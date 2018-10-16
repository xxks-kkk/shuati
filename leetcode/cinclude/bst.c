#include "cinclude/bst.h"

/* Example BST:
 *
 *       8
 *     /   \
 *    4     12
 *   / \    / \
 *  1   7 11   20
 *
 * struct TreeNode {
 *    int val;
 *    struct TreeNode *left, *right, *parent;
 * };
 */

struct TreeNode *
findMin(struct TreeNode *n)
{
    struct TreeNode *current = n;
    if (current == NULL)
    {
        return current;
    }
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct TreeNode *
findNext(struct TreeNode *n)
{
    if (n->right != NULL)
    {
        return findMin(n->right);
    }
    struct TreeNode *p = n->parent;
    while (p != NULL && n == p->right)
    {
        n = p;
        p = p->parent;
    }
    return p;
}

void
printBst(struct TreeNode *n)
{
    struct TreeNode *current = findMin(n);
    if (current != NULL)
    {
        printf("%d\n", current->val);
    }
    do
    {
        current = findNext(current);
        if (current != NULL)
        {
            printf("%d\n", current->val);
        }
    }
    while (current != NULL);
}

struct TreeNode *
insertNode(struct TreeNode *r, int i)
{
    struct TreeNode *n = malloc(sizeof(struct TreeNode));
    if (n == NULL)
    {
        return n;
    }
    n->left = n->right = n->parent = NULL;
    n->val = i;

    if (r == NULL)
    {
        return n;
    }

    do
    {
        n->parent = r;
        if (n->val < r->val)
        {
            r = r->left;
        }
        else if (n->val > r->val)
        {
            r = r->right;
        }
        else
        {
            free(n);
            return NULL;
        }
    }
    while (r != NULL);

    if (n->val < n->parent->val)
    {
        n->parent->left = n;
    }
    else
    {
        n->parent->right = n;
    }

    return n;
}

struct TreeNode *
buildTree(int *t, int count)
{
    if (count <= 0)
    {
        return NULL;
    }
    struct TreeNode *root = insertNode(NULL, t[0]);
    if (root == NULL)
    {
        return NULL;
    }
    for (int i = 1; i < count && insertNode(root, t[i]) != NULL; ++i);
    return root;
}

