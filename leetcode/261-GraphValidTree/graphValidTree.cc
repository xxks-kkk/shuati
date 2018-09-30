//    Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//
//    Example 1:
//
//    Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
//    Output: true
//    Example 2:
//
//    Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
//    Output: false
//    Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1]
//    is the same as [1,0] and thus will not appear together in edges.


#include <vector>
#include <cassert>
#include <stack>
#include <map>
#include <queue>

using namespace std;

class Solution
{
public:
    bool
    validTree(int n, vector<pair<int, int>> &edges)
    {
        if (n != edges.size() + 1)
        {
            // A connected graph G = (V,E) is a tree if and only if |E|=|V|-1
            // checking this also make sure that if there is no cycle in the graph, the graph is connected
            // counter example: 5 [[0,1],[0,4],[1,4],[2,3]]
            return false;
        }
        vector<int> id(n);
        for(int i = 0; i < n; ++i)
        {
            id[i] = i;
        }
        vector<int> size(n,1);
        for(auto&edge : edges)
        {
            auto first = edge.first;
            auto second = edge.second;
            // check cycle while building the union-find
            if(!unionId(first, second, id, size))
            {
                return false;
            }
        }
        return true;
    }
private:
    int findId(vector<int>&id, int node)
    {
        while (id[node] != node)
        {
            id[node] = id[id[node]];
            node = id[node];
        }
        return node;
    }

    bool unionId(int node1, int node2, vector<int>&id, vector<int>& size)
    {
        auto setX = findId(id, node1);
        auto setY = findId(id, node2);
        if (setX == setY)
        {
            return false;
        }
        if (size[setX] < size[setY])
        {
            size[setY] += size[setX];
            id[setX] = setY;
        }
        else
        {
            size[setX] += size[setY];
            id[setY] = setX;
        }
        return true;
    }
};

using ptr2validTree = bool (Solution::*)(int, vector<pair<int, int>> &);

void
test(ptr2validTree pfcn)
{
    Solution sol;
    int n = 5;
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4}
    };
    assert((sol.*pfcn)(n,edges) == true);

    n = 5;
    edges = {
        {0,1},
        {1,2},
        {2,3},
        {1,3},
        {1,4}
    };
    assert(!(sol.*pfcn)(n,edges));

    n = 5;
    edges = {
        {0,1},
        {0,4},
        {1,4},
        {2,3}
    };
    assert(!(sol.*pfcn)(n,edges));

    n = 4;
    edges = {
        {2,3},
        {1,2},
        {1,3}
    };

    n = 4;
    edges = {
        {0,1},
        {2,3},
        {1,2}
    };
    assert((sol.*pfcn)(n,edges));
}

int
main()
{
    ptr2validTree pfcn = &Solution::validTree;
    test(pfcn);
}