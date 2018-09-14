//    Given two strings s and t , write a function to determine if t is an anagram of s.
//
//    Example 1:
//
//    Input: s = "anagram", t = "nagaram"
//    Output: true
//    Example 2:
//
//    Input: s = "rat", t = "car"
//    Output: false
//    Note:
//    You may assume the string contains only lowercase alphabets.
//
//    Follow up:
//    What if the inputs contain unicode characters? How would you adapt your solution to such case?

#include <string>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution
{
public:
    bool
    isAnagram( string s, string t )
    {
        unordered_map<char, int> dict1;
        for ( auto &c: s )
        {
            dict1[c] += 1;
        }
        for ( auto &c: t )
        {
            if ( dict1.find( c ) == dict1.end())
            {
                return false;
            }
            else
            {
                dict1[c] -= 1;
                if ( dict1[c] < 0 )
                {
                    return false;
                }
            }
        }
        for ( auto &element: dict1 )
        {
            if ( element.second > 0 )
            {
                return false;
            }
        }
        return true;
    }
};

using ptr2isAnagram = bool ( Solution::* )( string, string );


void
test( ptr2isAnagram pfcn )
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    assert((sol.*pfcn)( s, t ));
    s = "rat";
    t = "car";
    assert( !(sol.*pfcn)( s, t ));
}


int
main()
{
    ptr2isAnagram pfcn = &Solution::isAnagram;
    test( pfcn );
}