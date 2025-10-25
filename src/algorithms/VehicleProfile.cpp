#include "VehicleProfile.h"
#include <algorithm>

VehicleProfile::VehicleProfile(const std::string& name, const std::string& type)
    : name(name), type(type) {}

void VehicleProfile::setSpeedFactor(const std::string& roadType, double factor) {
    speedFactors[roadType] = factor;
}

void VehicleProfile::setPriorityFactor(const std::string& roadType, double factor) {
    priorityFactors[roadType] = factor;
}

double VehicleProfile::getSpeedFactor(const std::string& roadType) const {
    auto it = speedFactors.find(roadType);
    return (it != speedFactors.end()) ? it->second : 0.5;
}

double VehicleProfile::getPriorityFactor(const std::string& roadType) const {
    auto it = priorityFactors.find(roadType);
    return (it != priorityFactors.end()) ? it->second : 1.0;
}

double VehicleProfile::getEffectiveSpeed(const std::string& highwayType) const {
    double baseSpeed = 50.0;
    if (type == "CAR") baseSpeed = 80.0;
    else if (type == "PEDESTRIAN") baseSpeed = 5.0;
    //else if (type == "BICYCLE") baseSpeed = 15.0;
    //else if (type == "TRUCK") baseSpeed = 60.0;

    return baseSpeed * getSpeedFactor(highwayType);
}

bool VehicleProfile::isHighwayBlocked(const std::string& highwayType) const {
    double factor = getSpeedFactor(highwayType);
    return factor <= 0.0;
}

bool VehicleProfile::isRoadSuitable(const std::unordered_map<std::string, std::string>& tags) const {
    auto it = tags.find("highway");
    if (it == tags.end()) return true; // no info = permitido

    const std::string& highway = it->second;
    return !isHighwayBlocked(highway);
}

std::vector<std::string> VehicleProfile::getPreferredTags() const {
    std::vector<std::string> result;
    for (const auto& [tag, factor] : priorityFactors)
        if (factor > 1.0) result.push_back(tag);
    return result;
}

std::vector<std::string> VehicleProfile::getAvoidedTags() const {
    std::vector<std::string> result;
    for (const auto& [tag, factor] : priorityFactors)
        if (factor < 1.0) result.push_back(tag);
    return result;
}

std::vector<std::string> VehicleProfile::getBlockedTags() const {
    std::vector<std::string> blocked;
    for (const auto& [tag, factor] : speedFactors)
        if (factor <= 0.0) blocked.push_back(tag);
    return blocked;
}


VehicleProfile VehicleProfile::createCarProfile() {
    VehicleProfile car("Automovil", "CAR");
    // Those that had 0.0 are considered blocked
    car.setSpeedFactor("residential", 1.0);
    car.setSpeedFactor("primary", 1.3);
    car.setSpeedFactor("secondary", 1.2);
    car.setSpeedFactor("tertiary", 1.1);
    car.setSpeedFactor("trunk", 1.4);
    car.setSpeedFactor("motorway", 1.5);
    car.setSpeedFactor("unclassified", 0.9);
    car.setSpeedFactor("tertiary_link", 1.1);
    car.setSpeedFactor("primary_link", 1.3);
    car.setSpeedFactor("secondary_link", 1.2);
    car.setSpeedFactor("trunk_link", 1.4);
    car.setSpeedFactor("corridor", 0.8);
    car.setSpeedFactor("track", 0.3);
    car.setSpeedFactor("footway", 0.0);
    car.setSpeedFactor("pedestrian", 0.0);
    car.setSpeedFactor("cycleway", 0.0);
    car.setSpeedFactor("path", 0.0);
    car.setSpeedFactor("service", 0.0);
    car.setSpeedFactor("steps", 0.0);

    car.setPriorityFactor("primary", 1.5);
    car.setPriorityFactor("secondary", 1.3);
    car.setPriorityFactor("tertiary", 1.2);
    car.setPriorityFactor("trunk", 1.6);
    car.setPriorityFactor("motorway", 1.8);
    car.setPriorityFactor("track", 0.2);
    /*
    car.setDistanceInfluence(0.1);
    car.setMaxWidth(2.5);
    car.setMaxHeight(4.0);
    car.setMaxWeight(3.5);
    car.setMaxLength(12.0);
    */
    return car;
}

VehicleProfile VehicleProfile::createPedestrianProfile() {
    VehicleProfile p("Peaton", "PEDESTRIAN");
    // Those that had 0.0 are considered blocked
    p.setSpeedFactor("footway", 1.5);
    p.setSpeedFactor("pedestrian", 1.4);
    p.setSpeedFactor("cycleway", 1.2);
    p.setSpeedFactor("path", 1.6);
    p.setSpeedFactor("service", 1.1);
    p.setSpeedFactor("residential", 1.0);
    p.setSpeedFactor("primary", 0.4);
    p.setSpeedFactor("secondary", 0.5);
    p.setSpeedFactor("tertiary", 0.7);
    p.setSpeedFactor("unclassified", 0.6);
    p.setSpeedFactor("trunk", 0.0);
    p.setSpeedFactor("motorway", 0.0);

    p.setPriorityFactor("footway", 1.8);
    p.setPriorityFactor("pedestrian", 1.7);
    p.setPriorityFactor("cycleway", 1.4);
    p.setPriorityFactor("path", 1.9);
    p.setPriorityFactor("primary", 0.3);
    p.setPriorityFactor("secondary", 0.4);
    /*
    p.setDistanceInfluence(0.2);
    p.setMaxWidth(1.0);
    p.setMaxHeight(2.5);
    p.setMaxWeight(0.1);
    */
    return p;
}
