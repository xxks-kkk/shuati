#include <cassert>
#include <vector>

// For jump 1, 2, 3 steps or 1,3 steps, see "RemoveChocolates.cc"
using namespace std;

class Solution
{
public:
    // Solution 1: using DP
    int
    climbStairs(int n)
    {
        // dp[i] = # of ways to reach i
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i < n + 1; ++i)
        {
            if (i >= 1)
            {
                dp[i] += dp[i - 1];
            }
            if (i >= 2)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }

    // Solution 2: without extra space
    int
    climbStairs2(int n)
    {
        int a = 1;  // # of ways to reach the current step
        int b = 1;  // # of ways to reacg the next step
        for (int i = 0; i < n; ++i)
        {   /*  a     b
             *  |     |
             *  cur   next
             *  1     1
             */
            // So for the situation one step further up, the old b becomes the new a,
            // and the new b is the old a+b, since the new step can be reached by climbing 1 step from what
            // b represented or 2 steps from what a represented
            b += a;
            a = b - a; // essentially a = b
        }
        return a;
    }
};

using ptr2climbStairs = int (Solution::*)(int);

void
test(ptr2climbStairs pfcn)
{
    Solution sol;
    assert((sol.*pfcn)(3) == 3);
    assert((sol.*pfcn)(2) == 2);
}

int
main()
{
    ptr2climbStairs pfcn = &Solution::climbStairs;
    test(pfcn);
    pfcn = &Solution::climbStairs2;
    test(pfcn);
}