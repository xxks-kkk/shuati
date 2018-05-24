//    Given a non-empty binary tree, find the maximum path sum.
//
//    For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
//    Example 1:
//
//    Input: [1,2,3]
//
//           1
//          / \
//         2   3
//
//    Output: 6
//    Example 2:
//
//    Input: [-10,9,20,null,null,15,7]
//
//       -10
//       / \
//      9  20
//        /  \
//       15   7
//
//    Output: 42

#include "bt.h"
#include <limits>

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
    int maxPathSum(TreeNode* root) {
        int max = std::numeric_limits<int>::min();
        maxPathSumHelper(root, max);
        return max;
    }
private:
    // return the maximum (sub)path contains the given node `root`
    int maxPathSumHelper(TreeNode* & root, int & max) {
        if(root == nullptr)
        {
            return 0;
        }
        int left = std::max(0, maxPathSumHelper(root->left, max));
        int right = std::max(0, maxPathSumHelper(root->right, max));
        // we construct a candidate maximum path and see if we beat the current max
        if(left + right + root->val > max)
        {
            max = left + right + root->val;
        }
        // we return the maximum (sub)path for the given node: either `left child path + root->val`
        // or `right child path + root->val` but NOT `left child path + right child path + root->val`,
        // which violate the question connection requirement.
        return root->val + std::max(left,right);
    }
};

using ptr2maxPathSum = int (Solution::*)(TreeNode *);

void test(ptr2maxPathSum pfcn)
{
    Solution sol;
    BT bt;
    std::vector<int> nums = {1,2,3};
    auto root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 6);
    bt.freeTree(root);
    nums = {-10,9,20,NULLPTR,NULLPTR,15,7};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 42);
    bt.freeTree(root);
    nums = {-3};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == -3);
    bt.freeTree(root);
    nums = {1,-2,-3,1,3,-2,NULLPTR,-1};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 3);
    bt.freeTree(root);
    nums = {4,2,NULLPTR,1,3};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 9);
    bt.freeTree(root);
}

int main()
{
    ptr2maxPathSum pfcn = &Solution::maxPathSum;
    test(pfcn);
}