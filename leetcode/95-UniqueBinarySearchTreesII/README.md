## Solution explanation

The solution to this problem is to note that $1 \dots n$ is the in-order traversal for any BST with 
nodes $1$ to $n$. So we can loop through $1 \dots n$ and use $i \in [1,n]$ as the root of BST. Then,
the left subtree will contain all elements in $[1,i-1]$ and the right subtree will contain
all elements in $[i+1, n]$. Then we use the recursive calls to construct the left subtrees and the
right subtrees. The return of the recursive calls is a list of left (or right) subtree roots. 
We can combine them in all possible ways with our root to construct the unique structured BST.
Here, we again utilized the recursive definition of the tree structure.

One thought I had initially is to generate all possible permutations for the given $n$
and then we construct BST from there. For example,
for `n = 3`, we have:

```
1,2,3
1,3,2
2,1,3
2,3,1
3,1,2
3,2,1
```

However, we can notice that `2,1,3` and `2,3,1` will lead to the same BST. However, with the
algorithm described above, we can easily avoid this problem. Because for BST with `2` as the root,
we only have `1` for left subtree and `3` for right subtree, which can never lead to the duplicate
structured BST.


## Reference

- https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31494