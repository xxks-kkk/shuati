## Solution explanation

This problem can be solved by either BFS or DFS. However, there is one problem need to be careful:
We only do the copy for the unvisited node. In other words, for the visited node, we don't make a
copy of it and append the nodes connecting to it only.

For example, consider an undirected graph with two nodes `A` and `B` looks like below:

```
A - B
```

Assume that the starting point of the graph is `A`. First, you make a copy of node `A` (i.e., `A2`), 
and found that `A` has only one neighbor `B`. You make a copy of `B` (i.e., `B2`) and 
connects `A2->B2` by adding `B2` as `A2`’s neighbor. N
ext, you find that `B` has `A` as neighbor, which you have already made a copy of. 
Here, we have to be careful not to make a copy of `A` again, but to connect `B2->A2` by adding
`A2` as `B2`’s neighbor. But, how do we know if a node has already been copied?  HashMap (i.e., dictionary).
We use original node and its copy as the key-value pair. We only make a new copy for the unvisited
nodes. We choose key-value pair this ways as a shortcut to reference the copy node no matter whether
we have visited the node before or not (see the line `visited[neighbor]` in 
`visited[curr].neighbors.append(visited[neighbor])`).

## Reference

- https://leetcode.com/problems/clone-graph/discuss/42313/
- https://articles.leetcode.com/clone-graph-part-i/