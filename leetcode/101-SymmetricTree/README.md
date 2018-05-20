## Solution Explanation

The following code is the original version:

```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root)
        {
            return isSymmetricHelper(root->left, root->right);
        }
        else
        {
            return true;
        }
    }
private:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
            return true;
        if ((!left && right) || (left && !right))
            return false;
        else
        {
            if (left->val == right->val)
            {
                auto res1 = isSymmetricHelper(left->left, right->right);
                if (!res1)
                    return false;
                auto res2 = isSymmetricHelper(left->right, right->left);
                if (!res2)
                    return false;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};
```

## Reference

- Elements of Programming Interview 9.2