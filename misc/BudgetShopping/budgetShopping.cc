// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=446249&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26sortid%3D311
// Similar to LC322
#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    int budgetShopping(int n, vector<int>&bundleQuantities, vector<int>&bundleCosts)
    {
        int m = bundleCosts.size();
        // DP[i] = max number of notebooks can be purchased for money i
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i = 1; i < n+1; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if (i >= bundleCosts[j])
                {
                    dp[i] = max(dp[i], dp[i-bundleCosts[j]] + bundleQuantities[j]);
                }
            }
        }
        return dp[n];
    }
};

using ptr2budgetShopping = int (Solution::*)(int, vector<int>&, vector<int>&);

void test(ptr2budgetShopping pfcn)
{
    Solution sol;
    int n = 50;
    vector<int> bundleQuantities = {20,19};
    vector<int> bundleCosts = {24, 20};
    assert((sol.*pfcn)(n, bundleQuantities, bundleCosts) == 40);
}

int main()
{
    ptr2budgetShopping pfcn = &Solution::budgetShopping;
    test(pfcn);
}