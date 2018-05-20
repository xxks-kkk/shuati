//    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//    For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//       1
//      / \
//     2   2
//    / \ / \
//   3  4 4  3
//    But the following [1,2,2,null,3,null,3] is not:
//       1
//      / \
//     2   2
//      \   \
//      3    3
//    Note:
//    Bonus points if you could solve it both recursively and iteratively.

#include "bt.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        return !root || isSymmetricHelper(root->left, root->right);
    }
private:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
            return true;
        else if (left && right)
            return left->val == right->val &&
                isSymmetricHelper(left->left, right->right) &&
                isSymmetricHelper(left->right, right->left);
        return false; // one subtree is empty, and the other is not
    }
};

int
main()
{
    BT bt;
    Solution sol;
    std::vector<int> nums = {1,2,2,3,4,4,3};
    auto root = bt.list2Tree(nums);
    assert(sol.isSymmetric(root));
    bt.freeTree(root);
    nums = {1,2,2,NULLPTR,3,NULLPTR,3};
    root = bt.list2Tree(nums);
    assert(!sol.isSymmetric(root));
    bt.freeTree(root);
}