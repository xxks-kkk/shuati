## Solution explanation

Again, we utilize the recursion definition of the tree. We let `tmp` points to the root of the 
right subtree. Then, we apply the `flatten` function to make the right subtree into a linked list.
Then, we apply the `flatten` function again to make the left subtree into a linked list.
Then, we make `root.right` points to the original left subtree (that's why we need `tmp`
to hold the original right subtree). This is because for the given question,
the linked list is generated via the preorder traversal of the binary tree. Then, we use `cur` to 
get the end of the linked list generated from the original left subtree and we make the linked list
generated from the original right subtree attached after the node pointed by `cur`.