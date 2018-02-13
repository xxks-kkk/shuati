## Solution explanation

This problem can be solved via the in-order traversal. Since the $O(h)$ space requirement, we cannot
use the call stack because that the resulting list of all elements from tree is $O(n)$. 

Here, we use the stack explicitly. We know the smallest tree is the left-most node of BST and
for each give node, we just follow in-order traversal. To understand `next`, you can just think of an example

```
     7
    / \
   2   8
  / \
 1   4
    /
   3
```

Suppose `node` now is `2` and `node.right` is `4`. Then, we traverse all the left nodes of `4`. That's
essentially how we do in-order traversal (i.e., `[1,2,3,4,7,8]`). The stack at given time maintains
$O(h)$ nodes. Since for a given tree with $n$ nodes, `next` can be called at most $n$ times and `next`
running time is $O(n)$ (because while loop can run at most $n$ times as there are $n$ nodes). Thus,
for $n$ operations (i.e. `next`), the running time is $O(n)$, which leads to $O(1)$ amortized time.


### Remarks

- We can also solve this problem using "morris traversal"
[here](http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html) and [here](https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/).

## Reference

- https://leetcode.com/problems/binary-search-tree-iterator/discuss/52525/My-solutions-in-3-languages-with-Stack?page=1
- http://www.cnblogs.com/grandyang/p/4231455.html