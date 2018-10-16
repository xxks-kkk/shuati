//    Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
//
//    The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.
//
//    Example:
//    Input: [[1,2], [3], [3], []]
//    Output: [[0,1,3],[0,2,3]]
//    Explanation: The graph looks like this:
//    0--->1
//    |    |
//    v    v
//    2--->3
//    There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
//    Note:
//
//    The number of nodes in the graph will be in the range [2, 15].
//    You can print different paths in any order, but you should keep the order of nodes inside one path.

#include <vector>
#include <unordered_set>
#include <cassert>
#include <queue>

using namespace std;

class Solution
{
public:
    // DFS
    vector<vector<int>>
    allPathsSourceTarget(vector<vector<int>> graph)
    {
        vector<vector<int>> res;
        unordered_set<int> visited;
        allPathsSourceTargetHelper(graph, res, visited, vector<int>() = {0}, 0);
        return res;
    }

    // BFS
    vector<vector<int>>
    allPathsSourceTarget2(vector<vector<int>> graph)
    {
        queue<pair<int, vector<int>>> q;
        q.push(pair<int, vector<int>>{0,{}});
        vector<vector<int>> res;
        while (!q.empty())
        {
            queue<pair<int, vector<int>>> next_q;
            while (!q.empty())
            {
                auto node = q.front().first;
                auto path = q.front().second;
                q.pop();
                if (node == graph.size() - 1)
                {
                    path.push_back(node);
                    res.push_back(path);
                    continue;
                }
                for(auto& item : graph[node])
                {
                    path.push_back(node);
                    next_q.push(pair<int, vector<int>>{item, path});
                    path.pop_back();
                }
            }
            // for the example, first time hit here,
            // next_q = (1,[0]), (2,[0])
            // second time hit here
            // next_q = (3,[0,1]), (3, [0,2])
            q = next_q;
        }
        return res;
    }
private:
    void
    allPathsSourceTargetHelper(vector<vector<int>> &graph,
                               vector<vector<int>> &res,
                               unordered_set<int> &visited,
                               vector<int> &path,
                               int node)
    {
        if (node == graph.size() - 1)
        {
            res.push_back(path);
            return;
        }
        for (auto &item: graph[node])
        {
            if (visited.find(item) == visited.end())
            {
                visited.insert(item);
                path.push_back(item);
                allPathsSourceTargetHelper(graph, res, visited, path, item);
                path.pop_back();
                visited.erase(item);
            }
        }
    }
};

using ptr2allPathsSourceTarget = vector<vector<int>> (Solution::*)(vector<vector<int>>);

void
test(ptr2allPathsSourceTarget pfcn)
{
    Solution sol;
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };
    vector<vector<int>> ans = {
        {0, 1, 3},
        {0, 2, 3}
    };
    assert((sol.*pfcn)(graph) == ans);
}

int
main()
{
    ptr2allPathsSourceTarget pfcn = &Solution::allPathsSourceTarget;
    test(pfcn);

    pfcn = &Solution::allPathsSourceTarget2;
    test(pfcn);
}