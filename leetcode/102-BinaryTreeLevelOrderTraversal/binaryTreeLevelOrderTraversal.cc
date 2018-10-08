//    Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
//
//    For example:
//    Given binary tree [3,9,20,null,null,15,7],
//       3
//      / \
//      9  20
//        /  \
//       15   7
//    return its level order traversal as:
//    [
//    [3],
//    [9,20],
//    [15,7]
//    ]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <queue>
#include <cassert>
#include "bt.h"
#include "cpputility.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>>
    levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        queue<TreeNode *> q;
        vector<vector<int>> res;
        int depth = 0;
        int len = 0;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tmp;
            // invariant: the number of the nodes for the current level
            int cnt = q.size();
            for (int i = 0; i < cnt; ++i)
            {
                auto node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};

using ptr2levelOrder = vector<vector<int>> (Solution::*)(TreeNode *);

void
test(ptr2levelOrder pfcn)
{
    Solution sol;
    BT bt;
    vector<int> nums = {3, 9, 20, NULLPTR, NULLPTR, 15, 7};
    auto root = bt.list2Tree(nums);
    auto res = (sol.*pfcn)(root);
    CPPUtility::print2DVector(res);
    vector<vector<int>> ans = {{3}, {9,20}, {15,7}};
    assert(res == ans);
}

int
main()
{
    ptr2levelOrder pfcn = &Solution::levelOrder;
    test(pfcn);
}