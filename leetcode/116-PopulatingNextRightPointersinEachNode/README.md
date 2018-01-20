## Solution explanation

### Solution 1: Using queue [Not satisfy the problem requirement]

Very typical problem that uses BFS in binary tree using queue. However, this solution uses a 
queue, which is not a constant space.

## Solution 2: iterative approach [Accpeted]

The implementation `connect2` is quite straightforward. Basically, we traverse the tree level by level
For each level, we link the tree nodes in the next level.

## Reference

- https://discuss.leetcode.com/topic/6221/java-solution-with-o-1-memory-o-n-time