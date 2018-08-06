## Solution explanation

The solution utilizes the recursive definition of the binary tree. Both `left` and `right` are not `None`
when `p` and `q` are in two subtrees (left and right, or right and left). If `left` is not `None` and
`right` is None, that means both `p` and `q` are in the left subtree and we simply return the `left`,
which obtained from `lowestCommonAncestor` on left subtree. Similar reasoning holds when `left` is `None`
and `right` is not `None`.

For C++ solution, note that we should test out the whether the pointers are the same (i.e., both pointers
pointing to the same node) instead of testing out the equivalence of values pointed by the two pointers:

```cpp
// Wrong
if (!root || root->val == p->val || root->val == q->val) return root;
// Correct
if (!root || root == p || root == q) return root;
```

This is because there can be duplicate values in the tree. In addition, to understand the logic of the code,
when both `left` and `right` aren't `nullptr`, that means each subtree of the root contains a target node.
Thus, by definition of LCA, we know the root is LCA in this case.  When both target nodes are in the same subtree,
whenever we find one of the target nodes, we can immediately return. This also follows the definition of LCA.

## Application

In [OSTEP: Chapter 41 Locality and The Fast File System](http://pages.cs.wisc.edu/~remzi/OSTEP/file-ffs.pdf),
we perform an empirical study of the file access locality using SEER traces. In the SEER traces, we measure 
the distance between two file open by caclulating the distance between the files and their common ancestor.

Example:

- Open `dir/f` followed by opening `dir/g`. The distance between the two file accesses is 1 as they
share the same directory but are not the same file.
- Open `proj/src/foo.c` followed by `proj/obj/foo.o`. The distance between these two accesses is two,
as `proj` is the common ancestor.


## Reference

- https://discuss.leetcode.com/topic/18561/4-lines-c-java-python-ruby
