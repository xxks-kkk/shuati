## Solution explanation

To achieve O(1) operations, we exploit the implementation of `std::list`, which is a doubly-linked list.
We can achieve O(1) operation on elements of the `std::list` as long as we have pointer to the candidate element
that we want to apply operation (e.g. insertion and deletion).

> Compared to other base standard sequence containers (array, vector and deque), 
> lists perform generally better in inserting, extracting and moving elements 
> in any position within the container for which an iterator has already been obtained, 
> and therefore also in algorithms that make intensive use of these, like sorting algorithms.

Please see the comments for the detailed walkthrough.

## Reference

- https://leetcode.com/problems/lru-cache/discuss/45976/C++11-code-74ms-Hash-table-+-List
- [YouTube explanation](https://www.youtube.com/watch?v=8-FZRAjR7qU)
- http://www.cplusplus.com/reference/list/list/
