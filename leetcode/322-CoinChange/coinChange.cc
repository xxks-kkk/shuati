//    You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//    
//    Example 1:
//    
//    Input: coins = [1, 2, 5], amount = 11
//    Output: 3
//    Explanation: 11 = 5 + 5 + 1
//    Example 2:
//    
//    Input: coins = [2], amount = 3
//    Output: -1
//    Note:
//    You may assume that you have an infinite number of each kind of coin.

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // DP[i] = min # of coins for amount i
        vector<int> dp (amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
        {
            for(auto& coin : coins)
            {
                if (i >= coin)
                {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

using ptr2coinChange = int (Solution::*)(vector<int>&, int);

void test(ptr2coinChange pfcn)
{
    Solution sol;
    vector<int> coins = {1,2,5};
    int amount = 11;
    assert((sol.*pfcn)(coins, amount) == 3);
    
    coins = {2};
    amount = 3;
    assert((sol.*pfcn)(coins, amount) == -1);
}

int main()
{
    ptr2coinChange pfcn = &Solution::coinChange;
    test(pfcn);
}