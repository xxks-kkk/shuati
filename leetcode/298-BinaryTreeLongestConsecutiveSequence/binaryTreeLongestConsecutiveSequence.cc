//    Given a binary tree, find the length of the longest consecutive sequence path.
//
//    The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
//
//    Example 1:
//
//    Input:
//
//       1
//        \
//         3
//        / \
//       2   4
//            \
//             5
//
//    Output: 3
//
//    Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
//    Example 2:
//
//    Input:
//
//        2
//         \
//         3
//        /
//       2
//      /
//     1
//
//    Output: 2
//
//    Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.

#include "bt.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // bottom-up DFS
    int longestConsecutive(TreeNode* root) {
        int max = 0;
        longestConsecutiveHelper(root, max);
        return max;
    }
    // top-down DFS
    int longestConsecutive2(TreeNode* root) {
        TreeNode *parent = nullptr;
        int length = 0;
        return dfs(root, parent, length);
    }
private:
    int longestConsecutiveHelper(TreeNode* & root, int & max)
    {
        int length;
        if(root == nullptr)
        {
            return 0;
        }
        auto left = longestConsecutiveHelper(root->left, max);
        auto right = longestConsecutiveHelper(root->right, max);
        if (root->left && root->left->val - root->val == 1 && root->right && root->right->val - root->val == 1)
        {
            length =  std::max(left, right) + 1;
        }
        else if (root->left && root->left->val - root->val == 1)
        {
            length = left + 1;
        }
        else if (root->right && root->right->val - root->val == 1)
        {
            length = right + 1;
        }
        else
        {
            // the cases including:
            // 1) no left & right nodes
            // 2) there are left or right subtrees but current node and its children don't
            // satisfy the "consecutive increasing (by 1) sequence" condition.
            // in either case, we only include the current node, which is 1.
            length = 1;
        }
        if (length > max) max = length;
        return length;
    }

    int dfs(TreeNode* & root, TreeNode* & parent, int length)
    {
        if (root == nullptr)
        {
            return length;
        }
        length = (parent != nullptr && root->val == parent->val + 1) ? length + 1: 1;
        return std::max(length, std::max(dfs(root->left, root, length), dfs(root->right, root, length)));
    }
};

using ptr2longestConsecutive = int(Solution::*)(TreeNode *);

void test(ptr2longestConsecutive pfcn)
{
    BT bt;
    Solution sol;
    std::vector<int> nums = {1,NULLPTR,3,2,4,NULLPTR,NULLPTR,NULLPTR,5};
    auto root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 3);
    bt.freeTree(root);
    nums = {2,NULLPTR,3,2,NULLPTR,1};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 2);
    bt.freeTree(root);
}

int main()
{
    ptr2longestConsecutive pfcn = &Solution::longestConsecutive;
    test(pfcn);
    pfcn = &Solution::longestConsecutive2;
    test(pfcn);
}