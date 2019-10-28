#include <vector>
#include "cpputility.h"
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> res;
      int counter = 0; 
      // first construct adjacency list representation of the graph
      unordered_map<int, vector<int>> graph;
      for(int i = 0; i < numCourses; ++i) {
        graph[i] = {};
      }
      for(auto&& preq: prerequisites) {
        graph[preq[1]].emplace_back(preq[0]);
      }
      // build indegree vector;
      vector<int> indegree(numCourses, 0);
      for(auto&& item: graph) {
        for(auto&& vertex: item.second) {
          indegree[vertex]++;
        }
      }
      // use topological sort to generate result
      queue<int> q;
      for(int i = 0; i < indegree.size(); ++i) {
        if (indegree[i] == 0) {
          q.push(i);
        }
      }
      while(!q.empty()){
        int vertex = q.front(); q.pop();
        res.emplace_back(vertex);
        counter++;
        for(auto&& node: graph[vertex]) {
          if(--indegree[node] == 0) q.push(node);          
        }
      }
      if (counter != numCourses) res.clear();
      return res;
    }
};

using ptr2findOrder = vector<int> (Solution::*)(int, vector<vector<int>>&);

void test(ptr2findOrder pfcn) {
  Solution sol;
  struct testCase {
    int numCourses;
    vector<vector<int>> prerequisites;
    vector<vector<int>> expected;
  };
  vector<testCase> test_cases = {
   {2, {{1,0}}, {{0,1}}},
   {4, {{1,0},{2,0},{3,1},{3,2}}, {{0,1,2,3},{0,2,1,3}}},
   {3, {{1,0},{1,2},{0,1}}, {{}}},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.numCourses, test_case.prerequisites);
    if (find(test_case.expected.begin(), test_case.expected.end(), got) == test_case.expected.end()) {
      printf("findOrder(%d, %s) = %s\n",
             test_case.numCourses,
             CPPUtility::twoDVectorStr<int>(test_case.prerequisites).c_str(),
             CPPUtility::oneDVectorStr<int>(got).c_str());
      assert(false);
    }
  }
}

int main() {
  ptr2findOrder pfcn = &Solution::findOrder;
  test(pfcn);
}
