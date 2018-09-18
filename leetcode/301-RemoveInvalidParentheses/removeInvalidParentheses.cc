//    Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
//    Note: The input string may contain letters other than the parentheses ( and ).
//
//    Example 1:
//
//    Input: "()())()"
//    Output: ["()()()", "(())()"]
//
//    Example 2:
//
//    Input: "(a)())()"
//    Output: ["(a)()()", "(a())()"]
//
//    Example 3:
//
//    Input: ")("
//    Output: [""]

#include <string>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<string>
    removeInvalidParentheses( string s )
    {
        queue<string> q;
        unordered_set<string> visited;
        vector<string> res;
        if ( s.empty())
        {
            res.emplace_back("");
            return res;
        }
        // initialize
        q.push( s );
        visited.emplace( s );

        bool found = false;

        while ( !q.empty())
        {
            auto cand = q.front();
            q.pop();
            if ( isValid( cand ))
            {
                // Once we found an answer, we add to the result
                res.emplace_back( cand );
                found = true;
            }
            if ( found )
            {
                // Since we already found a valid answer, we don't need to
                // further explore due to the problem requires the "remove the minimum number of invalid parentheses"
                // The rest of task is to finish the what left in the queue. In other words,
                // If we found a valid candidate and we further explore, "" will always appear in our result, which is
                // not what we want.
                continue;
            }
            // generate all possible states
            for ( int i = 0; i < cand.length(); ++i )
            {
                // we only try to remove left or right paren
                if ( cand[i] != '(' && cand[i] != ')' )
                {
                    continue;
                }
                string t = string( cand );
                t.erase( i, 1);
                if ( visited.find( t ) == visited.end())
                {
                    // for each state, if it's not visited, add it to the queue
                    visited.emplace( t );
                    q.push( t );
                }
            }
        }
        return res;
    }


private:
    bool
    isValid( string s )
    {
        int counter = 0;
        for ( auto &c: s )
        {
            if ( c == '(' )
                counter++;
            if ( c == ')' )
                counter--;
            if ( counter < 0 )
                return false;
        }
        return counter == 0;
    }
};

using ptr2removeInvalidParentheses = vector<string> ( Solution::* )( string );


void
test( ptr2removeInvalidParentheses pfcn )
{
    Solution sol;
    string s = "()())()";
    unordered_set<string> ans = {"()()()", "(())()"};
    auto res = (sol.*pfcn)( s );
    unordered_set<string> res_set( res.begin(), res.end());
    assert( res_set == ans );

    s = "(a)())()";
    ans = {"(a)()()", "(a())()"};
    res = (sol.*pfcn)( s );
    unordered_set<string> res_set2( res.begin(), res.end());
    assert( res_set2 == ans );

    s = ")(";
    ans = {""};
    res = (sol.*pfcn)( s );
    unordered_set<string> res_set3( res.begin(), res.end());
    assert( res_set3 == ans );
}


int
main()
{
    ptr2removeInvalidParentheses pfcn = &Solution::removeInvalidParentheses;
    test( pfcn );
}