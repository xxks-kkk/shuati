#include "shared_headers.h"
#include "cpputility.h"

namespace Graph
{

/**
 * Given the edge list representation in string, the routine translates it into the same edge list representation
 * using the vector & pair.
 * @param edgeListStr the string format of edge list representation of a graph
 * @return same edge list representation but using vector & pair
 */
std::vector<std::pair<int, int>>
string2EdgeList(std::string edgeListStr);

/**
 * return a graph using the adjacency list representation
 * @param numberOfVertex the number of vertex in the graph
 * @param edgeListRepr the edge list representation of the graph
 * @param sourceFront the format of edge: true: [source, sink]; false: [sink, source]
 * @return the adjacency list representation of the graph
 */
std::vector<std::unordered_set<int>>
edgeList2AdjacencyList(int numberOfVertex, std::vector<std::pair<int, int>> edgeListRepr, bool sourceFront);

/**
 * compute the number of indegree for each vertex
 * @param numberOfVertex the number of vertex in the graph
 * @param adjacencyListRepr  the adjacency list representation of the graph
 * @return a vector of indegree for each vertex
 */
std::vector<int>
compute_indegree(int numberOfVertex, std::vector<std::unordered_set<int>> &adjacencyListRepr);
}