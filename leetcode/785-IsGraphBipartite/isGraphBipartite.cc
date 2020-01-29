#include <vector>
#include "cpputility.h"

// Interviewed with Amazon Neptune team onsite (01/24/20)

using std::vector;

class Solution
{
public:
  bool isBipartite(vector<vector<int>> &graph)
  {
  }
};

using ptr2isBipartite = bool (Solution::*)(vector<vector<int>>);

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
