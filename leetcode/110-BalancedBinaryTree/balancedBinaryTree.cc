//    Given a binary tree, determine if it is height-balanced.
//
//    For this problem, a height-balanced binary tree is defined as:
//
//    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//    Example 1:
//
//    Given the following tree [3,9,20,null,null,15,7]:
//
//        3
//       / \
//      9  20
//        /  \
//       15   7
//    Return true.
//
//    Example 2:
//
//    Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
//    Return false.

#include <stdlib.h>  /* abs */
#include <algorithm> /* max */
#include <vector>
#include <queue>
#include <assert.h>

#define NULLPTR (-999)

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BT
{
public:
    TreeNode*
    list2Tree(std::vector<int> & nums)
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
    printTree(TreeNode *root)
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
    freeTree(TreeNode *root)
    {
        if(root)
        {
            freeTree(root->left);
            freeTree(root->right);
            delete root;
        }
    }
};

struct BalancedStatusWithHeight
{
    bool balanced;
    int height;
};

class Solution
{
public:
    bool
    isBalanced(TreeNode *root)
    {
        return checkBalanced(root).balanced;
    }
private:
    BalancedStatusWithHeight
    checkBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {true, -1};
        }
        auto left_result = checkBalanced(root->left);
        if (!left_result.balanced)
        {
            return {false, 0};
        }
        auto right_result = checkBalanced(root->right);
        if (!right_result.balanced)
        {
            return {false, 0};
        }
        bool is_balanced = abs(left_result.height - right_result.height) <= 1;
        int height = std::max(left_result.height, right_result.height) + 1;
        return {is_balanced, height};
    }
};

int main()
{
    BT bt;
    Solution sol;
    std::vector<int> nums = {3,9,20,NULLPTR,NULLPTR,15,7};
    auto root = bt.list2Tree(nums);
    assert(sol.isBalanced(root));
    bt.freeTree(root);
    nums = {1,2,2,3,3,NULLPTR,NULLPTR,4,4};
    root = bt.list2Tree(nums);
    assert(!sol.isBalanced(root));
    bt.freeTree(root);
}