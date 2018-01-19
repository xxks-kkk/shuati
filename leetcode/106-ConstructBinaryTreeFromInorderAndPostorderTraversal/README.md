## Solution explanation

Let's use an example to illustrate the idea of the solution. Given a tree below:

```
     1
    / \
   2   3
  / \
 4   5
```

The inorder traversal gives `4,2,5,1,3` and the postorder traversal gives `4,5,2,3,1`. As you can see,
the last number of the postorder will give the root value of the binary tree (i.e. `1`) and the inorder
traversal tells us that which nodes belong to the left subtree and which nodes belong to the
right subtree. Thus, to construct the binary tree, we use the recursion definition of the binary tree
and construct the root using the last number from postorder and recursively construct the left and 
right subtree on the nodes suggested by the inorder traversal. 

The implementation is quite self-explanatory. Since we need to find the position of the root in the
the inorder to determine which sets of nodes belong to left or right subtree, we can use the loop
to find that, which is done in `buildTree`. However, we can also build a hash table to give us
$O(1)$ access to the position of the root, which is done in `buildTree2`.

## Reference

- http://www.cnblogs.com/grandyang/p/4296193.html
- https://discuss.leetcode.com/topic/3296/my-recursive-java-code-with-o-n-time-and-o-n-space