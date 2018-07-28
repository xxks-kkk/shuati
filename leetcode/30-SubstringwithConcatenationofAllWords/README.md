## Solution explanation

### Approach 1: two pointers

The idea is very similar to two pointers. We first create a dictionary `counts` and for every possible char in `s`,
we try to build another dictionary `seen`. Whenever `seen` looks exactly like `counts`, we update our final result.

- Time complexity: $O(n^2)$

## Reference

- https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/Easy-Two-Map-Solution-(C++Java)