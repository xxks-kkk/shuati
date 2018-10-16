//    Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
//    Example 1:
//    Input:s1 = "ab" s2 = "eidbaooo"
//    Output:True
//        Explanation: s2 contains one permutation of s1 ("ba").
//    Example 2:
//    Input:s1= "ab" s2 = "eidboaoo"
//    Output: False
//        Note:
//    The input strings only contain lower case letters.
//    The length of both given strings is in range [1, 10,000].

#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution
{
public:
    // Solve in the same way as LC30 (Approach 4 in the solution)
    bool
    checkInclusion(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return false;
        }
        unordered_map<char, int> s1count;
        for (auto &c : s1)
        {
            s1count[c]++;
        }
        for (int i = 0; i <= s2.length() - s1.length(); ++i)
        {
            unordered_map<char, int> s2count;
            int j;
            for (j = i; j < i + s1.length(); ++j)
            {
                char c = s2[j];
                s2count[c]++;
                if (s1count[c] < s2count[c])
                {
                    break;
                }
            }
            Match match;
            if (j == i + s1.length() && match(s2count, s1count))
            {
                return true;
            }
        }
        return false;
    }

    // Sliding window approach
    bool
    checkInclusion2(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return false;
        }
        unordered_map<char, int> s1count;
        unordered_map<char, int> s2count;
        Match match;
        for (int i = 0; i < s1.length(); ++i)
        {
            s1count[s1[i]]++;
            s2count[s2[i]]++;
        }
        for (int i = 0; i <= s2.length() - s1.length(); ++i)
        {
            if (match(s2count, s1count))
            {
                return true;
            }
            s2count[s2[i]]--;
            s2count[s2[i + s1.length()]]++;
        }
        return false;
    }
private:
    struct Match
    {
        bool
        operator()(unordered_map<char, int> &m1, unordered_map<char, int> &m2)
        {
            for (auto &item: m1)
            {
                if (item.second != m2[item.first])
                {
                    return false;
                }
            }
            return true;
        }
    };
};

using ptr2checkInclusion = bool (Solution::*)(string, string);

void
test(ptr2checkInclusion pfcn)
{
    Solution sol;
    assert((sol.*pfcn)("ab", "eidbaooo"));
    assert((sol.*pfcn)("adc", "dcda"));
}

int
main()
{
    ptr2checkInclusion pfcn = &Solution::checkInclusion;
    test(pfcn);

    pfcn = &Solution::checkInclusion2;
    test(pfcn);
}
