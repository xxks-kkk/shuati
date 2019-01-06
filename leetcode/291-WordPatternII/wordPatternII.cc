// Given a pattern and a string str, find if str follows the same pattern.

//     Here follow means a full match, such that there is a bijection between a
//     letter in pattern and a non-empty substring in str.

//     Example 1:

//     Input: pattern = "abab", str = "redblueredblue"
//     Output: true

//     Example 2:

//     Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
//     Output: true

//     Example 3:

//     Input: pattern = "aabb", str = "xyzabcxzyabc"
//     Output: false

//     Notes:
//     You may assume both pattern and str contains only lowercase letters.

#include <assert.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool wordPatternMatch(string pattern, string str)
  {
    // <pattern ('a'), corresponding string segment ('red')>
    unordered_map<char, string> p_table;
    // keep track of unique string segment
    unordered_set<string> s_table;
    return isMatch(str, 0, pattern, 0, p_table, s_table);
  }

private:
  // i: track index of str
  // j: track index of pattern
  bool isMatch(string str, int i, string pattern, int j, unordered_map<char, string> &p_table, unordered_set<string> &s_table)
  {
    if (i == str.length() && j == pattern.length())
    {
      return true;
    }
    if (i == str.length() || j == pattern.length())
    {
      return false;
    }
    // get current pattern character
    char c = pattern[j];

    // if the pattern character exists
    if (p_table.find(c) != p_table.end())
    {
      string s = p_table[c];

      // then check if we can use it to match str[i:i+s.length()]
      if (str.substr(i, s.length()) != s)
      {
        return false;
      }

      // if it can match, great, continue to match the rest
      return isMatch(str, i + s.length(), pattern, j + 1, p_table, s_table);
    }

    // pattern character does not exist in the map
    for (int k = i; k < str.length(); ++k)
    {
      string p = str.substr(i, k - i + 1);

      // suppose 'a' in pattern matches with 'red' in str,
      // then 'b' in pattern cannot match with 'red' in str again.
      if (s_table.find(p) != s_table.end())
      {
        continue;
      }

      // create or update it
      p_table[c] = p;
      s_table.insert(p);

      // continue to match the rest
      if (isMatch(str, k + 1, pattern, j + 1, p_table, s_table))
      {
        return true;
      }

      // backtracking
      p_table.erase(c);
      s_table.erase(p);
    }

    // we have tried our best but still no luck
    return false;
  }
};

using ptr2wordPatternMatch = bool (Solution::*)(string, string);

void test(ptr2wordPatternMatch pfcn)
{
  Solution sol;
  string pattern = "abab";
  string str = "redblueredblue";
  assert((sol.*pfcn)(pattern, str));

  pattern = "aaaa";
  str = "asdasdasdasd";
  assert((sol.*pfcn)(pattern, str));

  pattern = "aabb";
  str = "xyzabcxzyabc";
  assert(!(sol.*pfcn)(pattern, str));
}

int main()
{
  ptr2wordPatternMatch pfcn = &Solution::wordPatternMatch;
  test(pfcn);
}
