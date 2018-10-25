//    Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
//
//    Example 1:
//
//    Input: 123
//    Output: "One Hundred Twenty Three"
//    Example 2:
//
//    Input: 12345
//    Output: "Twelve Thousand Three Hundred Forty Five"
//    Example 3:
//
//    Input: 1234567
//    Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//    Example 4:
//
//    Input: 1234567891
//    Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

#include <string>
#include <cassert>

using namespace std;

class Solution
{
public:
    string
    numberToWords(int num)
    {
        if (num == 0)
        {
            return "Zero";
        }
        else
        {
            string ret = int2string(num);
            return ret.substr(1);
        }
    }
private:
    string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                         "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                         "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string
    int2string(int n)
    {
        if (n >= 1000000000)
        {
            // billion: 10^9
            return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
        }
        else if (n >= 1000000)
        {
            // million: 10^6
            return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
        }
        else if (n >= 1000)
        {
            // thousand: 10^3
            return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
        }
        else if (n >= 100)
        {
            // hundred: 10^2
            return int2string(n / 100) + " Hundred" + int2string(n % 100);
        }
        else if (n >= 20)
        {
            return " " + tens[n / 10] + int2string(n % 10);
        }
        else if (n >= 1)
        {
            return " " + digits[n];
        }
        else
        {
            return "";
        }
    }
};

using ptr2numberToWords = string (Solution::*)(int);

void
test(ptr2numberToWords pfcn)
{
    Solution sol;
    assert((sol.*pfcn)(123) == "One Hundred Twenty Three");
    assert((sol.*pfcn)(12345) == "Twelve Thousand Three Hundred Forty Five");
    assert((sol.*pfcn)(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    assert((sol.*pfcn)(1234567891) == "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One");
}

int
main()
{
    ptr2numberToWords pfcn = &Solution::numberToWords;
    test(pfcn);
}