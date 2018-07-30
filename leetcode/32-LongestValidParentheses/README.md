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

## Reference

- https://leetcode.com/problems/longest-valid-parentheses/solution/
- https://leetcode.com/problems/longest-valid-parentheses/discuss/14140/Constant-space-O(n)-time-with-forward-and-backward-pass