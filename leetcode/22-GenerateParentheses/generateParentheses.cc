//  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <vector>
#include <string>
#include <stack>
#include <assert.h>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> res;
    string cand;
    backtrack(res, 0, 0, cand, n);
    return res;
  }
private:
  // backtrack constructs all the valid pairs of parenthesis. The key idea is to keep track of the number of left parenthesis
  // (`left_parenthesis_used`) and the number of right parenthesis we have used. The valid pairs of parentheses can only
  // happen when 1. left_parenthesis_used < n or 2. left_parenthesis_used > right_parenthesis_used (otherwise, creates string like
  // '())')
  void backtrack(vector<string>& res, int left_parenthesis_used, int right_parenthesis_used, string cand, int n)
  {
    if (cand.length() == 2*n)
    {
      res.push_back(cand);
      return;
    }
    if (left_parenthesis_used < n)
    {
      backtrack(res, left_parenthesis_used + 1, right_parenthesis_used, cand + '(', n);
    }
    if (left_parenthesis_used > right_parenthesis_used)
    {
      backtrack(res, left_parenthesis_used, right_parenthesis_used + 1, cand + ')', n);
    }
  }
};

using ptr2generateParenthesis = vector<string> ( Solution::* )( int );

void
test( ptr2generateParenthesis pfcn )
{
    Solution sol;
    auto got = (sol.*pfcn)(3);
    vector<string> expected = {
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
    };
    for (auto && element : got)
    {
      if (find(expected.begin(), expected.end(), element) == expected.end())
      {
        assert(false);
      }
    }
    assert(true);
}


int
main()
{
    ptr2generateParenthesis pfcn = &Solution::generateParenthesis;
    test( pfcn );
}
