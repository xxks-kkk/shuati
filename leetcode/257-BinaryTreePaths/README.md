## Solution explanation

My not very optimized solution below:

```cpp
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root != nullptr)
        {
            string tmp;
            binaryTreePathsHelper(root, res, tmp);
        }
        return res;
    }
private:
    void binaryTreePathsHelper(TreeNode* root, vector<string> & res, string tmp)
    {
        if (root == nullptr)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            tmp.empty() ? tmp += to_string(root->val): tmp += "->" + to_string(root->val);
            res.push_back(tmp);
        }
        else
        {
            binaryTreePathsHelper(root->left, res, tmp.empty() ? tmp + to_string(root->val): tmp + "->" + to_string(root->val));
            binaryTreePathsHelper(root->right, res, tmp.empty() ? tmp + to_string(root->val): tmp + "->" + to_string(root->val));
        }
    }
};
```

Provided solution is optimized in following ways:

- We get rid of `string tmp` and directly pass in `""` to `binaryTreePathsHelper` instead.
- We check whether `root->left` and `root->right` arr `nullptr` to make sure `root` can never be `nullptr` in the recursive calls.
Thus, we get rid of `if (root == nullptr)` checking condition.
- We construct the `tmp` string via `tmp += to_string(root->val) + "->"` so that there is no long input like
`tmp.empty() ? tmp + to_string(root->val): tmp + "->" + to_string(root->val)`.