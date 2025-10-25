#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <cmath>

/*
 * - Inspirado en GraphHopper Custom Models
 * - Usado por algoritmos de pathfinding (Dijkstra, A*, TSP)
 */
class VehicleProfile {
private:
    std::string name;
    std::string type;
    std::unordered_map<std::string, double> speedFactors;
    std::unordered_map<std::string, double> priorityFactors;

    //double distanceInfluence = 0.0;
    //double maxWidth = 0.0;
    //double maxHeight = 0.0;
    //double maxWeight = 0.0;
    //double maxLength = 0.0;

public:
    VehicleProfile(const std::string& name, const std::string& type);

    // Setters and Getters for factors (for speed and priority)
    void setSpeedFactor(const std::string& roadType, double factor);
    void setPriorityFactor(const std::string& roadType, double factor);

    double getSpeedFactor(const std::string& roadType) const;
    double getPriorityFactor(const std::string& roadType) const;

    // Calculate effective speed and suitability
    double getEffectiveSpeed(const std::string& highwayType) const;
    bool isRoadSuitable(const std::unordered_map<std::string, std::string>& tags) const;
    bool isHighwayBlocked(const std::string& highwayType) const;

    // Getters y Setters
    const std::string& getName() const { return name; }
    const std::string& getType() const { return type; }

    // Create default profiles (car, pedestrian)
    static VehicleProfile createCarProfile();
    static VehicleProfile createPedestrianProfile();

    // Get preferred tags and avoided tags
    std::vector<std::string> getPreferredTags() const;
    std::vector<std::string> getAvoidedTags() const;
    std::vector<std::string> getBlockedTags() const;
};
