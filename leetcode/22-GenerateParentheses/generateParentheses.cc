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
    string currentState;
    backtrack(res, currentState, 0, n);
    return res;
  }
private:
  // isValid checks whether it is valid to apply "(" or ")" (noted as
  // `action`) to the `currentState` given the number of pairs of parentheses `n`
  bool isValid(string currentState, string action, int n)
  {
    currentState += action;
    int num_left_parentheses = 0;
    int num_right_parentheses = 0;
    stack<char> stk;
    for (auto&& c: currentState)
    {
      switch(c)
      {
      case '(':
        stk.push(')');
        num_left_parentheses += 1;
        if (num_left_parentheses > n) return false;
        break;
      case ')':
        stk.pop();
        num_right_parentheses += 1;
        if (num_right_parentheses > n) return false;
        break;
      }
    }
    if (num_right_parentheses > num_left_parentheses)
    {
      return false;
    }
    return true;
  }

  // generatePairs will take in `currentState` and generate valid pairs of parentheses
  string generatePairs(string currentState)
  {
    // Implementation idea is inspired by 20-ValidParentheses
    stack<char> stk;
    for (auto&& c : currentState)
    {
      switch(c)
      {
      case '(': stk.push(')'); break;
      default:
        stk.pop();
      }
    }
    while (!stk.empty())
    {
      currentState += stk.top();
      stk.pop();
    }
    return currentState;
  }

  void backtrack(vector<string>& res, string currentState, int num_used_left_parentheses, int n)
  {
    if (num_used_left_parentheses == n) {
      res.push_back(generatePairs(currentState));
    }
    else
    {
      string nextState;
      if (isValid(currentState, ")", n))
      {
          nextState = currentState + ")";
          backtrack(res, nextState, num_used_left_parentheses, n);
      }
      if (isValid(currentState, "(", n))
      {
          nextState = currentState + "(";
          backtrack(res, nextState, num_used_left_parentheses + 1, n);
      }
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
