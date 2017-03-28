/*
 * [Source]
 * 
 * https://leetcode.com/problems/maximum-depth-of-binary-tree
 *
 * [Problem Description]
 *
 * Given a binary tree, find its minimum depth.
 *
 * The maximum depth is the number of nodes along 
 * the longest path from the root node down to 
 * the farthest leaf node. 
 *
 * [Related Questions]
 *
 * 1. Leetcode-111 (exactly the same)
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

int
maxDepth(struct TreeNode* root)
{
  if (root == NULL) return 0;

  int l = maxDepth(root->left);
  int r = maxDepth(root->right);
  if(!l && !r) return 1; //leaf
  if(l && !r) return l+1; // no right child
  if(!l && r) return r+1; // no left child
  return l>r ? (l+1) : (r+1);
}
