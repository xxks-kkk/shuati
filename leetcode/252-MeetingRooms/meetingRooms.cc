#include<vector>
#include "cpputility.h"

using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
      sort(intervals.begin(),
           intervals.end(),
           [](const vector<int>& v1, const vector<int>& v2) {
             return v1[0] < v2[0];
           });
      for(int i = 0; i < intervals.size()-1; ++i) {
        if (intervals[i][1] > intervals[i+1][0])
          return false;
      }
      return true;
    }
};

#define FUNC_DEF(func) { func, #func },

using ptr2canAttendMeetings = bool (Solution::*)(vector<vector<int>>&);

struct testFuncsInfo {
  ptr2canAttendMeetings pfcn;
  const char* pfcn_name;
};

void test(ptr2canAttendMeetings pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    vector<vector<int>> intervals;
    bool expected;
  };
  vector<testCase> test_cases = {
    {{{0,30},{5,10},{15,20}},false},
    {{{7,10},{2,4}}, true},
    {{{13,15},{1,13}}, true},
  };
  for(auto&& test_case: test_cases) {
    bool got = (sol.*pfcn)(test_case.intervals);
    if (got != test_case.expected) {
      printf("%s(%s) = %s\n",
             pfcn_name,
             CPPUtility::twoDVectorStr(test_case.intervals).c_str(),
             got == false ? "false" : "true");
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::canAttendMeetings)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
