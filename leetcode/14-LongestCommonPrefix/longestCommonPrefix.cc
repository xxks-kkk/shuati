//    Write a function to find the longest common prefix string amongst an array of strings.
//
//    If there is no common prefix, return an empty string "".
//
//    Example 1:
//
//    Input: ["flower","flow","flight"]
//    Output: "fl"
//    Example 2:
//
//    Input: ["dog","racecar","car"]
//    Output: ""
//    Explanation: There is no common prefix among the input strings.
//    Note:
//
//    All given inputs are in lowercase letters a-z.

#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include "trie.h"

using namespace std;

class Solution
{
public:
    // Approach 1: Horizontal scanning
    string
    longestCommonPrefix( vector<string> &strs )
    {
        if ( !strs.size())
        {
            return "";
        }
        string prefix = strs[0];
        for ( int i = 1; i < strs.size(); ++i )
        {
            int j = 0;
            while ( strs[i][j] == prefix[j] )
            {
                j++;
            }
            if ( j == 0 )
            {
                return "";
            }
            prefix = prefix.substr( 0, j );
        }
        return prefix;
    }


    // Approach 2: Vertical Scanning
    string
    longestCommonPrefix2( vector<string> &strs )
    {
        if ( strs.empty())
        {
            return "";
        }
        for ( int i = 0; i < strs[0].size(); ++i )
        {
            char c = strs[0][i];
            for ( int j = 1; j < strs.size(); ++j )
            {
                if ( i == strs[j].size() || c != strs[j][i] )
                {
                    return strs[0].substr( 0, i );
                }
            }
        }
        return strs[0];
    }


    // Approach 3: Divide and Conquer
    string
    longestCommonPrefix3( vector<string> &strs )
    {
        if ( strs.empty())
        {
            return "";
        }
        // Be careful, we pass in `strs.size() - 1`.
        return longestCommonPrefix3Helper( strs, 0, strs.size() - 1 );
    }


    // Approach 4: Binary search
    string
    longestCommonPrefix4( vector<string> &strs )
    {
        if ( strs.empty())
        {
            return "";
        }
        int minLen = INT_MAX;
        for ( auto &str : strs )
        {
            if ( str.size() < minLen )
            {
                minLen = str.size();
            }
        }
        int left = 0;
        int right = minLen;
        // invariant: the LCP is from [0, mid) where mid \in [left, right] (?)
        // <= is needed for {"a", "b"} case
        while ( left <= right )
        {
            int mid = (left + right) / 2;
            if ( isCommonPrefix( strs, mid ))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return strs[0].substr( 0, (left + right) / 2 );
    }


    // Approach 5: using Trie
    string
    longestCommonPrefix5( vector<string> &strs )
    {
        auto trie = new Trie();
        for ( auto &str: strs )
        {
            trie->insert( str );
        }
        return trie->longestCommonPrefix();
    }


private:
    string
    longestCommonPrefix3Helper( vector<string> &strs, int left, int right )
    {
        if ( left == right )
        {
            return strs[left];
        }
        int mid = (left + right) / 2;
        string lcpLeft = longestCommonPrefix3Helper( strs, left, mid );
        string lcpRight = longestCommonPrefix3Helper( strs, mid + 1, right );
        return commonPrefix( lcpLeft, lcpRight );
    }


    string
    commonPrefix( string left, string right )
    {
        int minVal = min( left.size(), right.size());
        for ( int i = 0; i < minVal; ++i )
        {
            if ( left[i] != right[i] )
            {
                return left.substr( 0, i );
            }
        }
        return left.substr( 0, minVal );
    }


    bool
    isCommonPrefix( vector<string> &strs, int len )
    {
        string prefix = strs[0].substr( 0, len );
        for ( int i = 1; i < strs.size(); ++i )
        {
            if ( strs[i].substr( 0, prefix.length()) != prefix )
            {
                return false;
            }
        }
        return true;
    }

};

using ptr2longestCommonPrefix = string ( Solution::* )( vector<string> & );


void
test( ptr2longestCommonPrefix pfcn )
{
    Solution sol;
    vector<string> input = {"flower", "flow", "flight"};
    assert((sol.*pfcn)( input ) == "fl" );
    input = {"dog", "racecar", "car"};
    assert((sol.*pfcn)( input ) == "" );
    input = {"a", "b"};
    assert((sol.*pfcn)( input ) == "" );
}


int
main()
{
    ptr2longestCommonPrefix pfcn = &Solution::longestCommonPrefix;
    test( pfcn );
    pfcn = &Solution::longestCommonPrefix2;
    test( pfcn );
    pfcn = &Solution::longestCommonPrefix3;
    test( pfcn );
    pfcn = &Solution::longestCommonPrefix4;
    test( pfcn );
    pfcn = &Solution::longestCommonPrefix5;
    test( pfcn );
}