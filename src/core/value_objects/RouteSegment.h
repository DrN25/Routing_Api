#include "../entities/Node.h"
#include "../entities/Edge.h"
#include "Distance.h"

class RouteSegment {
private:
    Node* source;
    Node* target;
    Edge* edge;
    double durationSeconds;

public:
    RouteSegment(Node* source, Node* target, Edge* edge, double durationSeconds)
        : source(source), target(target), edge(edge), durationSeconds(durationSeconds) {}

    // Getters
    Node* getSource() const { return source; }
    Node* getTarget() const { return target; }
    Edge* getEdge() const { return edge; }
    double getDurationSeconds() const { return durationSeconds; }

};