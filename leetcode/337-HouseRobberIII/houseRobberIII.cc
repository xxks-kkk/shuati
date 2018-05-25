//    The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
//    Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//    Example 1:
//         3
//        / \
//       2   3
//        \   \
//         3   1
//    Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//    Example 2:
//          3
//        / \
//       4   5
//      / \   \
//     1   3   1
//    Maximum amount of money the thief can rob = 4 + 5 = 9.

#include "bt.h"
#include <chrono>
#include <iostream>

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
    int rob(TreeNode* root) {
        int res1, res2;
        if (root == nullptr)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return root->val;
        }
        res1 = rob(root->left) + rob(root->right);
        res2 = root->val;
        if (root->left)
        {
            res2 += (rob(root->left->left) + rob(root->left->right));
        }
        if (root->right)
        {
            res2 += (rob(root->right->left) + rob(root->right->right));
        }
        return std::max(res1,res2);
    }

    // Better optimized version than rob (see execution time difference on the test case)
    int rob2(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
private:
    int tryRob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;

        // here,
        // ll := root->left->left
        // lr := root->left->right
        // rl := root->right->left
        // rr := root->right->right
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);

        return std::max(root->val + ll + lr + rl + rr, l + r);
    }
};

using ptr2rob = int (Solution::*)(TreeNode *);

void test(ptr2rob pfcn)
{
    Solution sol;
    BT bt;
    std::vector<int> nums = {3,2,3,NULLPTR,3,NULLPTR,1};
    auto root = bt.list2Tree(nums);
    assert(sol.rob(root) == 7);
    bt.freeTree(root);
    nums = {3,4,5,1,3,NULLPTR,1};
    root = bt.list2Tree(nums);
    assert(sol.rob(root) == 9);
    bt.freeTree(root);
    nums = {1};
    root = bt.list2Tree(nums);
    assert(sol.rob(root) == 1);
    bt.freeTree(root);
}

int main()
{
    ptr2rob pfcn = &Solution::rob;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    test(pfcn);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "rob duration (ms): " << duration << std::endl;

    pfcn = &Solution::rob2;
    t1 = std::chrono::high_resolution_clock::now();
    test(pfcn);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "rob2 duration (ms): " << duration << std::endl;
}