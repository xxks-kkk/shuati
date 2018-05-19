#include "bt.h"

TreeNode*
BT::list2Tree(std::vector<int> & nums)
{
    if (!nums.empty())
    {
        std::queue<TreeNode*> queue;
        auto root = new TreeNode(nums[0]);
        queue.push(root);
        int i = 1;
        while (!queue.empty() && i < nums.size())
        {
            auto node = queue.back();
            queue.pop();
            if (node)
            {
                if (nums[i] != NULLPTR)
                {
                    auto left = new TreeNode(nums[i]);
                    node->left = left;
                    queue.push(left);
                }
                else
                {
                    node->left = nullptr;
                }
                ++i;
                if (i < nums.size())
                {
                    if (nums[i] != NULLPTR)
                    {
                        auto right = new TreeNode(nums[i]);
                        node->right = right;
                        queue.push(right);
                    }
                    else
                    {
                        node->right = nullptr;
                    }
                    ++i;
                }
            }
        }
        return root;
    }
    return nullptr;
}

std::vector<std::vector<int>>
BT::printTree(TreeNode *root)
{
    std::vector<std::vector<int>> res;
    if (root != nullptr)
    {
        std::queue<TreeNode *> queue;
        queue.push(root);
        while(!queue.empty())
        {
            std::vector<int> path;
            auto levelLength = queue.size();
            for(int i = 0; i < levelLength; ++i)
            {
                auto node = queue.back();
                queue.pop();
                path.push_back(node->val);
                if (node->left)
                {
                    queue.push(node->left);
                }
                if (node->right)
                {
                    queue.push(node->right);
                }
            }
            res.push_back(path);
        }
    }
    return res;
}

void
BT::freeTree(TreeNode *root)
{
    if(root)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}