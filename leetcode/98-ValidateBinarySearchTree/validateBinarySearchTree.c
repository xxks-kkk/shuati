/*
 * [Source]
 * 
 * https://leetcode.com/problems/validate-binary-search-tree/
 *
 * [Problem Description]
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows: 
 *
 * - The left subtree of a node contains only nodes with keys less than the node's key.
 * - The right subtree of a node contains only nodes with keys greater than the node's key.
 * - Both the left and right subtrees must also be binary search trees.
 *
 * Binary tree [2,1,3] return true. Binary tree [1,2,3] return false. 
 *
 * [Comments]
 *
 * This is a very clever solution. You need to handtrace to see its correctness.
 * Suppose a binary tree [10, 5, 15, null, null, 6, 20], 
 *   
 *      10
 *     /  \
 *    5   15
 *       /  \
 *       6  20
 *  
 * then we have
 *
 * root   minNode   maxNode            
 * ------------------------
 * 10     NULL      NULL
 * 5      NULL      10    <--- left subtree
 * 15     10        NULL  <--- right subtree
 * 6      NULL      15    <--- left subtree
 * 20     15        NULL  <--- right subtree 
 *
 * [Companies]
 */

bool
isValidBSTHelper(struct TreeNode *root, struct TreeNode *lowerBound, struct TreeNode *upperBound)
{
    if (root == NULL)
    {
        return true;
    }
    if ((upperBound && upperBound->val <= root->val) ||
        (lowerBound && lowerBound->val >= root->val))
    {
        return false;
    }
    return isValidBSTHelper(root->left, lowerBound, root) &&
        isValidBSTHelper(root->right, root, upperBound);
}

bool
isValidBST(struct TreeNode *root)
{
    return isValidBSTHelper(root, NULL, NULL);
}
