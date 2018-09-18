#include <string>
#include <cassert>
#include <stack>

using namespace std;

class Solution
{
public:
    bool
    isValid( string s )
    {
        stack<char> stk;
        for(const auto& c : s){
            switch(c){
                case '{':  stk.push('}'); break;
                case '[':  stk.push(']'); break;
                case '(':  stk.push(')'); break;
                default:
                    if(stk.empty() || c != stk.top()) return false;
                    else stk.pop();
            }
        }
        return stk.empty();
    }
};

using ptr2isValid = bool ( Solution::* )( string );


void
test( ptr2isValid pfcn )
{
    Solution sol;
    assert ((sol.*pfcn)( "()" ));
    assert(!(sol.*pfcn)( "([)]" ));
    assert((sol.*pfcn)("[](){}"));
}


int
main()
{
    ptr2isValid pfcn = &Solution::isValid;
    test( pfcn );
}