/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    if (root == NULL || p == NULL)
    {
        return NULL;
    }
    // The solution resembles the binary search
    struct TreeNode* successor = NULL;
    while(root != NULL)
    {
        if(root->val <= p->val)
        {
            // Similar to binary search, if root->val <= p->val, that means all the left nodes of the root
            // can be discarded. Their values are definitely smaller than p->val and thus cannot be its successor
            root = root->right;
        }
        else
        {
            // When root->val > p->val, root can be the successor of p. Thus, we update successor and move
            // the root to its left nodes as we may can find more tight bound that is greater than p->val but is
            // smaller than the current successor.
            successor = root;
            root = root->left;
        }
    }
    return successor;
}