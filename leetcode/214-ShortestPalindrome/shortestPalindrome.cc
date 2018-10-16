//    Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it.
//    Find and return the shortest palindrome you can find by performing this transformation.
//
//    Example 1:
//
//    Input: "aacecaaa"
//    Output: "aaacecaaa"
//    Example 2:
//
//    Input: "abcd"
//    Output: "dcbabcd"

#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
    // My naive solution
    string
    shortestPalindrome(string s)
    {
        int n = s.length();
        if (isPalindrome(s))
        {
            return s;
        }
        while (true)
        {
            int mid;
            int left;
            int right;
            if (n % 2 == 1)
            {
                mid = n / 2;
                left = mid - 1;
                right = mid + 1;
            }
            else
            {
                mid = n / 2;
                left = mid - 1;
                right = mid;
            }
            while (mid > 0)
            {
                if (s[left] != '0' && s[left] != s[right])
                {
                    // For example, "0abcd", mid point is "b",
                    // however, left point at "a" and right point at "c"
                    // Since "a" != "c", we cannot form the palindrome
                    // The only situation we can form the palindrome is
                    // when left is "0" and right is some character
                    // for example, "000abcd". left "0" and right is "b".
                    break;
                }
                left--;
                right++;
                mid--;
            }
            if (mid == 0)
            {
                if (n % 2 == 1)
                {
                    string tmp = s.substr(n / 2 + 1);
                    reverse(tmp.begin(), tmp.end());
                    return tmp + s.substr(n / 2);
                }
                else
                {
                    string tmp = s.substr(n / 2);
                    reverse(tmp.begin(), tmp.end());
                    return tmp + s.substr(n / 2);
                }
            }
            n += 1;
            // we use "0" as the place holder
            s = "0" + s;
        }
    }

    // Brute Force solution
    string
    shortestPalindrome3(string s)
    {
        // Understand code, think about an example: "abcb"
        int n = s.length();
        string rev(s);
        reverse(rev.begin(), rev.end());
        for(int i = 0; i < n; ++i)
        {
            if (s.substr(0,n-i) == rev.substr(i))
            {
                return rev.substr(0,i) + s;
            }
        }
        return "";
    }

    // Two pointers and recursion solution
    string
    shortestPalindrome2(string s)
    {
        int n = s.length();
        int i = 0;
        for(int j = n-1; j>=0; j--)
        {
            if(s[i] == s[j])
            {
                i++;
            }
        }
        if (i == n)
        {
            return s;
        }
        string remain = s.substr(i);
        reverse(remain.begin(), remain.end());
        return remain + shortestPalindrome2(s.substr(0, i)) + s.substr(i);
    }

    // TODO: KMP Solution
private:
    bool
    isPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return true;
        }
        if (n % 2 == 0)
        {
            return false;
        }
        int mid = n / 2;
        string tmp = s.substr(n / 2 + 1);
        reverse(tmp.begin(), tmp.end());
        return tmp == s.substr(0, n / 2);
    }
};

using ptr2shortestPalindrome = string (Solution::*)(string);

void test(ptr2shortestPalindrome pfcn)
{
    Solution sol;
    string s = "aacecaaa";
    assert("aaacecaaa" == (sol.*pfcn)(s));

    s = "abcd";
    assert("dcbabcd" == (sol.*pfcn)(s));
}

int main()
{
    ptr2shortestPalindrome pfcn = &Solution::shortestPalindrome;
    test(pfcn);

    pfcn = &Solution::shortestPalindrome3;
    test(pfcn);

    pfcn = &Solution::shortestPalindrome2;
    test(pfcn);
}