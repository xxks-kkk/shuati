#include <string>
#include <vector>
#include <stdio.h>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool canWin(string s) {
      for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '+' && s[i - 1] == '+' && !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
          return true;
        }
      }
      return false;
    }
};

using ptr2canWin = bool (Solution::*)(string);

class Test {
public:
  void test_pfcn(ptr2canWin pfcn) {
    Solution sol;
    struct testCase {
      string s;
      bool expected;
    };
    vector<testCase> test_cases = {
      {"++++", true},
      {"+++", true},
      {"+", false},      
      {"", false},
      {"++", true},
      {"+++++++++", false},
    };
    for(auto && test_case: test_cases) {
      bool got = (sol.*pfcn)(test_case.s);
      if (got != test_case.expected) {
        printf("canWin(%s) = %s\n", test_case.s.c_str(), got ? "true": "false");
        assert(false);
      }
    }
  }    
};

int main() {
  Test test;
  ptr2canWin pfcn = &Solution::canWin;
  test.test_pfcn(pfcn);
}

