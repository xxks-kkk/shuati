/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/sum-of-left-leaves/#/description
 *          
 * [Problem Description]
 *          
 * Find the sum of all left leaves in a given binary tree.
 * Example:
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
int sumOfLeftLeaves(struct TreeNode* root) {
  if (root == NULL) return 0;
  int sum = 0;
  if(root->left != NULL)
  {
    if(!root->left->left && !root->left->right)
      sum += root->left->val;
    sum += sumOfLeftLeaves(root->left);
  }
  if(root->right != NULL)
  {
    sum += sumOfLeftLeaves(root->right);
  }
  return sum;
}
