## Solution explanation

The solution utilizes the recursive definition of the binary tree. Both `left` and `right` are not `None`
when `p` and `q` are in two subtrees (left and right, or right and left). If `left` is not `None` and
`right` is None, that means both `p` and `q` are in the left subtree and we simply return the `left`,
which obtained from `lowestCommonAncestor` on left subtree. Similar reasoning holds when `left` is `None`
and `right` is not `None`.

## Reference

- https://discuss.leetcode.com/topic/18561/4-lines-c-java-python-ruby