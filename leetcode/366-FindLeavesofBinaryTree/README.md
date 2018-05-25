## Solution explanation

Once I read through the questions, my initial thought is to do level-order traversal using queue because we want to
group the leaves on the same "level" in a vector and append it to the final 2D vector. I use two queues to know when
to append the group into final result vector. The following is my failure code:

```cpp
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> tmp;
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;
        if(root == nullptr)
        {
            return res;
        }
        if(root->right || root->left)
        {
            q1.push(root);
        }
        else
        {
            tmp.push_back(root->val);
            res.push_back(tmp);
            return res;
        }
        while(!q1.empty())
        {
            auto node = q1.front();
            q1.pop();
            std::cout << "node: " << node->val << endl;
            if(node->left && !node->left->left && !node->left->right)
            {
                tmp.push_back(node->left->val);
                delete(node->left);
                node->left = nullptr;
            }
            if(node->right && !node->right->left && !node->right->right)
            {
                tmp.push_back(node->right->val);
                delete(node->right);
                node->right = nullptr;
            }
            if (node->left)
            {
                q1.push(node->left);
                std::cout << "node's left: " << node->left->val <<endl;
            }
            if (node->right)
            {
                q1.push(node->right);
                std::cout << "node's right: " << node->right->val <<endl;
            }
            q2.push(node);
            if(q1.empty() && !q2.empty())
            {
                swap(q1,q2);
                res.push_back(tmp);
                tmp.clear();
            }
        }
        return res;
    }
};
```

The above code is broken and won't compile. By writing this code, I realize that the leaves within the same group
has to be ordered from left to right in the same order as their appearance in the tree. For the given example, for the first
group, we have to have `[4,5,3]` NOT `[3,4,5]`. This ordering is not easily achievable in the level-order traversal and
the ordering is a hint to use DFS instead, which guarantees the leftmost leaf will always appear as the first element
of each group.

However, we still want to have "level" property provided by level-order traversal in the sense that we want to group
all the leaves on the same "level" into the same vector. The key here is to define the "level" of leaves, which can
be done using the definition of height: the height of a node is the number of edges from the node to the deepest leaf.
Thus, all the leaves for a given tree have the height 0. For the given example, if we categorize each node by its height
we can get: [4,5,3] all have the height 0, [2] has height 1, and [1] has height 2. These three groups form the exactly
groups as the problem expects. Then, the solution derives naturally.


## Reference

- https://leetcode.com/problems/find-leaves-of-binary-tree/discuss/83778/10-lines-simple-Java-solution-using-recursion-with-explanation