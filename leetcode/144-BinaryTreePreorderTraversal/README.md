## Solution explanation

There are two version implemented. One utilizes the recursion definition of tree, which
is implemented in `preorderTraversal` and the other is is an iterative approach that utilizes
stack, which is implemented in `preorderTraversal2`. Note that preorder is a version of DFS, which naturally
leads to the stack. 

Note that in `preorderTraversal2`, we check `node.right` first and then `node.left` because the stack
is FIFO structure and we want to visit left child first and then the right child in the preorder traversal.
Thus, we want to push right child in the stack first.

```python
if node.right:
    stack.append(node.right)
if node.left:
    stack.append(node.left)
```