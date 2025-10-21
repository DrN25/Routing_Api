#include <vector>
#include "Graph.h"

Graph::Graph() : minLatitude(0), maxLatitude(0), minLongitude(0), maxLongitude(0), boundsSet(false) {}

void Graph::addNode(Node* node) {
    nodes[node->getId()] = std::unique_ptr<Node>(node);
}

void Graph::addEdge(Edge* edge) {
    edges[edge->getId()] = std::unique_ptr<Edge>(edge);
}

void Graph::buildAdjacencyList() {
    adjacencyList.clear();
    for (const auto& [id, edgePtr] : edges) {
        Edge* edge = edgePtr.get();
        adjacencyList[edge->getSource()->getId()].push_back(edge);
        if (!edge->getIsOneWay()) {
            adjacencyList[edge->getTarget()->getId()].push_back(edge);
        }
    }
}

bool Graph::hasNode(int64_t id) const {
    return nodes.count(id) > 0;
}

size_t Graph::getNodeCount() const {
    return nodes.size();
}

bool Graph::hasEdge(int64_t id) const {
    return edges.count(id) > 0;
}

size_t Graph::getEdgeCount() const {
    return edges.size();
}