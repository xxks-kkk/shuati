/*
 * [Source]
 * 
 * https://leetcode.com/problems/same-tree/
 *
 * [Problem Description]
 *
 * Given two binary trees, write a function to check if they are equal or not.
 * 
 * Two binary trees are considered equal if they are structurally identical 
 * and the nodes have the same value. 
 *
 * [Companies]
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p,
                struct TreeNode* q)
{
  if ((p && !q) || (!p && q)) return false;
  if (!p && !q) return true;
  if(p->val != q->val) return false;
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
