#include<string>
#include<unordered_map>
#include<vector>
#include<limits>

using namespace std;

#define FUNC_DEF(func) { func, #func },

class Solution {
public:
  string minWindow(string s, string t) {
    string res;
    int lower_bound, upper_bound;
    unordered_map<char, int> char_count;
    int diff = numeric_limits<int>::max();
    for(auto&& ch : t) {
        char_count[ch]++;
    }
    int left_ptr = 0, count = 0;
    for(int right_ptr = 0; right_ptr < s.length(); ++right_ptr) {
      if (--char_count[s[right_ptr]] >= 0) count++;
      while(count == t.length()) {
          int interval_diff = right_ptr - left_ptr + 1;
          if (interval_diff < diff) {
              lower_bound = left_ptr;
              upper_bound = right_ptr;
              diff = interval_diff;
          }
          if (++char_count[s[left_ptr]] > 0) count--;
          left_ptr++;
      }
    }
    for(int i = lower_bound; i <= upper_bound; ++i) {
        res += s[i];
    }
    return res;
  }
};

using ptr2minWindow = string (Solution::*)(string, string);

struct testFuncsInfo {
  ptr2minWindow pfcn;
  const char* pfcn_name;
};

void test(ptr2minWindow pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    string s;
    string t;
    string expected;
  };
  vector<testCase> test_cases = {
    {"ADOBECODEBANC", "ABC", "BANC"},
    {"a", "a", "a"},
    {"cabwefgewcwaefgcf", "cae", "cwae"},
  };
  for(auto&& test_case: test_cases) {
    string got = (sol.*pfcn)(test_case.s, test_case.t);
    if (got != test_case.expected) {
      printf("%s(%s, %s) = %s\n", pfcn_name,
             test_case.s.c_str(),
             test_case.t.c_str(),
             got.c_str());
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::minWindow)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
