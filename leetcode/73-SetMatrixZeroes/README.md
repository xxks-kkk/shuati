## Solution explanation

To understand the implemented solution, we need to think about what $O(mn)$ space complexity and $O(m+n)$ 
space complexity solution might be.
$O(mn)$ solution is simply to create a new matrix with the same size. Then, we traverse through the given
matrix row-wise and whenever we find a zero in a row, we set the corresponding row in the new matrix to 
all zeros. We do the exact same thing column-wise. For a $O(m+n)$ solution, we use two lists with size `m`
and `n` respectively. Then, we use these two lists to keep track whether there are zero in each row
and each column. Then, we update the given matrix based on these two lists.

The implemented solution is similar to $O(m+n)$ solution. However, unlike the $O(m+n)$ solution using
two separate-created lists, we use the first row and the first column of the given matrix instead as 
our lists. In other words, we store states of each row in the first of that row, 
and store states of each column in the first of that column. The only issue with this approach is that
the state of the first row and the first column will occupy the same cell. Thus, in our implementation,
we use the cell to keep track of the state of the first row and use a separate variable `col_0` to 
keep track of the state of the first column.

In the first phase, we use matrix elements to set states in a top-down way. 
In the second phase, we use states to set matrix elements in a bottom-up way.
Be careful with the terminate conditions of the loops in the implementation.


## Reference

- https://leetcode.com/problems/set-matrix-zeroes/discuss/26014
- http://www.cnblogs.com/grandyang/p/4341590.html