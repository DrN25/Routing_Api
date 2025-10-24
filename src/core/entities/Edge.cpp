#include "Edge.h"

Edge::Edge(
    int64_t id,
    Node* source,
    Node* target,
    bool isOneWay,
    const Distance& distance,
    const std::unordered_map<std::string, std::string>& tags
)
    : id(id), source(source), target(target), isOneWay(isOneWay), distance(distance), tags(tags) {}

double Edge::getWeight(const VehicleProfile& vehicle) const { 
    // Placeholder implementation
    return 0.0;
}

void Edge::addTag(const std::string& key, const std::string& value) { tags[key] = value; }

std::string Edge::getTag(const std::string& key) const { return tags.at(key); }

bool Edge::hasTag(const std::string& key) const { return tags.find(key) != tags.end(); }