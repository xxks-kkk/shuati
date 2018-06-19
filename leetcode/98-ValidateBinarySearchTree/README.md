## Solution explanation

First we have to be clear about BST definition: for a binary tree with root $X$, binary tree $X$ is BST if for every node $Y$
in the tree, we have `Y->left->val < Y->val < Y->right->val`. To verify this true, we can see that `Y->val` works
as an upper bound for all the values in its left subtree (i.e. `Y->left->val < Y->val`). Similarly,
`Y->val` also works as a lower bound for all the values in its right subtree (i.e. `Y->val < Y->right->val`). We directly
exploit in our code.