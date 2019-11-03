#include <string>
#include "cpputility.h"

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    // invariant: s[start, end] (inclusive) is the longest palindrome    
    int start = 0, end = 0; 
    for(int i = 0; i < s.length(); ++i) {      
      auto len1 = longestPalindromeHelper(s, i, i);
      auto len2 = longestPalindromeHelper(s, i, i+1);
      auto len = max(len1, len2);
      if (len > end - start + 1) {
        start = i - (len-1) / 2;
        end = i + len / 2;
      }
    }
    return s.substr(start, end-start+1);
  }
private:
  int longestPalindromeHelper(const string& s, int left, int right) {
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }
    return right-left-1;
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
