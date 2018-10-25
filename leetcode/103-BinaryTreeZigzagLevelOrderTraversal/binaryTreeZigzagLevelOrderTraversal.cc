/*************************************************************************
  > File Name:       binaryTreeZigzagLevelOrderTraversal.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/24/18
  > Description:
    
    C++ Solution
 ************************************************************************/


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include "cppinclude/bt.h"
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<vector<int>>
    zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        // level counting starts with 0 (i.e. root in level 0)
        bool evenLevel = true;
        if (root == nullptr)
        {
            return {};
        }
        q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            vector<int> tmp;
            for (int i = 0; i < len; ++i)
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
            if (evenLevel)
            {
                res.push_back(tmp);
                evenLevel = false;
            }
            else
            {
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
                evenLevel = true;
            }
        }
        return res;
    }
};

using ptr2zigzagLevelOrder = vector<vector<int>> (Solution::*)(TreeNode *);

void
test(ptr2zigzagLevelOrder pfcn)
{
    Solution sol;
    BT bt;
    auto root = bt.list2Tree(vector<int>() = {3, 9, 20, NULLPTR, NULLPTR, 15, 7});
    (sol.*pfcn)(root);
    // TODO: Add assertions
}

int
main()
{
    ptr2zigzagLevelOrder pfcn = &Solution::zigzagLevelOrder;
    test(pfcn);
}
