#ifndef BST_H
#define BST_H

#include "shared_headers.h"

struct TreeNode
{
    int val;
    struct TreeNode *left, *right, *parent;
};

struct TreeNode *
findMin(struct TreeNode *n);
struct TreeNode *
findNext(struct TreeNode *n);
void
printBst(struct TreeNode *n);
struct TreeNode *
insertNode(struct TreeNode *r, int i);
struct TreeNode *
buildTree(int *t, int count);

#endif
