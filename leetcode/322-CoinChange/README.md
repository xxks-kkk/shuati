## Solution explanation

A typical DP problem and I think the bottom-up DP approach makes the most sense for me.

$$
DP[s] = \text{minimum number of coins needed to make change for amount s using the given coins}
$$

Then, we have $DP[s] = DP[s-c] + 1$ where $c$ represents the coin value. Here, we need to traverse all possible $c$
value in order to find out the $DP[s]$. The base case: $DP[0] = 0$

## Reference

- https://leetcode.com/problems/coin-change/solution/