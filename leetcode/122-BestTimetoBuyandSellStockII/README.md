## Solution explanation

The idea is that we add up all the positive price difference (i.e. positive profit) and the profit we get is automatically
be optimal (because we never pick negative).

1. Calculate `prices[i+1]-prices[i]`
2. Turn the array `prices[] = [1,2,4,2,5,7,2,4,9,0]` into `difference[] = [+1,+2,-2,+3,+2,-5,+2,+5,-9]`
3. Then add all positive numbers `profit = 1+2+3+2+2+5 = 15` in difference
4. Return `15`

## Reference

- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/39582/Quite-easy-share-my-C-code-with-explanation