## Solution explanation

### Solution 1: Disjset (Union-Find) [Accepted]

The first solution utilizes the data structure called disjoint set. The idea comes from the observation
that if a region is NOT captured, it is connected to the boundary. So if we connect all the `'O'`
nodes on the boundary to a dummy node, and then connect each `'O'` node to its neighbour `'O'`
nodes, then can tell directly whether a `'O'` node is captured by checking whether it is connected to the
dummy node.

### Solution 2: Simple rules [Accepted]

Solution 2 use the similar idea as the solution 1. The idea is following:

- First, check the four border of the matrix. If there is a element is
`'O'`, alter it and all its neighbor `'O'` elements to `'S'`.
- Then ,alter all the `'O'` to `'X'`
- At last,alter all the `'S'` to `'O'`


## Reference

- https://discuss.leetcode.com/topic/1944/solve-it-using-union-find
- https://discuss.leetcode.com/topic/17224/a-really-simple-and-readable-c-solution-only-cost-12ms
- https://discuss.leetcode.com/topic/18706/9-lines-python-148-ms
- http://www.cnblogs.com/grandyang/p/4555831.html