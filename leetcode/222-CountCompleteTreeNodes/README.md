## Solution explanation

### Method 1 & 2: Naive approach

M1 is a very naive level-order traversal and counting. This method doesn't utilize the complete tree information.
M2 is a attempt to improve the counting performance by first get the height of the tree by going to the leftmost
node. However, M2 still uses traverse almost every node (the stack halt on the second to last level of nodes)
and the execution time shows that the performance of these two methods is pretty close.

### Method 3: Do recursion whenever we have to

M3 is an approach that tries to avoid expensive stack call as much as possible. For example, if the tree is a perfect
binary tree, then the leftmost node has the same depth as the rightmost node and we don't need any stack call. However,
if the last level of tree is partially filled, the stack call is avoid as much as we can. For the given example,
`[2,4,5]` subtree is perfect binary tree and thus we don't need to stack call into it and this saves time. For the
`[3,6]` subtree, we have to do the stack call.

## Remarks

If the solution is truly innovative (i.e. significant enough to improve performance), the execution timing
is likely to be significant better and independent of how many experiment trails you run. For M3, the execution time
always get "0" while the other two fluctuate between 5 - 10. M1 and M2 performance difference is really minimum and subject
to statistical variation: one trail M1 is better than M2 and another trail M2 is better than M1. This reminds me of
HyperPebblesDB project and system research project in general: only the truly significant improvement can be independent of
the number of experiment trail we run. In other words, if the experiment shows that our improved method cannot consistently
beat the baseline, then it is very likely that our idea or implementation doesn't work. This is the biggest takeaway from
this problem.

## Reference

- https://leetcode.com/problems/count-complete-tree-nodes/discuss/61953/Easy-short-c++-recursive-solution