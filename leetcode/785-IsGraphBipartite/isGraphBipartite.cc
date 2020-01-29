#include <vector>
#include "cpputility.h"
#include <stack>

// Interviewed with Amazon Neptune team onsite (01/24/20)
using std::vector;
using std::stack;

class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<int> color(n, -1);
    for(int i = 0; i < n; ++i) {
      if (color[i] == -1) {
        color[i] = 0;
        stack<int> stk;
        stk.push(i);
        while(!stk.empty()) {
          int node = stk.top(); stk.pop();
          for(auto &&neighbor: graph[node]) {
            if (color[neighbor] == -1) {
              color[neighbor] = color[node] ^ 1;
              stk.push(neighbor);
            } else if (color[neighbor] == color[node])
              return false;
          }
        }
      }
    }
    return true;
  }
};

using ptr2isBipartite = bool (Solution::*)(vector<vector<int>>&);

struct testFuncsInfo {
  ptr2isBipartite pfcn;
  const char* pfcn_name;
};

void test(ptr2isBipartite pfcn, const char* pfcn_name)
{
  Solution sol;
  struct testCase {
    vector<vector<int>> graph;
    bool expected;
  };
  vector<testCase> test_cases = {
    {{{1,3}, {0,2}, {1,3}, {0,2}}, true},
    {{{1,2,3}, {0,2}, {0,1,3}, {0,2}}, false},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.graph);
    if (got != test_case.expected) {
      printf("%s(%s) = %s\n",
             pfcn_name,
             CPPUtility::twoDVectorStr(test_case.graph).c_str(),
             got == true ? "true" : "false");
      assert(false);
    }
  }
}

int main()
{
  vector<testFuncsInfo> func_array = {
   FUNC_DEF(&Solution::isBipartite)
  };
  for(auto&& func: func_array) {
    test(func.pfcn, func.pfcn_name);
  } 
}
