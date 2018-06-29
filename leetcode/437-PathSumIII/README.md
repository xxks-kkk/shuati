## Solution explanation

Let me present my failure attempt first:

```cpp
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
        {
            return 0;
        }
        return pathSumHelper(root, sum, sum)
            +  pathSumHelper(root->left, sum)    // wrong (C)
            +  pathSumHelper(root->right, sum);
    }
private:
    int pathSumHelper(TreeNode* root, int target, int sum)
    {
        int count = 0;
        if (root == nullptr)
        {
            return 0;
        }
        if (target < 0)  // wrong code block (A)
        {
            target = sum;
        }
        else if (target == root->val)
        {
            count += 1;
            target = sum; // wrong code (B)
        }
        count += pathSumHelper(root->left, target - root->val, sum);
        count += pathSumHelper(root->right, target - root->val, sum);
        return count;
    }
};
```

The most tricky part of the problem is that the path doesn't have to start from the root.

A) The code block is derived from the given example, where `target` < 0 once we pass the root `10`. Thus, I think of reset
value. However, this essentially means we perform `pathSum` for `5`, which is the important point to be realized to solve this one.

B) Don't need this code for the same reasoning as A). `pathSumHelper` essentially finds all the valid path starting from the root.
If we reset the `target` value inside the function, we violate our invariant we want to keep.

C) This is attempt to fix "the path doesn't have to start from root" statement given A) and B). As one can see, C) will
introduce the duplicate for the given example. Even if there is no B) and C), we are missing paths as we only find
all the valid path starting from `root`, `root->left`, and `root->right`.

### Approach 1: DFS

This problem actually uses two recursions.

- Time Complexity:

    - In the worst case, for the given tree like `[5, null, 8, null, 4, null, 1]` (degenerate tree), it is $O(n^2)$. To see
    this, we can calculate like the following:

        - # of times pass node `5` is 1 (`pathSumHelper(root, sum)` once)
        - # of times pass node `8` is 2 (once during `pathSumHelper(root, sum)` call to node `5` and once during the
        following recursive call when `8` is treated as root)
        - # of times pass node `4` is 3
        - ...

    Thus we have $1 + 2 + \dots + n$ = $O(n^2)$

    - In the best case, for the given tree like `[5,4,8,11,null,13,4,7,2,null,null,5,1]` (balanced tree),
    the runtime is $O(n\log n)$ because

        - # of times pass node `5` is 1
        - # of times pass node `4` and `8` are 2: Both are in the same level right below `5`
        - ...
        - # of times pass node `2` (the node in the last layer) is $\log n$

    As you can see, the number of visit times for each node really depends on the level they are at (i.e. their depth). In
    this case, we have $1 + 2 + \dots + \log n = (1 + \log n) \times n/2 = O(n \log n)$.

### Approach 2: Hash map

This approach is exactly the same as "2 - Two Sum": using `map` to store ( key : the prefix sum, value : how many ways get to this prefix sum)
, and whenever reach a node, we check if value "prefix sum - target" exists as a key in the map or not, if it does,
we added up the ways of getting "prefix sum - target" into the final count.

Remember we need to do backtracking just like what we do with DFS.


- Time complexity: $O(n)$
- Space complexity: $O(n)$

## Reference

- https://leetcode.com/problems/path-sum-iii/discuss/91889/Simple-Java-DFS
- https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method