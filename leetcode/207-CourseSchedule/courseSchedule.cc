//    There are a total of n courses you have to take, labeled from 0 to n-1.
//
//    Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//    Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
//    Example 1:
//
//    Input: 2, [[1,0]]
//    Output: true
//    Explanation: There are a total of 2 courses to take.
//    To take course 1 you should have finished course 0. So it is possible.
//    Example 2:
//
//    Input: 2, [[1,0],[0,1]]
//    Output: false
//    Explanation: There are a total of 2 courses to take.
//    To take course 1 you should have finished course 0, and to take course 0 you should
//    also have finished course 1. So it is impossible.
//    Note:
//
//    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
//    You may assume that there are no duplicate edges in the input prerequisites.

#include <vector>
#include <unordered_set>
#include <queue>
#include "graph.h"

using namespace std;

class Solution
{
public:
    bool
    canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        // We apply toplogical sorting using MAW (cpp) Figure 9.7
        auto graph = Graph::edgeList2AdjacencyList(numCourses, prerequisites);
        auto indegreeList = Graph::compute_indegree(numCourses, graph);
        queue<int> box;
        int count = 0;
        for (int i = 0; i < indegreeList.size(); ++i)
        {
            if (indegreeList[i] == 0)
            {
                box.push(i);
            }
        }
        while (!box.empty())
        {
            int vertex = box.front();
            box.pop();
            count++;
            for (auto &node : graph[vertex])
            {
                indegreeList[node]--;
                if (indegreeList[node] == 0)
                {
                    box.push(node);
                }
            }
        }
        if (count != numCourses)
        {
            // we have found cycle in the graph:
            // we should have visited every vertex when the queue is empty (count == numCourses)
            // However, if there is vertex we haven't visited, the only reason is that we haven't pushed it onto the
            // queue, which means its indegree is non-zero, which means we have cyclic in the graph:
            //
            //        x - x - x
            //            \  /
            //             x
            return false;
        }
        return true;
    }
};

using ptr2canFinish = bool (Solution::*)(int, vector<pair<int, int>> &);

void
test(ptr2canFinish pfcn)
{
    Solution sol;
    auto graph1 = Graph::string2EdgeList("[[1,0]]");
    assert((sol.*pfcn)(2, graph1));
    auto graph2 = Graph::string2EdgeList("[[1,0],[0,1]]");
    assert(!(sol.*pfcn)(2, graph2));
}

int
main()
{
    ptr2canFinish pfcn = &Solution::canFinish;
    test(pfcn);
}