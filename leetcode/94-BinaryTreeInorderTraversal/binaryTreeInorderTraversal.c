/*
 * [Source]
 * 
 * https://leetcode.com/problems/binary-tree-inorder-traversal
 *
 * [Problem Description]
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
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

void inorderTraversalHelper(struct TreeNode* root, int** array, int *i);
int countNodes(struct TreeNode *root);

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
inorderTraversal(struct TreeNode* root,
                 int* returnSize)
{
  *returnSize = countNodes(root);
  int *array = malloc(*returnSize * sizeof(int));
  int i = 0;
  inorderTraversalHelper(root, &array, &i);
  return array;
}

void
inorderTraversalHelper(struct TreeNode *root,
                       int** array,
                       int *i)
{
  if (root != NULL)
  {
    inorderTraversalHelper(root->left, array, i);
    *(*array+(*i)++) = root->val; // !! easy to get wrong !!
    inorderTraversalHelper(root->right, array, i);
  }
}

int
countNodes(struct TreeNode *root)
{
  int count = 0;
  if (root == NULL)
    count = 0;
  else
  {
    count += countNodes(root->left);
    count++;
    count += countNodes(root->right);
  }
  return count;
}
