//    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
//
//    '?' Matches any single character.
//    '*' Matches any sequence of characters (including the empty sequence).
//
//    The matching should cover the entire input string (not partial).
//
//    Note:
//
//    s could be empty and contains only lowercase letters a-z.
//    p could be empty and contains only lowercase letters a-z, and characters like ? or *.
//
//    Example 1:
//
//    Input:
//    s = "aa"
//    p = "a"
//    Output: false
//    Explanation: "a" does not match the entire string "aa".
//
//    Example 2:
//
//    Input:
//    s = "aa"
//    p = "*"
//    Output: true
//    Explanation: '*' matches any sequence.
//
//    Example 3:
//
//    Input:
//    s = "cb"
//    p = "?a"
//    Output: false
//    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//
//    Example 4:
//
//    Input:
//    s = "adceb"
//    p = "*a*b"
//    Output: true
//    Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//
//    Example 5:
//
//    Input:
//    s = "acdcb"
//    p = "a*c?b"
//    Output: false
//

#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if ((s.empty() && p.empty())) return true;
        if ((s[0] != p[0] && p[0] != '*' && p[0] != '?') || (s.empty() && p[0] == '?')) return false;
        else if (s[0] == p[0] || (s.size() >= 1 && p[0] == '?')) {
                return isMatch(s.substr(1), p.substr(1));
        }
        else {
            assert(p[0] == '*');
            for(int i = 0; i <= s.size(); ++i) {
                if (isMatch(s.substr(0), s.substr(0,i) + p.substr(1))) {
                    return true;
                }
            }
            return false;
        }
    }
};

using ptr2isMatch = bool (Solution::*)(string, string);

void test(ptr2isMatch pfcn) {
    Solution sol;
    string s;
    string p;
    s = "ho";
    p = "ho**";
    assert((sol.*pfcn)(s,p) == true);
    s = "aa";
    p = "a";
    assert((sol.*pfcn)(s,p) == false);
    s = "aa";
    p = "*";
    assert((sol.*pfcn)(s,p) == true);
    s = "cb";
    p = "?a";
    assert((sol.*pfcn)(s,p) == false);
    s = "adceb";
    p = "*a*b";
    assert((sol.*pfcn)(s,p) == true);
    s = "acdcb";
    p = "a*c?b";
    assert((sol.*pfcn)(s,p) == false);
    s = "";
    p = "*";
    assert((sol.*pfcn)(s,p) == true);
    s = "mississippi";
    p = "m??*ss*?i*pi";
    assert((sol.*pfcn)(s,p) == false);
    s = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
    p = "***bba**a*bbba**aab**b";
    assert((sol.*pfcn)(s,p) == false);
}

int main()
{
    ptr2isMatch pfcn = &Solution::isMatch;
    test(pfcn);
}