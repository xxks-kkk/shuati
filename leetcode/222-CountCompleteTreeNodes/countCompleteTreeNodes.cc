//    Given a complete binary tree, count the number of nodes.
//
//    Note:
//
//    Definition of a complete binary tree from Wikipedia:
//    In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//
//    Example:
//
//    Input:
//         1
//       /  \
//      2    3
//     / \  /
//    4  5 6
//
//    Output: 6

#include "bt.h"
#include <queue>
#include <cmath>
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
    // Naive approach, get TLE
    int countNodes(TreeNode* root) {
        int cnt = 0;
        std::queue<TreeNode *> q;
        if (root == nullptr)
        {
            return cnt;
        }
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            ++cnt;
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return cnt;
    }

    // Second attempt, get TLE as well
    int countNodes2(TreeNode* root)
    {
        int cnt = 0;
        int height = 0;
        auto current = root;
        if(root == nullptr)
        {
            return 0;
        }
        if(!root->left && !root->right)
        {
            return 1;
        }
        while(current->left)
        {
            height++;
            current = current->left;
        }
        cnt += countNodes2Helper(root, height, 0);
        cnt += pow(2,height) - 1;
        return cnt;
    }

    // Third attempt, AC
    int countNodes3(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        auto leftPointer = root, rightPointer = root;
        int leftDepth = 0, rightDepth = 0;
        while(leftPointer->left)
        {
            leftDepth ++;
            leftPointer = leftPointer->left;
        }
        while(rightPointer->right)
        {
            rightDepth ++;
            rightPointer = rightPointer->right;
        }
        if(leftDepth == rightDepth)
        {
            return (int)pow(2,leftDepth+1) - 1;
        }
        return 1 + countNodes3(root->left) + countNodes3(root->right);
    }

private:
    int countNodes2Helper(TreeNode* root, const int height, int && i)
    {
        int cnt = 0;
        if(root == nullptr)
        {
            return 0;
        }
        if (i == height - 1)
        {
            if(root->left && root->right) return 2;
            if((root->left && !root->right) || (!root->left && root->right)) return 1;
            else return 0;
        }
        cnt += countNodes2Helper(root->left, height, i+1);
        cnt += countNodes2Helper(root->right, height, i+1);
        return cnt;
    }
};


using ptr2countNodes = int (Solution::*)(TreeNode*);

void test(ptr2countNodes pfcn)
{
    Solution sol;
    BT bt;
    std::vector<int> nums = {1,2,3,4,5,6};
    auto root = bt.list2Tree(nums);
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    assert((sol.*pfcn)(root) == 6);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "duration (ms): " << duration << std::endl;
    bt.freeTree(root);
}

int main()
{

    ptr2countNodes pfcn = &Solution::countNodes;
    test(pfcn);
    pfcn = &Solution::countNodes2;
    test(pfcn);
    pfcn = &Solution::countNodes3;
    test(pfcn);
}
