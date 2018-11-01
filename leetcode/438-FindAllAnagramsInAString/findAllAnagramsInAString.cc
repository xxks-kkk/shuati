//    Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
//    Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
//    The order of output does not matter.
//
//    Example 1:
//
//    Input:
//    s: "cbaebabacd" p: "abc"
//
//    Output:
//    [0, 6]
//
//    Explanation:
//    The substring with start index = 0 is "cba", which is an anagram of "abc".
//    The substring with start index = 6 is "bac", which is an anagram of "abc".
//    Example 2:
//
//    Input:
//    s: "abab" p: "ab"
//
//    Output:
//    [0, 1, 2]
//
//    Explanation:
//    The substring with start index = 0 is "ab", which is an anagram of "ab".
//    The substring with start index = 1 is "ba", which is an anagram of "ab".
//    The substring with start index = 2 is "ab", which is an anagram of "ab".

#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution
{
public:
    // Sliding window approach
    vector<int>
    findAnagrams(string s, string p)
    {
        if (p.length() > s.length())
        {
            return {};
        }
        vector<int> res;
        unordered_map<char, int> table;
        unordered_map<char, int> counter;
        for (auto &c: p)
        {
            table[c]++;
        }
        for(int i = 0; i < p.length(); ++i)
        {
            counter[s[i]]++;
        }
        if (counter == table)
        {
            res.push_back(0);
        }
        //here window is moving from left to right across the string.
        //window size is p.size(), so s.size()-p.size() moves are made
        for (int i = p.length(); i < s.length(); ++i)
        {
            // window extends one step to the right. counter for s[i] is incremented
            counter[s[i]]++;
            // since we added one element to the right,
            // one element to the left should be forgotten.
            // counter for s[i-p.size()] is decremented
            counter[s[i-p.length()]]--;
            if (counter[s[i-p.length()]] == 0)
            {
                counter.erase(s[i-p.length()]);
            }
            // if after move to the right the anagram can be composed,
            // add new position of window's left point to the result 
            if (counter == table)
            {
                res.push_back(i-p.length()+1);
            }
        }
        return res;
    }
};

using ptr2findAnagrams = vector<int> (Solution::*)(string, string);

void
test(ptr2findAnagrams pfcn)
{
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = {0,6};
    assert((sol.*pfcn)(s, p) == res);
}

int
main()
{
    ptr2findAnagrams pfcn = &Solution::findAnagrams;
    test(pfcn);
}