#include "graph.h"

namespace Graph
{
std::vector<std::pair<int, int>>
string2EdgeList(std::string edgeListStr)
{
    std::vector<std::pair<int, int>> result;
    std::stack<int> s;
    for (auto &c: edgeListStr)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        if (s.size() == 2)
        {
            int tmp1 = s.top();
            s.pop();
            int tmp2 = s.top();
            s.pop();
            result.push_back(std::make_pair(tmp2, tmp1));
        }
    }
    return result;
}

std::vector<std::unordered_set<int>>
edgeList2AdjacencyList(int numberOfVertex, std::vector<std::pair<int, int>> edgeListRepr)
{
    std::vector<std::unordered_set<int>> graph(numberOfVertex);
    for (auto &edge: edgeListRepr)
    {
        // the edge format: [sink, source]
        graph[edge.second].insert(edge.first);
    }
    return graph;
}

std::vector<int>
compute_indegree(int numberOfVertex, std::vector<std::unordered_set<int>> &adjacencyListRepr)
{
    std::vector<int> indegree(numberOfVertex, 0);
    for (auto &source : adjacencyListRepr)
    {
        for (auto &sink : source)
        {
            indegree[sink]++;
        }
    }
    return indegree;
}
}
