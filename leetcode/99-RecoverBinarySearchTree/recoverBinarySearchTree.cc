//    Two elements of a binary search tree (BST) are swapped by mistake.
//
//    Recover the tree without changing its structure.
//
//    Example 1:
//
//    Input: [1,3,null,null,2]
//
//     1
//    /
//   3
//   \
//    2
//
//    Output: [3,1,null,null,2]
//
//     3
//    /
//   1
//   \
//    2
//    Example 2:
//
//    Input: [3,1,4,null,null,2]
//
//      3
//     / \
//    1   4
//       /
//      2
//
//    Output: [2,1,4,null,null,3]
//
//      2
//     / \
//    1   4
//       /
//      3
//    Follow up:
//
//    A solution using O(n) space is pretty straight forward.
//    Could you devise a constant space solution?

#include "bst.h"

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
    void recoverTree(TreeNode* root)
    {
        pre = nullptr;
        first = nullptr;
        second = nullptr;
        recoverTreeHelper(root);
        if (first && second)
        {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }

    // We use morris traversal to have constant space complexity
    void recoverTree2(TreeNode* root)
    {

    }

private:
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
    void recoverTreeHelper(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        recoverTreeHelper(root->left);
        if (first == nullptr && pre && pre->val > root->val)
        {
            first = pre;
        }
        if (first != nullptr && pre->val > root->val)
        {
            second = root;
        }
        pre = root;
        recoverTreeHelper(root->right);
    }
};

void test(void (Solution::*pf)(TreeNode*))
{
    BT bt;
    Solution sol;
    std::vector<int> nums = {1,3,NULLPTR,NULLPTR,2};
    auto root = bt.list2Tree(nums);
    (sol.*pf)(root);
    std::vector<int> ans = {3,1,NULLPTR,NULLPTR,2, NULLPTR, NULLPTR};
    assert(bt.tree2List(root) == ans);
    bt.freeTree(root);
    nums = {3,1,4,NULLPTR,NULLPTR,2};
    root = bt.list2Tree(nums);
    (sol.*pf)(root);
    ans = {2,1,4,NULLPTR,NULLPTR,3,NULLPTR,NULLPTR,NULLPTR};
    assert(bt.tree2List(root) == ans);
    bt.freeTree(root);
}

int main()
{
    void (Solution::*ptr2recoverTree)(TreeNode*);
    ptr2recoverTree = &Solution::recoverTree;
    test(ptr2recoverTree);
}