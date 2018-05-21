//    Two elements of a binary search tree (BST) are swapped by mistake.
//
//    Recover the tree without changing its structure.
//
//    Example 1:
//
//    Input: [1,3,null,null,2]
//
//     1
//    /
//   3
//   \
//    2
//
//    Output: [3,1,null,null,2]
//
//     3
//    /
//   1
//   \
//    2
//    Example 2:
//
//    Input: [3,1,4,null,null,2]
//
//      3
//     / \
//    1   4
//       /
//      2
//
//    Output: [2,1,4,null,null,3]
//
//      2
//     / \
//    1   4
//       /
//      3
//    Follow up:
//
//    A solution using O(n) space is pretty straight forward.
//    Could you devise a constant space solution?

#include "bst.h"
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
    void recoverTree(TreeNode* root)
    {
        pre = nullptr;
        first = nullptr;
        second = nullptr;
        recoverTreeHelper(root);
        if (first && second)
        {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }

    // We use morris traversal to have constant space complexity
    void recoverTree2(TreeNode* root)
    {
        pre = nullptr;
        first = nullptr;
        second = nullptr;
        TreeNode *rightmost = nullptr; // the rightmost node in the left subtree
        TreeNode *current = root;
        while (current != nullptr)
        {
            // for each node, we compare it with pre node as we did in in-order-traversal
            if(first == nullptr && pre && pre->val > current->val)
            {
                first = pre;
            }
            if(first != nullptr && pre->val > current->val)
            {
                second = current;
            }
            if (current->left != nullptr)
            {
                //got left subtree, then let's locate its rightmost node in left subtree
                rightmost = current->left;
                while(rightmost->right != nullptr && rightmost->right != current)
                {
                    rightmost = rightmost->right;
                }

                // if this left subtree has been visited before, then we are done with it
                // cut the connection with current node and start visit current's right subtree
                if(rightmost->right == current)
                {
                    rightmost->right = nullptr;
                    pre = current;
                    current = current->right;
                }
                else
                {
                    //if this left subtree has not been visited before, then we create a link from rightmost node
                    // to current node, so we can return to the start point after done the left subtree
                    rightmost->right = current;
                    current = current->left;
                }
            }
            else
            {
                //no left subtree, then just visit its right subtree
                pre = current;
                current = current->right;
            }
        }
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

private:
    TreeNode *pre;
    TreeNode *first;
    TreeNode *second;
    void recoverTreeHelper(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        recoverTreeHelper(root->left);
        if (first == nullptr && pre && pre->val > root->val)
        {
            first = pre;
        }
        if (first != nullptr && pre->val > root->val)
        {
            second = root;
        }
        pre = root;
        recoverTreeHelper(root->right);
    }
};

void test(void (Solution::*pf)(TreeNode*))
{
    BT bt;
    Solution sol;
    std::vector<int> nums = {1,3,NULLPTR,NULLPTR,2};
    auto root = bt.list2Tree(nums);
    (sol.*pf)(root);
    std::vector<int> ans = {3,1,NULLPTR,NULLPTR,2, NULLPTR, NULLPTR};
    assert(bt.tree2List(root) == ans);
    bt.freeTree(root);
    nums = {3,1,4,NULLPTR,NULLPTR,2};
    root = bt.list2Tree(nums);
    (sol.*pf)(root);
    ans = {2,1,4,NULLPTR,NULLPTR,3,NULLPTR,NULLPTR,NULLPTR};
    assert(bt.tree2List(root) == ans);
    bt.freeTree(root);
}

int main()
{
    void (Solution::*ptr2recoverTree)(TreeNode*);
    ptr2recoverTree = &Solution::recoverTree;
    test(ptr2recoverTree);
    ptr2recoverTree = &Solution::recoverTree2;
    test(ptr2recoverTree);
}