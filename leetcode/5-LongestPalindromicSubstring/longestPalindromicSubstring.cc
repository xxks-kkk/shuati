#include <string>
#include "cpputility.h"

using namespace std;

class Solution {
public:
  // Recursion
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

  // DP
  string longestPalindrome2(string s) {
    int palindromeBeginsAt = 0;
    int maxLength = 0;
    int n = static_cast<int>(s.length());
    // DP[i][j] = 1 means a palindrome starts at i and ends at j (inclusive)
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = n-1; i >= 0; --i) {
      for(int j = i; j < n; ++j) {
        dp[i][j] = (s[i] == s[j]) && (j-i <= 2 || dp[i+1][j-1]);
        if (dp[i][j] && j-i+1 > maxLength) {
          palindromeBeginsAt = i;
          maxLength = j-i+1;
        }
      }
    }
    return s.substr(palindromeBeginsAt, maxLength);
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
    vector<string> expected;
  };
  vector<testCase> test_cases = {
    {"babad", {"aba","bab"}},
    {"cbbd", {"bb"}},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.s);
    if (find(test_case.expected.begin(), test_case.expected.end(), got) == test_case.expected.end()) {
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
    FUNC_DEF(&Solution::longestPalindrome2)
  };
  for(auto&& func: func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
