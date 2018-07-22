//    Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
//    Example 1:
//
//    Input: 121
//    Output: true
//    Example 2:
//
//    Input: -121
//    Output: false
//    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//    Example 3:
//
//    Input: 10
//    Output: false
//    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

#include <string>
#include <cassert>

class Solution
{
public:
    bool
    isPalindrome( int x )
    {
        std::string strint = std::to_string( x );
        int strlength = strint.length();
        int i = 0;
        int j = strlength - 1;
        while ( j >= 0 && i <= strlength - 1 )
        {
            if ( strint[i] != strint[j] )
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }


    bool
    isPalindrome2( int x )
    {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, in order to be a palindrome,
        // the first digit of the number also needs to be 0.
        // Only 0 satisfy this property.
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int revertedNumber = 0;
        while (revertedNumber < x)
        {
            revertedNumber = x % 10 + revertedNumber * 10;
            x  /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123,
        // since the middle digit doesn't matter in palidrome(it will always equal to itself), we can simply get rid of it.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

using ptr2isPalindrome = bool ( Solution::* )( int );


void
test( ptr2isPalindrome pfcn )
{
    Solution sol;
    assert( sol.isPalindrome( 11 ));
    assert( !sol.isPalindrome( -121 ));
}


int
main()
{
    ptr2isPalindrome pfcn = &Solution::isPalindrome;
    test( pfcn );
    pfcn = &Solution::isPalindrome2;
    test( pfcn );
}