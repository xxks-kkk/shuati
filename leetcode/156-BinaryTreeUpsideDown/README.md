## Solution explanation

Let's first understand the problem description. Suppose we have a binary tree `[1,2,3]` and
after applying the function, we have the binary tree `[2,3,1]`. In picture, it looks like:

```
   1               2
  / \   ---->     / \
 2   3           3   1
```

As you can see, the root becomes the right child, and the original left child of the root becomes root.
The original right child becomes the left child. We can solve the problem, again, using the 
recursive definition of the binary tree:

```
    1              4   1            4
   / \            / \ / \          / \
  2   3  -->     5   2   3  ->    5   2
 / \                                 / \
4   5                               3   1
```

The tree in the middle of the above graph is after the execution of 
`new_root = self.upsideDownBinaryTree(root.left)` and `new_root` is `2`.
Then, we only need to fix the links among `1,2,3`.

The iterative approach can be seen in the reference link.

## Reference

- https://leetcode.com/problems/binary-tree-upside-down/discuss/49406/Java-recursive-(O(logn)-space)-and-iterative-solutions-(O(1)-space)-with-explanation-and-figure