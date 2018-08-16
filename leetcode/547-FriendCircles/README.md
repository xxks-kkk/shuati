## Solution explanation

The given matrix can be viewed as the adjaceny matrix of a graph. Then the problem becomes of finding the number of
connected components in an undirected graph. For example,

```
M= [1 1 0 0 0 0

    1 1 0 0 0 0

    0 0 1 1 1 0

    0 0 1 1 0 0

    0 0 1 0 1 0

    0 0 0 0 0 1]
```

Then, the connected components in this graph as `1-0, 5, 2-3-4`. To find number of connected components in an undirected graph,
there are three methods we can use: DFS, BFS, Union find.

## Reference

- https://leetcode.com/problems/friend-circles/solution/