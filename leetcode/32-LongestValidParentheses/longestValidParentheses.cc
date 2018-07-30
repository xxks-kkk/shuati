//    Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//    Example 1:
//
//    Input: "(()"
//    Output: 2
//    Explanation: The longest valid parentheses substring is "()"
//    Example 2:
//
//    Input: ")()())"
//    Output: 4
//    Explanation: The longest valid parentheses substring is "()()"

#include <string>
#include <stack>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Approach 1: using stack
    int
    longestValidParentheses( string s )
    {
        stack<int> st;
        st.push( -1 );
        int max_len = 0;
        for ( int i = 0; i < s.length(); ++i )
        {
            if ( s[i] == '(' )
            {
                st.push( i );
            }
            else
            {
                st.pop();
                if ( st.empty())
                {
                    st.push( i );
                }
                else
                {
                    max_len = max( max_len, i - st.top());
                }
            }
        }
        return max_len;
    }


    // Approach 2: without extra space
    int
    longestValidParentheses2( string s )
    {
        // count # of left parentheses
        int left = 0;
        // count # of right parentheses
        int right = 0;
        int max_len = 0;
        for ( int i = 0; i < s.length(); ++i )
        {
            if ( s[i] == '(' )
            {
                left++;
            }
            else
            {
                right++;
            }
            if ( left == right )
            {
                max_len = max( max_len, right * 2 );
            }
            if ( right > left )
            {
                left = right = 0;
            }
        }
        left = 0;
        right = 0;
        for ( int i = s.length() - 1; i >= 0; --i )
        {
            if ( s[i] == '(' )
            {
                left++;
            }
            else
            {
                right++;
            }
            if ( left == right )
            {
                max_len = max( max_len, left * 2 );
            }
            if ( left > right )
            {
                left = right = 0;
            }
        }
        return max_len;
    }


    // Approach 3: DP
    int
    longestValidParentheses3( string s )
    {
        int max_len = 0;
        vector<int> dp ((int)s.length(), 0);
        for (int i = 1; i < s.length(); ++i)
        {
            if(s[i] == ')')
            {
                if (s[i-1] == '(')
                {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                }
                else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(')
                {
                    dp[i] = dp[i-1] + ((i - dp[i-1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                max_len = max(max_len, dp[i]);
            }
        }
        return max_len;
    }
};

using ptr2ongestValidParentheses = int ( Solution::* )( string );


void
test( ptr2ongestValidParentheses pfcn )
{
    Solution sol;
    string s = "(()";
    assert((sol.*pfcn)( s ) == 2 );
    s = ")()())";
    assert((sol.*pfcn)( s ) == 4 );
    s = "(()())";
    assert((sol.*pfcn)( s ) == 6 );
    s = "())((())";
    assert((sol.*pfcn)( s ) == 4 );
}


int
main()
{
    ptr2ongestValidParentheses pfcn = &Solution::longestValidParentheses;
    test( pfcn );
    pfcn = &Solution::longestValidParentheses2;
    test( pfcn );
    pfcn = &Solution::longestValidParentheses3;
    test( pfcn );
}