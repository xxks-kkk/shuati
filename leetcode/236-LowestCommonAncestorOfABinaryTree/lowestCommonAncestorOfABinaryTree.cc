//    Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
//    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
//
//    Given the following binary search tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
//
//             _______3______
//            /              \
//        ___5__          ___1__
//       /      \        /      \
//      6      _2       0       8
//            /  \
//           7   4
//    Example 1:
//
//    Input: root, p = 5, q = 1
//    Output: 3
//    Explanation: The LCA of of nodes 5 and 1 is 3.
//    Example 2:
//
//    Input: root, p = 5, q = 4
//    Output: 5
//    Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
//        according to the LCA definition.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return (left && right) ? root : (left) ? left : right;
    }
};

int main()
{
    BT bt;
    Solution sol;
    std::vector<int> nums = {3,5,1,6,2,0,8,NULLPTR,NULLPTR,7,4};
    auto root = bt.list2Tree(nums);
    auto p = bt.find(root, 5);
    auto q = bt.find(root, 1);
    assert(sol.lowestCommonAncestor(root, p, q)->val == 3);
    p = bt.find(root, 5);
    q = bt.find(root, 4);
    assert(sol.lowestCommonAncestor(root, p, q)->val == 5);
    bt.freeTree(root);
    nums = {37,-34,-48,NULLPTR,-100,-100,48,NULLPTR,NULLPTR,NULLPTR,NULLPTR,-54,NULLPTR,-71,-22,NULLPTR,NULLPTR,NULLPTR,8};
    root = bt.list2Tree(nums);
    p = bt.findAll(root, -100)[1];
    q = bt.find(root, -71);
    assert(sol.lowestCommonAncestor(root, p, q)->val == -48);
    bt.freeTree(root);
}