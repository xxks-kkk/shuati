/*************************************************************************
  > File Name:       decodeString.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/31/18
  > Description:
    
    Given an encoded string, return it's decoded string.

    The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being
    repeated exactly k times. Note that k is guaranteed to be a positive integer.

    You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

    Furthermore, you may assume that the original data does not contain any digits and that digits are only for those
    repeat numbers, k. For example, there won't be input like 3a or 2[4].

    Examples:

    s = "3[a]2[bc]", return "aaabcbc".
    s = "3[a2[c]]", return "accaccacc".
    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 ************************************************************************/

#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
    // Recursive solution
    string
    decodeString(string s)
    {
        int pos = 0;
        return decodeStringHelper(pos, s);
    }
private:
    string
    decodeStringHelper(int &pos, string s)
    {
        int num = 0;
        string res = "";
        for (; pos < s.length(); ++pos)
        {
            char curr = s[pos];
            if (curr == '[')
            {
                string tmp = decodeStringHelper(++pos, s);
                for (; num > 0; num--)
                {
                    res += tmp;
                }
            }
            else if (curr == ']')
            {
                return res;
            }
            else if ('0' <= curr && curr <= '9')
            {
                num = num * 10 + curr - '0';
            }
            else
            {
                // Normal characters
                res += curr;
            }
        }
        return res;
    }
};

using ptr2decodeString = string (Solution::*)(string);

void
test(ptr2decodeString pfcn)
{
    Solution sol;
    string s = "3[a]2[bc]";
    assert((sol.*pfcn)(s) == "aaabcbc");
    s = "3[a2[c]]";
    assert((sol.*pfcn)(s) == "accaccacc");
    s = "2[abc]3[cd]ef";
    assert((sol.*pfcn)(s) == "abcabccdcdcdef");
}

int
main()
{
    ptr2decodeString pfcn = &Solution::decodeString;
    test(pfcn);
}