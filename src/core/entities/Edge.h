#include <string>
#include <unordered_map>
#include "Node.h"
#include "../value_objects/Distance.h"

// Forward declaration
class VehicleProfile;

class Edge {
private:
    int64_t id;
    Node* source;
    Node* target;
    Distance distance;
    bool isOneWay;
    std::unordered_map<std::string, std::string> tags;

public:
    Edge(int64_t id, Node* source, Node* target, const Distance& distance, bool isOneWay,
         const std::unordered_map<std::string, std::string>& tags);

    // Calculate weight based on vehicle profile
    double getWeight(const VehicleProfile& vehicle) const;

    // Getters
    int64_t getId() const { return id; }
    Node* getSource() const { return source; }
    Node* getTarget() const { return target; }
    const Distance& getDistance() const { return distance; }
    bool getIsOneWay() const { return isOneWay; }
    const std::unordered_map<std::string, std::string>& getTags() const { return tags; }

    //Tag management
    void addTag(const std::string& key, const std::string& value);
    std::string getTag(const std::string& key) const;
    bool hasTag(const std::string& key) const;

    // Comparation
    bool operator==(const Edge& other) const { return id == other.getId(); }
    bool operator!=(const Edge& other) const { return id != other.getId(); }
};