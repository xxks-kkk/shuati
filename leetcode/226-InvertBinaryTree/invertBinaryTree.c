/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/invert-binary-tree/#/description
 *          
 * [Problem Description]
 *          
 * Invert a binary tree.
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * 
 * to
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
 *          
 * [Comments]
 *          
 *          
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
struct TreeNode* invertTree(struct TreeNode* root) {
  struct TreeNode* tmp;
  if (root != NULL)
  {
    if (root->left != NULL && root->right == NULL)
    {
      root->right = invertTree(root->left);
      root->left = NULL;
    }
    else if (root->right != NULL && root->left == NULL)
    {
      root->left = invertTree(root->right);
      root->right = NULL;
    }
    else if (root->left != NULL && root->right != NULL)
    {
      tmp = root->left;
      root->left = invertTree(root->right);
      root->right = invertTree(tmp);
    }
    return root;
  }
  return NULL;
}
