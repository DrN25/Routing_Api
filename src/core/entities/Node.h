#include <string>
#include <unordered_map>
#include "../value_objects/Coordinate.h"

class Node {
private:
    int64_t id;
    Coordinate coordinate;
    std::unordered_map<std::string, std::string> tags;

public:
    Node(int64_t id , const Coordinate& coordinate, const std::unordered_map<std::string, std::string>& tags);
    
    //Getters
    int64_t getId() const { return id; }
    Coordinate getCoordinate() const { return coordinate; }
    std::unordered_map<std::string, std::string> getTags() const { return tags; }

    //Tag management
    void addTag(const std::string& key, const std::string& value);
    std::string getTag(const std::string& key) const;
    bool hasTag(const std::string& key) const;

    // Comparation
    bool operator==(const Node& other) const { return id == other.id; }
    bool operator!=(const Node& other) const { return id != other.id; }
};