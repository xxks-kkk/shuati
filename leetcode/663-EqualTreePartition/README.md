## Solution explanation

After removing some edge from parent to child, 
(where the child cannot be the original root) 
the subtree rooted at child must be half the sum of the entire tree.

Let's record the sum of every subtree using stack. We can do this recursively 
using depth-first search. After, we should check that half the 
sum of the entire tree occurs somewhere in our recording 
(and not from the total of the entire tree.)

Some special cases need to be careful

```
  0      0
 / \      \
-1  1      0
```

## Reference

- https://leetcode.com/problems/equal-tree-partition/solution/
