#include <string>
#include <cassert>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool
    isValid( string s )
    {
        stack<char> stk;
        for ( const auto &c : s )
        {
            switch (c)
            {
                case '{': stk.push( '}' );
                    break;
                case '[': stk.push( ']' );
                    break;
                case '(': stk.push( ')' );
                    break;
                default:
                    if ( stk.empty() || c != stk.top())
                        return false;
                    else
                        stk.pop();
            }
        }
        return stk.empty();
    }


    bool
    isValid2( string s )
    {
        unordered_map<char, char> table;
        stack<char> st;
        table['('] = ')';
        table['['] = ']';
        table['{'] = '}';
        for (auto & c : s)
        {
            if (table.find(c) != table.end())
            {
                st.push(c);
            }
            else if (st.empty() || table[st.top()] != c)
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        return st.empty();
    }
};

using ptr2isValid = bool ( Solution::* )( string );


void
test( ptr2isValid pfcn )
{
    Solution sol;
    assert ((sol.*pfcn)( "()" ));
    assert( !(sol.*pfcn)( "([)]" ));
    assert((sol.*pfcn)( "[](){}" ));
}


int
main()
{
    ptr2isValid pfcn = &Solution::isValid;
    test( pfcn );
    pfcn = &Solution::isValid2;
    test(pfcn);
}