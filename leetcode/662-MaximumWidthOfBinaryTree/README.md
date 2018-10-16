## Solution explanation

### BFS

```
            1
       2         3
     4   5     6   7
    8 9 x 11  x 13 x 15
```

Regardless whether these nodes exist:

- Always make the id of left child as parent_id * 2;
- Always make the id of right child as parent_id * 2 + 1;

### DFS

We know that a binary tree can be represented by an array (assume the root begins from the position with index 1 in the array). 
If the index of a node is `i`, the indices of its two children are `2*i` and `2*i + 1`. 
The idea is to use `vector<pair<int,int>>` to record the the indices of the leftmost node and rightmost node in each level, 
respectively. For each level of the tree, the width is `vec[level].first - vec[level].second + 1`. 
Then, we just need to find the maximum width.

## Reference

- https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106645/C%2B%2BJava-*-BFSDFS3liner-Clean-Code-With-Explanation
- https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/106654/JavaC%2B%2B-Very-simple-dfs-solution