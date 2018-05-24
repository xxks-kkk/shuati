## Solution explanation

Let me show my failed attempt first.

```cpp
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = 0;
        int max = std::numeric_limits<int>::min();
        maxPathSumHelper(root, sum, max);
        return max;
    }
private:
    void maxPathSumHelper(TreeNode* root, int & sum, int & max) {
        if(root == nullptr)
        {
            return;
        }
        maxPathSumHelper(root->left, sum, max);
        sum += root->val;
        if (sum > max) max = sum;
        if (sum < 0) sum = 0;
        maxPathSumHelper(root->right, sum, max);
    }
};
```

This solution fails for the following test cases:

```
    4
   /
  2
 / \
1   3
```

Here, my solution returns `10` (i.e., 4+2+1+3 = 10). However, the correct answer should be `9` (i.e. 4+2+3 = 9)

Another test case:

```
          1
         / \
       -2   -3
       /\   /
      1  3 -2
     /
    -1
```

For this case, my solution returns `4` (i.e., 3+1 = 4). However, the correct answer should be `3` (i.e. 3 = 3).

My thoughts on my solution is to first using in-order traversal to represent the nodes in list and then invoke
[max subsequence sum](https://leetcode.com/problems/maximum-subarray/description/) solution, which should be $O(n)$.
However, my solution has an important caveat as the nodes in the maximum path have to be connected in parent-child fashion.
For example, for test case 1 above, in-order traversal gives `1,2,3,4` but notice `1` and `3` don't satisfy parent-child connection
requirement (i.e. they are peers). For test case 2, `3` and `1` don't meet the connection requirement because they are not connected
(`-2` is not included in the path). I'm kinda fooled by "does not need to go through the root" somehow.

The correct solution follows the bottom-up DFS approach. For any given node (i.e. `root`), we find out that the maximum
path includes such node. For a maximum path contains the given node, we recursively find the maximum path contains its left
child and right child by return the maximum path sums. Here, the connection ensured because `root` are connected with both `root->left` and `root->right`
and the recursion gives the maximum path contains left (right) child of the given node. We compare the recusion result
with 0 (i.e. `std::max(0, maxPathSumHelper(root->left, max))`) to ensure that in the worst case scenario when maximum
path contains left (right) child gives negative sum, we can ignore the left (right) child path.

As you might see from the description above, we construct a candidate maximum path (i.e. the path corresponding with the final answer)
by doing `left child path + root->val + right child path`. However, here we have to distinguish between the candidate maximum path
and the path to be part of the final maximum path. For the former one, ideally it should be constructed by
`left child path + root->val + right child path`. For the latter one, we have to return either `left child path + root->val`
or `right child path + root->val` to avoid the situation 4+2+1+3 = 10 in test case 1. In other words, we either choose `4,2,1`
or `4,2,3`. If we `return root->val + left + right`, we inevitably introduce 4+2+1+3 situation.

## Reference

- https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39869/Simple-O(n)-algorithm-with-one-traversal-through-the-tree
- https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/39775/Accepted-short-solution-in-Java