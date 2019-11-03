#include <vector>
#include "cpputility.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      auto comp = [] (const vector<int>& interval1, const vector<int>& interval2) {
                    return interval1[0] < interval2[0];
                  };
      sort(intervals.begin(), intervals.end(), comp);
      vector<vector<int>> res;
      for(auto&& interval: intervals) {
        if (res.empty()) res.emplace_back(interval);
        else {
          auto prev_interval = res[res.size()-1];
          if (interval[0] > prev_interval[1]) res.emplace_back(interval);
          else if (interval[1] > prev_interval[1]) res[res.size()-1][1] = interval[1];
        }
      }
      return res;
    }
};

using ptr2merge = vector<vector<int>> (Solution::*)(vector<vector<int>>&);

void test(ptr2merge pfcn) {
  Solution sol;
  struct testCase {
    vector<vector<int>> intervals;
    vector<vector<int>> expected;
  };
  vector<testCase> test_cases = {
    {{{1,3},{2,6},{8,10},{15,18}}, {{1,6},{8,10},{15,18}}},
    {{{1,4},{4,5}}, {{1,5}}},
    {{{1,4},{2,3}}, {{1,4}}},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.intervals);
    if (got != test_case.expected) {
      printf("merge(%s) = %s\n",
             CPPUtility::twoDVectorStr<int>(test_case.intervals).c_str(),
             CPPUtility::twoDVectorStr<int>(got).c_str()
        );
    }
  }
}

int main() {
  ptr2merge pfcn = &Solution::merge;
  test(pfcn);
}
