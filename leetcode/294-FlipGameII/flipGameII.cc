#include <string>
#include <vector>
#include <stdio.h>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool canWin(string s) {
        int depth = 0;
        return backtrack(depth, s);
    }
private:
  bool backtrack(int depth, string s) {
    int s_size = s.length();
    if (s_size == 0 || s_size == 1) {
      return false;
    }
    vector<string> states = generateStates(s);
    if (depth % 2 == 1 && states.empty()) {
      return true;
    } else if (depth % 2 == 0 && states.empty()) {
      return false;
    }
    for (auto&& state: states) {
      auto res = backtrack(depth+1, state);
      if (res) {
        return true;
      }
    }
    return false;
  }

  // This generate all possible states by replacing "++" into "--"
  // if possible
  vector<string> generateStates(string s) {
    vector<string> res;
    if (s.length() == 0) {
      return res;
    }
    for(int i = 0; i < (signed) s.length()-1; ++i) {
      if (s[i] == '+' && s[i+1] == '+') {
        string tmp = s;
        tmp.replace(i, 2, "--");
        res.push_back(tmp);
      }
    }
    return res;
  }

  friend class Test;
};

using ptr2canWin = bool (Solution::*)(string);

class Test {
public:
  void test_generateStates() {
    Solution sol;
    struct testCase {
      string s;
      vector<string> expected;
    };
    vector<testCase> test_cases = {
      { "", {}},
      {"++++", {"--++", "++--", "+--+"}},
    };
    for(auto && test_case: test_cases) {
      vector<string> got = (sol.generateStates)(test_case.s);
      for(auto&& item: got) {
        if (find(test_case.expected.begin(), test_case.expected.end(), item) == test_case.expected.end())
        {
          string got_str = "[";
          for(auto && item: got) {
            got_str += item;
            got_str += ", ";
          }
          got_str += "]";          
          printf("generateStates(%s) = %s", test_case.s.c_str(), got_str.c_str());
        }
      }
    }
  }

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
  test.test_generateStates();
  ptr2canWin pfcn = &Solution::canWin;
  test.test_pfcn(pfcn);
}

