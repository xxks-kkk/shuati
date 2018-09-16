## Solution explanation

To achieve O(1) operations, we exploit the implementation of `std::list`, which is a doubly-linked list.
We can achieve O(1) operation on elements of the `std::list` as long as we have pointer to the candidate element
that we want to apply operation (e.g. insertion and deletion).

Please see the comments for the detailed walkthrough.

## Reference

- https://leetcode.com/problems/lru-cache/discuss/45976/C++11-code-74ms-Hash-table-+-List
- [YouTube explanation](https://www.youtube.com/watch?v=8-FZRAjR7qU)