## Solution explanation

Similar to LC347 Top K Elements. However, since there are duplicates in the problem, we naturally use `set` instead of
`priority_queue`. However, the logic is very similar.

In terms of running time, it is $O(n \log 3)$ = $O(n)$.

## Reference

- https://leetcode.com/problems/third-maximum-number/discuss/90209/Short-easy-C++-using-set