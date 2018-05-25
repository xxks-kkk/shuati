//    Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
//
//    Example:
//    Given binary tree
//              1
//             / \
//            2   3
//           / \
//          4  5
//    Returns [4, 5, 3], [2], [1].
//
//    Explanation:
//    1. Removing the leaves [4, 5, 3] would result in this tree:
//
//          1
//         /
//        2
//    2. Now removing the leaf [2] would result in this tree:
//
//    1
//    3. Now removing the leaf [1] would result in the empty tree:
//
//    []
//    Returns [4, 5, 3], [2], [1].

#include <queue>
#include "bt.h"
#include <iostream>

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        findLeavesHelper(root, res);
        return res;
    }
private:
    // return the height of the given node
    int findLeavesHelper(TreeNode* & root, vector<vector<int>> & res)
    {
        if(root == nullptr)
        {
            return -1;
        }
        int height = 1 + max(findLeavesHelper(root->left, res), findLeavesHelper(root->right, res));
        if (res.size() == height)
        {
            vector<int> tmp;
            res.push_back(tmp);
        }
        res[height].push_back(root->val);
        return height;
    }
};

using ptr2findLeaves = vector<vector<int>> (Solution::*)(TreeNode*);

void test(ptr2findLeaves pfcn)
{
    Solution sol;
    BT bt;
    std::vector<int> nums = {1,2,3,4,5};
    auto root = bt.list2Tree(nums);
    std::vector<std::vector<int>> ans = {{4,5,3},{2},{1}};
    assert((sol.*pfcn)(root) == ans);
}

int main()
{
    ptr2findLeaves pfcn = &Solution::findLeaves;
    test(pfcn);
}