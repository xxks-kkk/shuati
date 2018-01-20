## Solution explanation

### Solution 1 [Accepted]

Solution 1 implemented in `connect` comes up by myself. It handles various scenarios. The solution
leaves here for restrospective purpose. This solution can be easily coded wrong. Please
take a look at the solution 2.

### Solution 2 [Accepted]

The big idea is to do the level-order traversal. Here, we create a dummy node `dummy` that points
to the first node of the next level. Then, we use `curr` to traverse the nodes on the current level
and link them together. To best understand this code (implemented as `connect2`), 
we can work out an example like this:

```
      0
     / \
    2   4
   /   / \
  1   3   -1
 / \   \    \
5  1    6    8
```


## Reference 

- https://discuss.leetcode.com/topic/8447/simple-solution-using-constant-space/5
