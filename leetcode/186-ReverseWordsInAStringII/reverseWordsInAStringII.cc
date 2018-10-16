//    Given an input string , reverse the string word by word.
//
//    Example:
//
//    Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
//    Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
//    Note:
//
//    A word is defined as a sequence of non-space characters.
//    The input string does not contain leading or trailing spaces.
//    The words are always separated by a single space.
//    Follow up: Could you do it in-place without allocating extra space?

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void reverseWords(vector<char>& str) {
        // first reverse whole vector of char
        reverseHelper(str, 0, str.size()-1);
        int start = 0;
        // reverse each word
        for(int end = 0; end < str.size(); ++end)
        {
            if (str[end] == ' ' || end == str.size()-1)
            {
                if (end != str.size()-1)
                {
                    reverseHelper(str, start, end-1);
                }
                else
                {
                    reverseHelper(str, start, end);
                }
                start = end + 1;
            }
        }
    }
private:
    void reverseHelper(vector<char>& str, int start, int end)
    {
        int i = start;
        int j = end;
        while (i < j)
        {
            swap(str[i], str[j]);
            i++;
            j--;
        }
    }
};

using ptr2reverseWords = void (Solution::*)(vector<char>&);

void test(ptr2reverseWords pfcn)
{
    Solution sol;
    vector<char> input = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    vector<char> ans = {'b','l','u','e',' ','i','s',' ','s','k','y',' ','t','h','e'};
    (sol.*pfcn)(input);
    assert( input == ans);
}

int main()
{
    ptr2reverseWords pfcn = &Solution::reverseWords;
    test(pfcn);
}