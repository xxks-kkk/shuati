//    You are given a string, s, and a list of words, words, that are all of the same length.
//    Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and
//    without any intervening characters.
//
//    Example 1:
//
//    Input:
//    s = "barfoothefoobarman",
//        words = ["foo","bar"]
//    Output: [0,9]
//    Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
//    The output order does not matter, returning [9,0] is fine too.
//    Example 2:
//
//    Input:
//    s = "wordgoodstudentgoodword",
//        words = ["word","student"]
//    Output: []

#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>
#include <iostream>

using namespace std;

class Solution
{
public:
    // Approach 1: two pointers
    vector<int>
    findSubstring( string s, vector<string> &words )
    {
        if ( s.size() == 0 || words.empty())
        {
            return {};
        }
        unordered_map<string, int> counts;
        for ( auto &word : words )
            counts[word]++;
        unsigned long n = s.length();
        unsigned long num = words.size();
        unsigned long len = words[0].length();
        vector<int> indexes;
        for ( int i = 0; i < n - num * len + 1; i++ )
        {
            unordered_map<string, int> seen;
            int j = 0;
            for ( ; j < num; j++ )
            {
                string word = s.substr( i + j * len, len );
                if ( counts.find( word ) != counts.end())
                {
                    seen[word]++;
                    if ( seen[word] > counts[word] )
                        break;
                }
                else
                    break;
            }
            if ( j == num )
                indexes.push_back( i );
        }
        return indexes;
    }
};

using ptr2findSubstring = vector<int> ( Solution::* )( string, vector<string> & );


void
test( ptr2findSubstring pfcn )
{
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> ans = {0, 9};
    assert((sol.*pfcn)( s, words ) == ans );

    s = "wordgoodstudentgoodword";
    words = {"word", "student"};
    ans = {};
    assert((sol.*pfcn)( s, words ) == ans );

    s = "wordgoodgoodgoodbestword";
    words = {"word", "good", "best", "word"};
    ans = {};
    assert((sol.*pfcn)( s, words ) == ans );

    s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    words = {"fooo", "barr", "wing", "ding", "wing"};
    ans = {13};
    assert((sol.*pfcn)( s, words ) == ans );
}


int
main()
{
    ptr2findSubstring pfcn = &Solution::findSubstring;
    test( pfcn );
}