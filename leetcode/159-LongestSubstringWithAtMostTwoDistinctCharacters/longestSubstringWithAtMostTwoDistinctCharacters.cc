//    Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
//
//    Example 1:
//
//    Input: "eceba"
//    Output: 3
//    Explanation: t is "ece" which its length is 3.
//    Example 2:
//
//    Input: "ccaabbb"
//    Output: 5
//    Explanation: t is "aabbb" which its length is 5.

#include <string>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution
{
public:
    // My 1st attempt: works but too slow
    int
    lengthOfLongestSubstringTwoDistinct( string s )
    {
        int max_len = 0;
        int len = 0;
        unordered_set<int> counts;
        for ( int i = 0; i < s.length(); ++i )
        {
            int j = i;
            while ( j < s.length())
            {
                if ( counts.find( s[j] ) == counts.end())
                {
                    counts.emplace( s[j] );
                }
                if ( counts.size() > 2 )
                {
                    break;
                }
                len += 1;
                j++;
            }
            max_len = max( len, max_len );
            len = 0;
            counts.erase( counts.begin(), counts.end());
        }
        return max_len;
    }


    // Solution: sliding window approach
    int
    lengthOfLongestSubstringTwoDistinct2( string s )
    {
        if ( s.empty())
        {
            return 0;
        }
        int dict[256];
        fill_n( dict, 256, 0 );
        // start index of the substring
        int start = 0;
        int max_len = 1;
        // count the number of unique chars in the substring
        int count = 0;
        for ( int i = 0; i < s.length(); ++i )
        {
            dict[s[i]]++;
            if(dict[s[i]] == 1)
            {
                // We encounter a new char and we increment the count of
                // the unique chars in the substring
                count++;
                while(count > 2)
                {
                    // slide the window to the right
                    // doing so will remove the char pointed by "start" from the substring
                    dict[s[start]]--;
                    if(dict[s[start]] == 0)
                    {
                        // when dict[s[start]] == 0, that means s[start] no longer appears in the substring
                        // thus, we can decrement the count
                        count--;
                    }
                    // Our window is slided to the right by one
                    start++;
                }
            }
            if (i - start + 1 > max_len)
            {
                max_len = i - start + 1;
            }
        }
        return max_len;
    }
};

using ptr2lengthOfLongestSubstringTwoDistinct = int ( Solution::* )( string );


void
test( ptr2lengthOfLongestSubstringTwoDistinct pfcn )
{
    Solution sol;
    string s = "aa";
    assert((sol.*pfcn)( s ) == 2 );
    s = "bacc";
    assert((sol.*pfcn)( s ) == 3 );
}


int
main()
{
    ptr2lengthOfLongestSubstringTwoDistinct pfcn = &Solution::lengthOfLongestSubstringTwoDistinct;
    test( pfcn );
    pfcn = &Solution::lengthOfLongestSubstringTwoDistinct2;
    test(pfcn);
}