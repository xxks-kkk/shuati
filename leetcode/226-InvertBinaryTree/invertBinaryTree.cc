//    Invert a binary tree.
//
//    Example:
//
//    Input:
//
//       4
//      / \
//     2    7
//    / \   / \
//   1   3 6   9
//
//    Output:
//
//        4
//       /  \
//      7     2
//     / \   / \
//    9   6 3   1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "bst.h"
#include <cassert>
#include <vector>

using namespace std;

class Solution{
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
        {
            return root;
        }
        auto tmp = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = tmp;
        return root;
    }
};

using ptr2invertTree = TreeNode* (Solution::*)(TreeNode*);

void test(ptr2invertTree pfcn)
{
    Solution sol;
    BT bt;
    vector<int> nums = {4,2,7,1,3,6,9};
    auto root = bt.list2Tree(nums);
    auto res = (sol.*pfcn)(root);
    vector<int> res_vec = bt.tree2List(res);
    vector<int> ans = {4,7,2,9,6,3,1, NULLPTR, NULLPTR, NULLPTR, NULLPTR, NULLPTR, NULLPTR, NULLPTR, NULLPTR};
    assert(res_vec == ans);
}

int main()
{
    ptr2invertTree pfcn = &Solution::invertTree;
    test(pfcn);
}