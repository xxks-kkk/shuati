/*
 * [Source]
 * 
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
 *
 * [Problem Description]
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along 
 * the shortest path from the root node down to 
 * the nearest leaf node. 
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

// This is a very classic solution to reflect tree
// recursive definition.
int minDepth(struct TreeNode* root) {
  if(root == NULL) return 0;

  int l = minDepth(root->left);
  int r = minDepth(root->right);

  if (l == 0 && r == 0) return 1; // leaf
  if (l && r == 0) return l+1;    // no right child
  if (r && l == 0) return r+1;    // no left child
  return l < r ?(l+1) : (r+1);    // has both left and right child
}
