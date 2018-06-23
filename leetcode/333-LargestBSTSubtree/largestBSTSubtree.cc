//    Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.
//
//    Note:
//    A subtree must include all of its descendants.
//    Here's an example:
//         10
//        / \
//       5  15
//      / \   \
//     1   8   7
//    The Largest BST Subtree in this case is the highlighted one.
//    The return value is the subtree's size, which is 3.
//    Follow up:
//    Can you figure out ways to solve it with O(n) time complexity?

#include "bt.h"
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int largestBSTSubtree(TreeNode* root) {
        TreeNode* lowerBound = nullptr;
        TreeNode* upperBound = nullptr;
        if(isValidBST(root, lowerBound, upperBound))
        {
            return count(root);
        }
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }

    int largestBSTSubtree2(TreeNode *root)
    {
        int upperbound = INT_MAX;
        int lowerbound = INT_MIN;
        int size = 0;
        isValidBST2(root, upperbound, lowerbound, size);
        return size;
    }
private:

    int count(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        return 1 + count(root->left) + count(root->right);
    }

    bool isValidBST(TreeNode* root, TreeNode* & lowerBound , TreeNode* & upperBound)
    {
        if (root == nullptr)
        {
            return true;
        }
        if ((lowerBound && root->val <= lowerBound->val) ||
            (upperBound && root->val >= upperBound->val))
        {
            return false;
        }
        return isValidBST(root->left, lowerBound, root) && isValidBST(root->right, root, upperBound);
    }

    void isValidBST2(TreeNode *root, int & upperbound, int & lowerbound, int & size)
    {
        if (root == nullptr)
        {
            return;
        }
        int left_upperbound = INT_MAX;
        int left_lowerbound = INT_MIN;
        int right_upperbound = INT_MAX;
        int right_lowerbound = INT_MIN;
        int left_size = 0;
        int right_size = 0;
        isValidBST2(root->left, left_upperbound, left_lowerbound, left_size);
        isValidBST2(root->right, right_upperbound, right_lowerbound, right_size);
        if ((!root->left || left_upperbound < root->val) && (!root->right || right_lowerbound > root->val))
        {
            size = left_size + right_size + 1;
            lowerbound = (root->left) ? left_lowerbound : root->val;
            upperbound = (root->right) ? right_upperbound : root->val;
        }
        else size = max(left_size, right_size);
    }
};

using ptr2largestBSTSubtree = int (Solution::*)(TreeNode*);

void test(ptr2largestBSTSubtree pfcn)
{
    Solution sol;
    BT bt;
    vector<int> nums = {10,5,15,1,8,NULLPTR,7};
    auto root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 3);
    bt.freeTree(root);
}

int main()
{
    ptr2largestBSTSubtree pfcn = &Solution::largestBSTSubtree;
    test(pfcn);
    pfcn = &Solution::largestBSTSubtree2;
    test(pfcn);
}