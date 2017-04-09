/*
 * [Source]
 * 
 * https://leetcode.com/problems/diameter-of-binary-tree
 *
 * [Problem Description]
 *
 * Given a binary tree, you need to compute the length of the diameter of 
 * the tree. The diameter of a binary tree is the length of the longest path 
 * between any two nodes in a tree. This path may or may not pass through 
 * the root.
 *
 *         1
 *        /\
 *       2  3
 *      / \     
 *     4   5   
 *
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * Note: The length of path between two nodes is represented by the 
 * number of edges between them.
 * 
 * [Comments]
 *
 * The solution iself is typical recursive solution based upon the tree
 * recursive definition.
 *
 * Be careful about "1" noted by the in-line comment. It is easy to add
 * 1 in the wrong place b/c of we don't want to get rid of root. However,
 * 1 here means the distance.
 *  
 *    3
 *   / \
 *  1   4
 *
 * Think of the above simple example, the leftDepth we get from node "1"
 * is 1. It contains the distance between node "1" and "3". If we adding
 * extra 1 at the root, we may get the overcount.
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
static int
diameterOfBinaryTreeHelper(struct TreeNode* root,
                           int *maxDiaDepth)
{
  if(!root) return 0;
  int leftDepth = diameterOfBinaryTreeHelper(root->left, maxDiaDepth);
  int rightDepth = diameterOfBinaryTreeHelper(root->right, maxDiaDepth);
  int cand = leftDepth + rightDepth; //!! Not to add 1 here !!
  if (cand > *maxDiaDepth) *maxDiaDepth = cand;
  return leftDepth + 1 > rightDepth + 1 ? leftDepth + 1 : rightDepth + 1;
  // 1 here is the distance between the "root" and "root->left"
}

int
diameterOfBinaryTree(struct TreeNode *root)
{
  int maxDiaDepth = 0;
  diameterOfBinaryTreeHelper(root, &maxDiaDepth);
  return maxDiaDepth;
}
