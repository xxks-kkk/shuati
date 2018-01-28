## Solution explanation

### Solution 1: backtracking [Accepted]

We can solve this problem with backtracking. The code structure is very similar to "77 - Combinations".
See "77 - Combinations" for explanation. Note that we use `index` structure.

Time complexity for this solution: $O(n*2^n)$.

There are two ways to understand this time complexity:

1. We let $T(n)$ denote all possible palindrome partition for string with length $n$. Then, we have
$T(n) = T(n-1) + T(n-2) + \dots + T(1)$. To solve this recurrence relation, we can take a look 
at $T(n+1) = T(n) + T(n-1) + \dots + T(1)$. We take difference between these two and we have
$T(n+1) - T(n) = T(n)$, which indicates that $T(n) = 2^n$. In addition, it takes $O(n)$ time to check
if a string with length $n$ is palindrome. So, the total running time is $O(n*2^n)$.

2. For a string with length $n$, there will be $(n - 1)$ intervals between chars.
For every interval, we can cut it or not cut it, so there will be $2^(n - 1)$ ways to partition the string.
For every partition way, we need to check if it is palindrome, which is $O(n)$.
So the time complexity is $O(n*(2^n))$.


## Reference

- https://leetcode.com/problems/palindrome-partitioning/discuss/41963