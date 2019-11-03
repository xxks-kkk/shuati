#include <string>
#include "cpputility.h"

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string res = "";
    for(int i = 0; i < s.length(); ++i) {
      auto cand1 = longestPalindromeHelper(s, i, i);
      auto cand2 = longestPalindromeHelper(s, i, i+1);
      if (cand1.length() > cand2.length()) {
        if (res.length() < cand1.length()) res = cand1;
      } else {
        if (res.length() < cand2.length()) res = cand2;
      }
    }
    return res;
  }
private:
  string longestPalindromeHelper(string s, int left, int right) {
    string res = "";
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
      if (left == right) res += s[right];
      else {
        res = s[left] + res;
        res += s[right];
      }
      left--;
      right++;
    }
    return res;
  }
};

using ptr2longestPalindrome = string (Solution::*)(string);

struct testFuncsInfo {
  ptr2longestPalindrome pfcn;
  const char* pfcn_name;
};

void test(ptr2longestPalindrome pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    string s;
    string expected;
  };
  vector<testCase> test_cases = {
    {"babad", "bab"},
    {"cbbd", "bb"},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.s);
    if (got != test_case.expected) {
      printf("%s(%s) = %s\n",
             pfcn_name,
             test_case.s.c_str(),
             got.c_str());
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::longestPalindrome)
  };
  for(auto&& func: func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
