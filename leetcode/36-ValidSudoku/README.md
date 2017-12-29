## Solution Explanation

The key part to solve this problem is matrix traversal. 

`%` and `/` are two operators that can be helpful for matrix traversal problems.
Consider the first block (top-left corner of the sudoku), it looks like below:

```
0,0, 0,1, 0,2
1,0, 1,1, 1,2 
2,0, 2,1, 2,2
```

The block to the right horizontally looks like below:

```
0,3, 0,4, 0,5
1,3, 1,4, 1,5
2,3, 2,4, 2,5
```

This is the same as shifting the first block to right by `3`. If we take a look 
at the block down below vertically, it looks like:

```
3,0, 3,1, 3,2
4,0, 4,1, 4,2
5,0, 5,1, 5,2
```

The block can be obtained by shifting the first block downward by `3`. 

In general, we may use `%` for horizontal traversal and `/` for vertical traversal. Let's
take a look the values resulting from `%` and `/`:

```
| i   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| i/3 | 0 | 0 | 0 | 1 | 1 | 1 | 2 | 2 | 2 |
| i%3 | 0 | 1 | 2 | 0 | 1 | 2 | 0 | 1 | 2 |
```

So, for a given block, we can traverse the whole block using just `j`.

But because `j` is just 0 to 9, it will stay only first block. But to increment block, use `i`. 
To move horizontally to next block, use `%` again : `ColIndex = 3 * i%3` 
(Multiply by 3 so that the next block is after 3 columns. 
For example `0,0` is start of first block, second block is `0,3` (not `0,1`))

Similarly, to move to next block vertically, 
use `/` and multiply by `3` as explained above.

Note `rowIndex` and `columnIndex` calculate the value of the top-left corner value of
each block. For example, when `i = 4`, `rowIndex = 3 * (4//3) = 3` and 
`colIndex = 3 * (4%3) = 3`, which is the top-left corner value of the middle block:

```
3,3, 3,4, 3,5
4,3, 4,4, 4,5
5,3, 5,4, 5,5
```


## Reference

- https://leetcode.com/problems/valid-sudoku/discuss/15450/