## Solution explanation

Based on the description of the problem, we naturally think about using binary search
to solve the problem. The only problem is to convert between the index of element in matrix
and the index in array:

- `m*n` matrix convert to an array: `matrix[x][y]` => `a[x * n + y]`

- an array convert to `m*n` matrix: `a[x]` => `matrix[x / n][x % n]`


## Reference

- https://leetcode.com/problems/search-a-2d-matrix/discuss/26220