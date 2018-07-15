//    Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//
//    '.' Matches any single character.
//    '*' Matches zero or more of the preceding element.
//    The matching should cover the entire input string (not partial).
//
//    Note:
//
//    s could be empty and contains only lowercase letters a-z.
//    p could be empty and contains only lowercase letters a-z, and characters like . or *.
//    Example 1:
//
//    Input:
//    s = "aa"
//    p = "a"
//    Output: false
//    Explanation: "a" does not match the entire string "aa".
//    Example 2:
//
//    Input:
//    s = "aa"
//    p = "a*"
//    Output: true
//    Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//    Example 3:
//
//    Input:
//    s = "ab"
//    p = ".*"
//    Output: true
//    Explanation: ".*" means "zero or more (*) of any character (.)".
//    Example 4:
//
//    Input:
//    s = "aab"
//    p = "c*a*b"
//    Output: true
//    Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
//    Example 5:
//
//    Input:
//    s = "mississippi"
//    p = "mis*is*p*."
//    Output: false

#include <string>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Dynamic Programming Approach
    bool
    isMatch(string s, string p)
    {
        // dp[i][j] = whether p[0 .. j-1] matches s[0 .. i-1]
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        // This for loop is for when "s" is empty, "p" can be "c*" (counts as empty)
        // Consider the case "s" is "aab" and "p" is "c*a*b"
        for ( int i = 0; i < p.size(); ++i )
        {
            if ( p[i] == '*' && dp[0][i - 1] )
            {
                dp[0][i + 1] = true;
            }
        }
        for ( int i = 0; i < s.size(); ++i )
        {
            for ( int j = 0; j < p.size(); ++j )
            {
                if ( p[j] == '.' || s[i] == p[j] )
                {
                    // i+1, j+1 because in the DP table, we have 1-indexed instead of 0-indexed, which is
                    // for string.
                    dp[i + 1][j + 1] = dp[i][j];
                }
                if ( p[j] == '*' )
                {
                    if ( p[j - 1] != s[i] && p[j - 1] != '.' )
                    {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    }
                    else
                    {
                        dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }


    // DFS solution
    bool
    isMatch2(string s, string p)
    {
        if ( p.empty())
        {
            return s.empty();
        }
        if ( p[1] == '*' ) // '*' requires that there must be a char before '*'
        {
            return (isMatch2(s, p.substr(2)) ||  // we treat "a*" as empty
                    (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch2(s.substr(1), p)));
        }
        else
        {
            return (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch2(s.substr(1), p.substr(1)));
        }
    }
};

using ptr2isMatch = bool (Solution::*)(string, string);


void
test(ptr2isMatch pfcn)
{
    Solution sol;
    string s = "aa";
    string p = "a";
    s = "aa";
    p = "a*";
    assert((sol.*pfcn)(s, p));
    s = "ab";
    p = ".*";
    assert((sol.*pfcn)(s, p));
    s = "aab";
    p = "c*a*b";
    assert((sol.*pfcn)(s, p));
    s = "mississippi";
    p = "mis*is*p*.";
    assert(!(sol.*pfcn)(s, p));
    s = "aaa";
    p = "aa";
    assert(!(sol.*pfcn)(s, p));
    s = "baaa";
    p = ".c";
    assert(!(sol.*pfcn)(s, p));
    s = "aaa";
    p = "ab*a*c*a";
    assert((sol.*pfcn)(s, p));
    s = "";
    p = ".*";
    assert((sol.*pfcn)(s, p));
}


int
main()
{
    ptr2isMatch pfcn = &Solution::isMatch;
    test(pfcn);
    pfcn = &Solution::isMatch2;
    test(pfcn);
}