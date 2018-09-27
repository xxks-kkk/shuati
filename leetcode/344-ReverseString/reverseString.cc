//    Write a function that takes a string as input and returns the string reversed.
//
//    Example 1:
//
//    Input: "hello"
//    Output: "olleh"
//    Example 2:
//
//    Input: "A man, a plan, a canal: Panama"
//    Output: "amanaP :lanac a ,nalp a ,nam A"

#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

using ptr2reverseString = string (Solution::*)(string);

void test(ptr2reverseString pfcn)
{
    Solution sol;
    string s = "hello";
    assert((sol.*pfcn)(s) == "olleh");

    s = "A man, a plan, a canal: Panama";
    assert((sol.*pfcn)(s) == "amanaP :lanac a ,nalp a ,nam A");
}

int main()
{
    ptr2reverseString pfcn = &Solution::reverseString;
    test(pfcn);
}