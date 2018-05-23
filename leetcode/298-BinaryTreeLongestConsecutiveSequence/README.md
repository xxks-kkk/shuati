## Solution explanation

The problem description is a little vague: "longest consecutive sequence path" can be more accurately interpreted as
"longest consecutive increasing path". The value difference between parent and child node is 1
[See discussion here on more details](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/discuss/74549/Don't-understand-what-is-consecutive-sequence).

### Method 1: Top-down DFS

Top-down approach is similar to an in-order traversal.
We use a variable `length` to store the current consecutive path length and pass it down the tree.
As we traverse, we compare the current node with its parent node to determine if it is consecutive. If not, we reset the length.

- Time complexity: $O(n)$
- Space complexity: $O(h)$

### Method 2: Bottom-up DFS

My solution falls into this category. Essentially, we find the longest consecutive sequence for left and right subtree and
then check whether the current node and its children satisfy the question requirement. Note that this idea mimics
the post-order traversal.

- Time complexity: $O(n)$
- Space complexity: $O(h)$

## Reference

- https://leetcode.com/articles/binary-tree-longest-consecutive-sequence/