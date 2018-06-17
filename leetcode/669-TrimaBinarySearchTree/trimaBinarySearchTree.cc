//    Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that
//    all its elements lies in [L, R] (R >= L). You might need to change the root of the tree,
//    so the result should return the new root of the trimmed binary search tree.
//
//    Example 1:
//    Input:
//        1
//       / \
//      0   2
//
//    L = 1
//    R = 2
//
//    Output:
//      1
//       \
//        2
//    Example 2:
//    Input:
//        3
//       / \
//      0   4
//      \
//       2
//      /
//     1
//
//    L = 1
//    R = 3
//
//    Output:
//        3
//       /
//      2
//    /
//    1

#include "bst.h"
#include <vector>


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
    // recursive approach
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == nullptr)
        {
            return root;
        }
        else if(root->val > R)
        {
            root = trimBST(root->left, L, R);
            return root;
        }
        else if(root->val < L)
        {
            root = trimBST(root->right, L, R);
            return root;
        }
        else
        { // L <= root->val <= R
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        }
    }

    // iterative approach
    TreeNode* trimBST2(TreeNode* root, int L, int R) {
        auto current = root;
        //find the new root node to return
        while(current != nullptr)
        {
            if(current->val < L)
            {
                current = current->right;
            }
            else if (current->val > R)
            {
                current = current->left;
            }
            else if (current->val >= L && current->val <= R)
            {
                break;
            }
        }
        if (current == nullptr)
        {
            return current;
        }

        // trim the left subtree
        auto current2 = current;
        while (current2 && current2->left != nullptr)
        {
            if (current2->left->val < L)
            {
                current2->left = current2->left->right;
            }
            else
            {   // current2->left->val >= L and any root in left subtree is smaller than
                // current->val, which is in [L,R]. Thus, we don't need to consider
                // current2->right ones.
                current2 = current2->left;
            }
        }

        // trim the right subtree
        current2 = current;
        while (current2 && current2->right != nullptr)
        {
            if (current2->right->val > R)
            {
                current2->right = current2->right->left;
            }
            else
            {
                current2 = current2->right;
            }
        }
        return current;
    }
};

using ptr2trimBST = TreeNode* (Solution::*) (TreeNode*, int, int);

void test(ptr2trimBST pfcn)
{
    //TODO: there is memory leak
    Solution sol;
    BST bst;
    std::vector<int> nums = {1,0,2};
    auto root = bst.list2Tree(nums);
    std::vector<int> ans = {1, NULLPTR, 2, NULLPTR, NULLPTR};
    auto root_sol = (sol.*pfcn)(root, 1,2);
    assert(bst.tree2List(root_sol) == ans);
    bst.freeTree(root);
    nums = {3,0,4,NULLPTR,2,NULLPTR,NULLPTR,1};
    root = bst.list2Tree(nums);
    ans = {3,2,NULLPTR,1,NULLPTR,NULLPTR,NULLPTR};
    root_sol = (sol.*pfcn)(root,1,3);
    assert(bst.tree2List(root_sol) == ans);
    bst.freeTree(root);
}

int main()
{
    ptr2trimBST  pfcn = &Solution::trimBST;
    test(pfcn);
    pfcn = &Solution::trimBST2;
    test(pfcn);
}