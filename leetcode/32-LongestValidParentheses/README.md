## Solution Explanation

### Approach 1: Using stack

Please take a look at the code for the understanding. There is animation in the official solution.

- Time Complexity: $O(n)$
- Space Complexity: $O(n)$

### Approach 2: Without extra space

The idea is following:

When right parentheses are more than left parentheses in the forward pass, we can discard previous parentheses.
In the backward pass, when left parentheses are more than right parentheses, we can discard previous parentheses.

- Time Complexity: $O(n)$
- Space Complexity: $O(1)$

### Approach 3: DP

We make use of a `DP` array and $DP[i] = \text{the length of the longest valid substrings ending at ith index}$.
We initialize the complete `DP` array with 0. We observe that the valid substrings must end with `)`. This further
leads to the conclusion that the substring ending with `(` will always contain `0` at their corresponding `DP` indices.
Thus, we update the `DP` array only when `)` is encountered.

To fill `DP` array we will check every two consecutive characters of the string and if

1. `s[i] == )` and `s[i-1] == (` (string looks like `...()`). We have

        `DP[i] = DP[i-2] + 2`

2. `s[i] == )` and `s[i-1] == )` (string looks like `...))`). If `s[i - DP[i-1] - 1] == (` then

        `DP[i] = DP[i-1] + DP[i - DP[i-1] - 2] + 2`

For example, suppose string looks like `() ( ()() )` (we use space to make grouping clear).

| index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|-------|---|---|---|---|---|---|---|---|
| char  | ( | ) | ( | ( | ) | ( | ) | ) |

We have `s[7] == )` (`i = 7`) and `DP[i-1] = 4` (string `()()` from index 3 to 6). `s[i - DP[i-1] - 1] = s[7-4-1] = s[2] == (`
and thus we have the DP relation. Another way to think about is

```
...)                | ( ... )       )
   |                        |       |
 dp[i-dp[i-1]-2]         dp[i-1] dp[i]
```

- Time Complexity: $O(n)$
- Space Complexity: $O(1)$

## Reference

- https://leetcode.com/problems/longest-valid-parentheses/solution/
- https://leetcode.com/problems/longest-valid-parentheses/discuss/14140/Constant-space-O(n)-time-with-forward-and-backward-pass