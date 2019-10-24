#include <string>
#include "cpputility.h"
#include <queue>

using namespace std;

class Solution
{
public:
  // brute force
  int countSubstrings(string s)
  {
    int count = 0;
    for (int l = 1; l <= s.length(); ++l)
    {
      for (int i = 0; i <= s.length() - l; ++i)
      {
        string substr = s.substr(i, l);
        string copy(substr);
        reverse(substr.begin(), substr.end());
        if (copy == substr)
          count++;
      }
    }
    return count;
  }

  // recursion approach
  int countSubstrings1(string s) {
    int count = 0;
    for(int i = 0; i < s.length(); ++i) {
      countSubstrings1_helper(s, i, i, count);
      countSubstrings1_helper(s, i, i+1, count);
    }
    return count;
  }

  // DP
  int countSubstrings2(string s) {
    int n = s.length(), count = 0;
    deque<deque<bool>> dp(n, deque<bool>(n));
    for(int i = n-1; i >= 0; --i) {
      for(int j = i; j < n; ++j) {
        dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i+1][j-1]);
        if (dp[i][j]) ++count;
      }
    }
    return count;
  }  
private:
  void countSubstrings1_helper(const string& s, int left, int right, int&count) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left --;
      right++;
      count++;
    }
  }
};

using ptr2countSubstrings = int (Solution::*)(string);

struct testFuncsInfo {
  ptr2countSubstrings pfcn;
  const char* pfcn_name;
};

void test(ptr2countSubstrings pfcn, const char* pfcn_name)
{
  Solution sol;
  struct testCase {
    string s;
    int expected;
  };
  vector<testCase> test_cases = {
    {"abc", 3},
    {"aaa", 6},
  };
  for(auto&& test_case: test_cases) {
    auto got = (sol.*pfcn)(test_case.s);
    if (got != test_case.expected) {
      printf("%s(%s) = %d\n",
             pfcn_name,
             test_case.s.c_str(),
             got);
      assert(false);
    }
  }
}

int main()
{
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::countSubstrings)
    FUNC_DEF(&Solution::countSubstrings1)
    FUNC_DEF(&Solution::countSubstrings2)
  };
  for(auto&& func: func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
