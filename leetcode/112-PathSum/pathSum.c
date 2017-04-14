/*
 * [Source]
 * 
 * https://leetcode.com/problems/path-sum/
 *
 * [Problem Description]
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
 * such that adding up all the values along the path equals the given sum. 
 *
 * For example:
 * Given the below binary tree and sum = 22, 
 *
 *             5
 *            / \
 *           4   8
 *          /   / \
 *         11  13  4
 *        /  \      \
 *       7    2      1
 *
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 *
 * [Comments]
 *
 * The general strategy is to subtract the node value from the sum when recurring
 * down, and check to see if the sum is the value of the leaf node when we run
 * out of the tree.
 *
 * For example, for above tree, when we down to node 2, the sum is 2 as well.
 * Thus, we know there exists a path that satisfies the condition.
 *
 * This problem can be found: http://cslibrary.stanford.edu/110/BinaryTrees.html
 * However, the solution provided is not right when we provide the tree [] with 
 * sum 1. If we follow the solution from the link, the return will be true, which
 * is not consistent with our problem description.
 *
 * In addition, the general philosophy is to do "subtraction" instead of "addition".
 * In my first attempt, I try to use a variable (say, cand)
 * to keep track of the addition result of the nodes we have visited so far. 
 * This can be problematic because
 * Once we get down to a leaf node (say, 7) and it is not the right path, by the
 * nature of recursion, we get back to 11. However, we want to rollback our cand
 * variable as well. However, this is quite hard to do so. Thus, it is a lot easier
 * to do "subtraction on the target" than do "addition on what we have". 
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
bool
hasPathSum(struct TreeNode* root,
           int sum)
{
  if (root == NULL)
    return false;
  if (!root->left && !root->right && root->val == sum)
    return true;
  return
    hasPathSum(root->left, sum - root->val) ||
    hasPathSum(root->right, sum - root->val);
}
