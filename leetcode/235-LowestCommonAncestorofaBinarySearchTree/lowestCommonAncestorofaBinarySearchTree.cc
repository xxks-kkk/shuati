//    Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
//
//    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//    Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]
//
//              _______6______
//             /              \
//        ___2__          ___8__
//       /      \        /      \
//      0      _4       7       9
//     /  \
//    3   5
//    Example 1:
//
//    Input: root, p = 2, q = 8
//    Output: 6
//    Explanation: The LCA of nodes 2 and 8 is 6.
//    Example 2:
//
//    Input: root, p = 2, q = 4
//    Output: 2
//    Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself
//        according to the LCA definition.


#include "bst.h"

class Solution
{
public:
    TreeNode *
    lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};

int
main()
{
    BST bst;
    Solution sol;
    std::vector<int> nums = {6, 2, 8, 0, 4, 7, 9, NULLPTR, NULLPTR, 3, 5};
    auto root = bst.list2Tree(nums);
    auto p = bst.find(root, 2);
    auto q = bst.find(root, 8);
    assert(sol.lowestCommonAncestor(root, p, q)->val == 6);
    p = bst.find(root, 2);
    q = bst.find(root, 4);
    assert(sol.lowestCommonAncestor(root, p, q)->val == 2);
    bst.freeTree(root);
}