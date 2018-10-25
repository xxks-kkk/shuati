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
#include "cppinclude/bt.h"

using namespace std;

class Solution
{
public:
    vector<TreeNode *>
    generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }
        return generateTreesHelper(1, n);
    }
private:
    vector<TreeNode*> generateTreesHelper(int start, int end)
    {
        vector<TreeNode*> res;
        if (start > end)
        {
            res.push_back(nullptr);
        }
        for (int i = start; i < end + 1; ++i)
        {
            auto left_roots = generateTreesHelper(start, i-1);
            auto right_roots = generateTreesHelper(i+1, end);
            for (auto & left_root : left_roots)
            {
                for (auto& right_root: right_roots)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left_root;
                    root->right = right_root;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

using ptr2generateTrees = vector<TreeNode *> (Solution::*)(int);

void test(ptr2generateTrees pfcn)
{
    Solution sol;
    // TODO: Add assertions
    (sol.*pfcn)(3);
}

int main()
{
    ptr2generateTrees pfcn = &Solution::generateTrees;
    test(pfcn);
}