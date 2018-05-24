## Solution explanation

Let me present my failed attempt first

```cpp
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int left = countUnivalSubtrees(root->left);
        int right = countUnivalSubtrees(root->right);
        if ((root->left && root->right && root->left->val == root->right->val && root->val == root->left->val) ||
            (!root->left && !root->right) ||
            (!root->left && root->right && root->right->val == root->val) ||
            (!root->right && root->left && root->left->val == root->val))
        {
                return left + right + 1;
        }
        return left + right;
    }
};
```

The above solution fails the following test case:

```
  -79
    \
    -79
    /
   97
```

The correct answer for this one is `1` (i.e. 97) but my failed solution gives `2`. Why is that? The above solution is
no hard to understand. For `-79,97` subtree, our code correctly identify the answer is `1`, which comes from the leaf `97`.
But, for `-79,-79,97` tree, since root's `-79` equals its child's `-79` and the recursive call for root's left child gives
`0` and right child for `1` and our code treats the case as if it were `-79,97` subtree and add `1` to `1` (i.e. right child) and leads to `2`.
However, as you can see, `-79,-79,97` doesn't satisfy the uni-value subtree definiton but we treat it is because
the code cannot distinguish between the subtree contains leaves and the tree contains non-leaves but the recursion result happens
to be `1`. In other words, code thinks left child's 0 and right child's 1 as the subtree containing leaves, which may not be true.

To further illustrate the point above, the following code is equivalent as above and fail the same test case:

```cpp
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int left = countUnivalSubtrees(root->left);
        int right = countUnivalSubtrees(root->right);
        if (left == right && left == 0)
            return left + right + 1;
        if (left == 0 && right == 1)
            return (root->right->val == root->val) ? left + right + 1 : right;
        if (left == 1 && right == 0)
            return (root->left->val == root->val) ? left + right + 1 : left;
        if (left >= 1 && right >= 1 && root->left->val == root->right->val && root->right->val == root->val)
            return left + right + 1;
        return left + right;
    }
};
```

That's why we need to use a helper class with return `bool` to help us identify whether we have uni-val subtree for
left and right child of a given node. For the test case above, `-79,97` clearly is not a uni-value subtree but
the leaf `97` itself is a uni-value subtree. Thus, we can use a `bool` to distinguish previous two situations. Thus,
to keep track of counting, we need to pass in a `cnt` variable as parameter to helper function. From another perspective,
those checking if-conditions only make sense when both left and right subtrees are uni-value, which we cannot guarantee
from failed attempts (i.e., doing the count only is not enough).


## Reference

- https://leetcode.com/problems/count-univalue-subtrees/discuss/67612/C++-one-pass-recursive-solution