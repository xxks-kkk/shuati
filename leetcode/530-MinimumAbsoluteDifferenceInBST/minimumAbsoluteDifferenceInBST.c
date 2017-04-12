/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int
min(int a, int b)
{
  int min = a;
  (void) ((min > b) && (min = b));
  return min;
}

void
getMinimumDifferenceHelper(struct TreeNode* root,
                           int *prevNodeVal,
                           int* minVal)
{
  if (root->left != NULL)
    getMinimumDifferenceHelper(root->left, prevNodeVal, minVal);

  if (*prevNodeVal >= 0)
    *minVal = min(*minVal, root->val - *prevNodeVal);

  *prevNodeVal = root->val;

  if (root->right != NULL)
    getMinimumDifferenceHelper(root->right, prevNodeVal, minVal);
}

int
getMinimumDifference(struct TreeNode* root)
{
  int minVal = INT_MAX;
  int prevNodeVal = -1;
  getMinimumDifferenceHelper(root, &prevNodeVal, &minVal);
  return minVal;
}
