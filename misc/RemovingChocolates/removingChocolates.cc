// http://www.1point3acres.com/bbs/thread-446266-1-1.html
// Similar to LC70
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    // standard DP way
    // Can speed up by when come to mod
    int numberofWays(int n)
    {
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i < n+1; ++i)
        {
            if (i >= 1)
            {
                dp[i] += dp[i-1];
            }
            if (i >= 3)
            {
                dp[i] += dp[i-3];
            }
        }
        return dp[n] % (unsigned int)(7 + 10e9);
    }

    // More optimized way
    // https://leetcode.com/problems/climbing-stairs/discuss/25296/3-4-short-lines-in-every-language
    // https://stackoverflow.com/questions/22562023/n-steps-with-1-2-or-3-steps-taken-how-many-ways-to-get-to-the-top/34593246#34593246
    int numberofWays2(int n)
    {
        int a = 0; // prev prev step
        int b = 0; // prev step
        int c = 1; // current step
        int i = 0;
        while(i < n)
        {
            auto a_old = a;
            a = b;
            b = c;
            c = a_old + c;
            ++i;
        }
        return c;
    }

    // https://stackoverflow.com/questions/2661697/most-optimized-way-to-calculate-modulus-in-c
    // Tried to avoid module (maybe work)
    int numberofWays3(int n)
    {
        auto mod = (unsigned int) (7 + 10e9);
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i < n+1; ++i)
        {
            if (i >= 1)
            {
                dp[i] += dp[i-1];
                if (dp[i] >= mod)
                {
                    dp[i] -= mod;
                }
            }
            if (i >= 3)
            {
                dp[i] += dp[i-3];
                if (dp[i] >= mod)
                {
                    dp[i] -= mod;
                }
            }
        }
        return dp[n];
    }
};

using ptr2numberofWays = int (Solution::*)(int);

void test(ptr2numberofWays pfcn)
{
    Solution sol;
    assert((sol.*pfcn)(3) == 2);
    assert((sol.*pfcn)(7) == 9);
}

int main()
{
    ptr2numberofWays pfcn = &Solution::numberofWays;
    test(pfcn);
    pfcn = &Solution::numberofWays2;
    test(pfcn);
    pfcn = &Solution::numberofWays3;
    test(pfcn);
}
