//
//    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
//
//    For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//    Example:
//
//    Given the sorted array: [-10,-3,0,5,9],
//
//    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
//
//          0
//         / \
//       -3   9
//       /   /
//    -10  5


#include "bst.h"

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
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        int start = 0;
        int end = (int) nums.size();
        sortedArrayBSTHelper(nums, start, end, root);
        return root;
    }
private:
    void sortedArrayBSTHelper(vector<int>& nums, const int start, const int end, TreeNode* & root)
    {
        int length = end - start;
        if (length == 0)
        {
            return;
        }
        int pivotPos = start + length / 2;
        insert(root, nums[pivotPos]);
        sortedArrayBSTHelper(nums, start, pivotPos, root->left);
        sortedArrayBSTHelper(nums, pivotPos+1, end, root->right);
    }

    void insert(TreeNode* & root, int & val)
    {
        if(root == nullptr)
        {
            root = new TreeNode(val);
        }
        if(val < root->val)
        {
            insert(root->left, val);
        }
        if(val > root->val)
        {
            insert(root->right, val);
        }
    }
};

using ptr2sortedArrayToBST = TreeNode* (Solution::*)(vector<int>&);

void test(ptr2sortedArrayToBST pfcn)
{
    Solution sol;
    BT bt;
    vector<int> nums = {-10, -3, 0, 5, 9};
    vector<int> ans = {0, -3, 9, -10, NULLPTR, 5, NULLPTR, NULLPTR, NULLPTR, NULLPTR, NULLPTR};
    auto root = sol.sortedArrayToBST(nums);
    assert(bt.tree2List(root) == ans);
    bt.freeTree(root);
}

int main()
{
    ptr2sortedArrayToBST pfcn = &Solution::sortedArrayToBST;
    test(pfcn);
}