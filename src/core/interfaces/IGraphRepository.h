#include <string>
#include <memory>
#include "../entities/Graph.h"

/*
 * - Patrón Estructural (Adapter): Abstrae la fuente de datos (binario, JSON, DB)
 * - Bajo acoplamiento: Servicios no conocen implementación concreta
*/

class IGraphRepository {
public:
    virtual ~IGraphRepository() = default;

    // Load graph from data source
    virtual std::unique_ptr<Graph> load(const std::string& source) = 0;

    // Save graph to data source
    virtual void save(const Graph& graph, const std::string& destination) = 0;

    virtual bool exists(const std::string& source) const = 0;

};