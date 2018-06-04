//    Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
//    Note:
//
//    Given target value is a floating point.
//    You are guaranteed to have only one unique value in the BST that is closest to the target.
//    Example:
//
//    Input: root = [4,2,5,1,3], target = 3.714286
//
//        4
//       / \
//      2   5
//     / \
//    1   3
//
//    Output: 4

#include "bst.h"
#include <cmath>
#include <limits>
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
    // naive solution; doesn't leverage the BST assumption
    int closestValue(TreeNode* root, double target) {
        double max = std::numeric_limits<double>::max();
        int candidate = 0;
        closestValueHelper(root, target, max, candidate);
        return candidate;
    }

    int closestValue2(TreeNode* root, double target) {
        int candidate = root->val;
        auto current = root;
        while(current)
        {
            if(fabs(current->val - target) < fabs(candidate - target))
            {
                candidate = current->val;
            }
            current = current->val > target ? current->left : current->right;
        }
        return candidate;
    }
private:
    void closestValueHelper(TreeNode* & root, double & target, double & max, int & candidate)
    {
        if(root == nullptr)
        {
            return;
        }
        double tmp = fabs(root->val - target);
        if (tmp < max)
        {
            candidate = root->val;
            max = tmp;
        }
        closestValueHelper(root->left, target, max, candidate);
        closestValueHelper(root->right, target, max, candidate);
    }
};

using ptr2closestValue = int (Solution::*)(TreeNode*, double);

void test(ptr2closestValue pfcn)
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    BST bst;
    Solution sol;
    std::vector<int> nums = {4,2,5,1,3};
    auto root = bst.list2Tree(nums);
    double target = 3.714286;
    assert((sol.*pfcn)(root, target) == 4);
    bst.freeTree(root);
    nums = {1500000000,1400000000};
    target = -1500000000.0;
    root = bst.list2Tree(nums);
    assert((sol.*pfcn)(root, target) == 1400000000);
    bst.freeTree(root);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "duration (ms): " << duration << std::endl;
}

int main()
{
    ptr2closestValue pfcn = &Solution::closestValue;
    test(pfcn);
    pfcn = &Solution::closestValue2;
    test(pfcn);
}