//    Given a string, sort it in decreasing order based on the frequency of characters.
//
//    Example 1:
//
//    Input:
//    "tree"
//
//    Output:
//    "eert"
//
//    Explanation:
//    'e' appears twice while 'r' and 't' both appear once.
//    So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//    Example 2:
//
//    Input:
//    "cccaaa"
//
//    Output:
//    "cccaaa"
//
//    Explanation:
//    Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
//    Note that "cacaca" is incorrect, as the same characters must be together.
//    Example 3:
//
//    Input:
//    "Aabb"
//
//    Output:
//    "bbAa"
//
//    Explanation:
//    "bbaA" is also a valid answer, but "Aabb" is incorrect.
//    Note that 'A' and 'a' are treated as two different characters.

#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // We simply use the bucket sort
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        vector<string> buckets(s.length()+1, "");
        string res = "";
        // count frequency of each character
        for(auto& c: s)
        {
            freq[c]++;
        }
        for(auto&item : freq)
        {
            // append(n, c): append character 'c' for n times
            buckets[item.second].append(item.second, item.first);
        }
        for(int i = buckets.size()-1; i >= 0; i--)
        {
            res += buckets[i];
        }
        return res;
    }
};

using ptr2frequencySort = string (Solution::*)(string);

void test(ptr2frequencySort pfcn)
{
    Solution sol;
    string s = "tree";
    assert((sol.*pfcn)(s) == "eert");

    s = "Aabb";
    assert((sol.*pfcn)(s) == "bbAa" || (sol.*pfcn)(s) == "bbaA");
}

int main()
{
    ptr2frequencySort pfcn = &Solution::frequencySort;
    test(pfcn);
}