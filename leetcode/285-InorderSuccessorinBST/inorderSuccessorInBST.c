#include "bst.h"
#include <stdio.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note that if we can access the parent node, we can certainly
 * find the successor given only one node p. See "findNext" in "cinclude/bst.c"
 * @param root
 * @param p
 * @return
 */
struct TreeNode *
inorderSuccessor(struct TreeNode *root, struct TreeNode *p)
{
    if (root == NULL || p == NULL)
    {
        return NULL;
    }
    // The solution resembles the binary search
    struct TreeNode *successor = NULL;
    while (root != NULL)
    {
        if (root->val <= p->val)
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

typedef struct TreeNode *(*ptr2inorderSuccessor)(struct TreeNode *, struct TreeNode *);

void
test(ptr2inorderSuccessor pfcn)
{
    int values[] = {8, 4, 12, 1, 7, 11, 20};
    struct TreeNode *t = buildTree(values, sizeof values / sizeof *values);
    printBst(t);
}

int
main(int argc, const char **argv)
{
    ptr2inorderSuccessor pfcn = &inorderSuccessor;
    test(pfcn);
}
