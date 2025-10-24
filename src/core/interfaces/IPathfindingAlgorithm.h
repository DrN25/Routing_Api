#include <string>
#include <vector>

class Graph;
class VehicleProfile;

/*
 * - Polimorfismo: Clase base abstracta con métodos virtuales puros
 * - Bajo acoplamiento: Algoritmos concretos dependen solo de esta interfaz
*/

class IPathfindingAlgorithm {
public:
    virtual ~IPathfindingAlgorithm() = default;

    // Search for a path in the graph from startNodeId to endNodeId
    virtual std::vector<int64_t> findPath(
        const Graph& graph,
        int64_t startNodeId,
        int64_t endNodeId,
        const VehicleProfile& vehicle
    ) = 0;
    
    // Name of the algorithm (for logging/debugging)
    virtual std::string getName() const = 0;

    virtual size_t getExploredNodeCount() const = 0;
    virtual double getExecutionTime() const = 0;
};