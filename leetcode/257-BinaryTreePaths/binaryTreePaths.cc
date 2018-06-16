//Given a binary tree, return all root-to-leaf paths.
//
//Note: A leaf is a node with no children.
//
//Example:
//
//Input:
//
//   1
// /   \
//2     3
// \
//  5
//
//Output: ["1->2->5", "1->3"]
//
//Explanation: All root-to-leaf paths are: 1->2->5, 1->3

#include "bt.h"
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root != nullptr)
        {
            binaryTreePathsHelper(root, res, "");
        }
        return res;
    }
private:
    void binaryTreePathsHelper(TreeNode* root, vector<string> & res, string tmp)
    {
        if (!root->left && !root->right)
        {
            tmp += to_string(root->val);
            res.push_back(tmp);
        }
        tmp += to_string(root->val) + "->";
        if (root->left != nullptr)
        {
            binaryTreePathsHelper(root->left, res, tmp);
        }
        if (root->right != nullptr)
        {
            binaryTreePathsHelper(root->right, res, tmp);
        }
    }
};

using ptr2binaryTreePaths = vector<string> (Solution::*)(TreeNode*);

void test(ptr2binaryTreePaths pfcn)
{
    Solution sol;
    BT bt;
    vector<int> nums = {1,2,3,NULLPTR,5};
    auto root = bt.list2Tree(nums);
    vector<string> ans = {"1->2->5", "1->3"};
    assert((sol.*pfcn)(root) == ans);
    bt.freeTree(root);
    nums = {1};
    root = bt.list2Tree(nums);
    ans = {"1"};
    assert((sol.*pfcn)(root) == ans);
}


int main()
{
    ptr2binaryTreePaths pfcn = &Solution::binaryTreePaths;
    test(pfcn);
}