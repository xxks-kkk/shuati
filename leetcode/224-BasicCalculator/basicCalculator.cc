//    Implement a basic calculator to evaluate a simple expression string.
//
//    The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
//
//    Example 1:
//
//    Input: "1 + 1"
//    Output: 2
//
//    Example 2:
//
//    Input: " 2-1 + 2 "
//    Output: 3
//
//    Example 3:
//
//    Input: "(1+(4+5+2)-3)+(6+8)"
//    Output: 23
//
//    Note:
//
//    You may assume that the given expression is always valid.
//    Do not use the eval built-in library function.
//
//  Company: Uber Phone Interview (12/17/2018)
//
//  Write something that given a string representation of a mathematical expression, computes the value of the expression.
//  Assume the expression will only contain addition (+) and multiplication (*) operator as well as integers. For example,
//  If the input is '3*4+1', the function output should be 13. You can assume the input is properly sanitized.

#include <string>
#include <assert.h>
#include <stack>

using namespace std;

class Solution {
public:
  int calculate(string s)
  {
    // keep track of signs right before each '('
    stack<int> st;
    // for all the signs those are not in the parentheses
    st.push(1);
    int ans = 0;
    // form the current operand
    int num = 0;
    // record the most recent right-before-'(' sign
    int last_sign = 1;
    for(auto& c: s)
    {
      if (c == '(')
      {
        st.push(last_sign); 
      }
      else if (c == ')')
      {
        st.pop();
      }
      if (c >= '0' && c <= '9')
      {
        num = num * 10 + c - '0';
      }
      if (c == '-' || c == '+')
      {
        // What operation to perform based on the current operator and
        // the sign immediately before the parentheses that the current operand is in
        ans += last_sign * num;
        num = 0;
        // update last_sign; needed as the next char can be '('
        last_sign = (c == '-'? -1 : 1) * st.top();
      }
    }
    // calculate the last number
    // For example, without this, in '1-(4+(5-6)+9)-10', '10' will be left out
    ans += last_sign * num;
    return ans;
  }
};

using ptr2calculate = int (Solution::*)(string);

void test(ptr2calculate pfcn)
{
  Solution sol;
  string s = "1+1";
  assert((sol.*pfcn)(s) == 2);
  s = "2-1+2";
  assert((sol.*pfcn)(s) == 3);
  s = "(1+(4+5+2)-3)+(6+8)";
  assert((sol.*pfcn)(s) == 23);
}

int main()
{
    ptr2calculate pfcn = &Solution::calculate;
    test(pfcn);
}
