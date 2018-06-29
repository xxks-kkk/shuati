//    You are given a binary tree in which each node contains an integer value.
//
//    Find the number of paths that sum to a given value.
//
//    The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
//
//    The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.
//
//    Example:
//
//    root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//          10
//         /  \
//        5   -3
//       / \    \
//      3   2   11
//     / \   \
//    3  -2   1
//
//    Return 3. The paths that sum to 8 are:
//
//    1.  5 -> 3
//    2.  5 -> 2 -> 1
//    3. -3 -> 11



/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

#include <bt.h>
#include <iostream>
#include <map>

class Solution
{
public:
    // Approach 1: nested DFS
    int
    pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return pathSumHelper(root, sum)
            + pathSum(root->left, sum)
            + pathSum(root->right, sum);
    }

    // Approach 2: O(n) solution using hash map
    int
    pathSum2(TreeNode *root, int sum)
    {
        std::map<int, int> preSum;
        preSum.emplace(0, 1);
        int count = 0;
        pathSum2Helper(root, 0, sum, preSum, count);
        return count;
    }
private:
    int
    pathSumHelper(TreeNode *root, int target)
    {
        int count = 0;
        if (root == nullptr)
        {
            return 0;
        }
        else if (target == root->val)
        {
            count += 1;
        }
        count += pathSumHelper(root->left, target - root->val);
        count += pathSumHelper(root->right, target - root->val);
        return count;
    }

    void
    pathSum2Helper(TreeNode *root, int currSum, int target, std::map<int, int> &preSum, int & count)
    {
        if (root == nullptr)
        {
            return;
        }
        currSum += root->val;
        if (preSum.count(currSum - target))
        {
            count += preSum.at(currSum - target);
        }
        if (preSum.find(currSum) == preSum.end())
        {
            preSum.emplace(currSum, 1);
        }
        else
        {
            preSum.emplace(currSum, preSum.at(currSum) + 1);
        }

        pathSum2Helper(root->left, currSum, target, preSum, count);
        pathSum2Helper(root->right, currSum, target, preSum, count);
        preSum[currSum] = preSum.at(currSum) - 1; // backtracking, just like DFS "1" is from there is one way to get currSum.
    }
};

using ptr2pathSum = int (Solution::*)(TreeNode *, int);

void
test(ptr2pathSum pfcn)
{
    BT bt;
    Solution sol;
    std::vector<int> nums = {10, 5, -3, 3, 2, NULLPTR, 11, 3, -2, NULLPTR, 1};
    auto root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root, 8) == 3);
    bt.freeTree(root);
    nums = {5, 4, 8, 11, NULLPTR, 13, 4, 7, 2, NULLPTR, NULLPTR, 5, 1};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root, 22) == 3);
    bt.freeTree(root);
    nums = {10, 5, -3, 3, 2, NULLPTR, 11, 3, -2, NULLPTR, 1};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root, 8) == 3);
    bt.freeTree(root);
}

int
main()
{
    ptr2pathSum pfcn = &Solution::pathSum;
    test(pfcn);
    pfcn = &Solution::pathSum2;
    test(pfcn);
}