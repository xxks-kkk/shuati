//        Given a binary tree, count the number of uni-value subtrees.
//
//        A Uni-value subtree means all nodes of the subtree have the same value.
//
//        Example :
//
//        Input:  root = [5,1,5,5,5,null,5]
//
//                      5
//                     / \
//                    1   5
//                   / \   \
//                  5   5   5
//
//        Output: 4

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
    int countUnivalSubtrees(TreeNode* root) {
        int cnt = 0;
        countUnivalSubtreesHelper(root, cnt);
        return cnt;
    }
private:
    bool countUnivalSubtreesHelper(TreeNode* root, int & cnt) {
        if (root == nullptr)
        {
            return true;
        }
        bool isLeftUnival = countUnivalSubtreesHelper(root->left, cnt);
        bool isRightUnival = countUnivalSubtreesHelper(root->right, cnt);
        if (isLeftUnival && isRightUnival && (
            (root->left && root->right && root->left->val == root->right->val && root->val == root->left->val) ||
            (!root->left && root->right && root->val == root->right->val) ||
            (!root->right && root->left && root->val == root->left->val) ||
            (!root->left && !root->right)))
        {
            cnt += 1;
            return true;
        }
        return false;
    }
};

using ptr2countUnivalSubtrees = int (Solution::*)(TreeNode *);

void test(ptr2countUnivalSubtrees pfcn)
{
    Solution sol;
    BT bt;
    std::vector<int> nums = {5,1,5,5,5,NULLPTR,5};
    auto root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 4);
    bt.freeTree(root);
    nums = {-79, NULLPTR, -79, 97, NULLPTR};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root) == 1);
    bt.freeTree(root);
}

int main()
{
    ptr2countUnivalSubtrees pfcn = &Solution::countUnivalSubtrees;
    test(pfcn);
}