#include "bst.h"

TreeNode*
BST::list2Tree(std::vector<int> & nums)
{
    TreeNode* root = nullptr;
    for (auto & x: nums)
    {
        if (x != NULLPTR)
        {
            insert(root, x);
        }
    }
    return root;
}

void
BST::insert(TreeNode* & root, int val)
{
    if(root == nullptr)
    {
        root = new TreeNode(val);
    }
    else if (val < root->val)
    {
        insert(root->left, val);
    }
    else if (val > root->val)
    {
        insert(root->right, val);
    }
}

TreeNode*
BST::find(TreeNode* root, int val)
{
    if (root)
    {
        if (root->val == val)
        {
            return root;
        }
        else if (val < root->val)
        {
            return find(root->left, val);
        }
        else if (val > root->val)
        {
            return find(root->right, val);
        }
    }
    return nullptr;
}