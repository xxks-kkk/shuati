#include "bt.h"

TreeNode *
BT::list2Tree(std::vector<int> &nums)
{
    if (!nums.empty())
    {
        std::deque<TreeNode *> queue;
        auto root = new TreeNode(nums[0]);
        queue.push_front(root);
        int i = 1;
        while (!queue.empty() && i < nums.size())
        {
            auto node = queue.back();
            queue.pop_back();
            if (node)
            {
                if (nums[i] != NULLPTR)
                {
                    auto left = new TreeNode(nums[i]);
                    node->left = left;
                    queue.push_front(left);
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
                        queue.push_front(right);
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
        std::deque<TreeNode *> queue;
        queue.push_front(root);
        while (!queue.empty())
        {
            std::vector<int> path;
            auto levelLength = queue.size();
            for (int i = 0; i < levelLength; ++i)
            {
                auto node = queue.back();
                queue.pop_back();
                path.push_back(node->val);
                if (node->left)
                {
                    queue.push_front(node->left);
                }
                if (node->right)
                {
                    queue.push_front(node->right);
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
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

TreeNode *
BT::find(TreeNode *root, int val)
{
    if (root)
    {
        if (root->val == val)
        {
            return root;
        }
        auto res1 = find(root->left, val);
        return (res1 == nullptr) ? find(root->right, val) : res1;
    }
    return nullptr;
}

std::vector<TreeNode *>
BT::findAll(TreeNode *root, int val)
{
    std::vector<TreeNode *> res;
    std::deque<TreeNode *> queue;
    queue.push_front(root);
    while (!queue.empty())
    {
        auto node = queue.back();
        queue.pop_back();
        if (node)
        {
            if (node->val == val)
            {
                res.push_back(node);
            }
            queue.push_front(node->left);
            queue.push_front(node->right);
        }
    }
    return res;
}