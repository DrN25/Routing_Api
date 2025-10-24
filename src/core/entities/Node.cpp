#include "Node.h"

Node::Node(
        int64_t id, 
        const Coordinate& coordinate, 
        const std::unordered_map<std::string, std::string>& tags
    )
        : id(id), coordinate(coordinate), tags(tags) {}

void Node::addTag(const std::string& key, const std::string& value) { tags[key] = value; }

std::string Node::getTag(const std::string& key) const { return tags.at(key); }

bool Node::hasTag(const std::string& key) const { return tags.find(key) != tags.end(); }

