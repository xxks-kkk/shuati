/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description
 *          
 * [Problem Description]
 *          
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *          
 * [Comments]
 *          
 *          
 *          
 * [Companies]
 *
 * Microsoft
 */          


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTreeHelper(int* preorder, int preStart, int preEnd, int* inorder, int inStart, int inEnd);

struct TreeNode* buildTree(int* preorder,
                           int preorderSize,
                           int* inorder,
                           int inorderSize)
{
  return buildTreeHelper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize-1);
}

struct TreeNode* buildTreeHelper(int* preorder,
                                 int preStart,
                                 int preEnd,
                                 int* inorder,
                                 int inStart,
                                 int inEnd)
{
  if (preStart > preEnd || inStart > inEnd)
    return NULL;
  struct TreeNode* root = malloc(sizeof(struct TreeNode));
  root->val = preorder[preStart];
  root->left = root->right = NULL;
  int inIndex = 0; // Index of the current root in int* inorder
  int i;
  for(i = inStart; i <= inEnd; i++)
  {
    if (inorder[i] == root->val)
    {
      inIndex = i;
      break;
    }
  }
  root->left = buildTreeHelper(preorder, preStart+1, preStart + inIndex - inStart, inorder, inStart, inIndex-1);
  root->right = buildTreeHelper(preorder, preStart + inIndex - inStart + 1, preEnd, inorder, inIndex+1, inEnd);
  return root;
}
