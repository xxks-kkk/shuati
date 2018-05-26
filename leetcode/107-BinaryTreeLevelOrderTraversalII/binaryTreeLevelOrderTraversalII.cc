//    Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//    For example:
//    Given binary tree [3,9,20,null,null,15,7],
//        3
//       / \
//      9  20
//        /  \
//       15   7
//    return its bottom-up level order traversal as:
//    [
//    [15,7],
//    [9,20],
//    [3]
//    ]

#include "bt.h"
#include <queue>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        std::queue<TreeNode *> q;
        unsigned long length = 0;
        if(root == nullptr)
        {
            return res;
        }
        q.push(root);
        while(!q.empty())
        {
            length = q.size();
            vector<int> tmp;
            int i = 0;
            while (i < length)
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
                ++i;
            }
            res.insert(res.begin(),tmp);
        }
        return res;
    }
};

using ptr2levelOrderBottom = vector<vector<int>> (Solution::*)(TreeNode*);

void test(ptr2levelOrderBottom pfcn)
{
    Solution sol;
    BT bt;
    vector<int> nums = {3,9,20,NULLPTR,NULLPTR,15,7};
    auto root = bt.list2Tree(nums);
    std::vector<std::vector<int>> ans = {{15,7},{9,20},{3}};
    assert((sol.*pfcn)(root) == ans);
    bt.freeTree(root);
}

int main()
{
    ptr2levelOrderBottom pfcn = &Solution::levelOrderBottom;
    test(pfcn);
}