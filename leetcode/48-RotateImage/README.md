## Solution Explanation

```python
# clockwise rotate
# first reverse up to down, then swap the symmetry around the diagonal
# 1 2 3     7 8 9     7 4 1
# 4 5 6  => 4 5 6  => 8 5 2
# 7 8 9     1 2 3     9 6 3

def rotate(self, matrix):
    """
    :type matrix: List[List[int]]
    :rtype: void Do not return anything, modify matrix in-place instead.
    """
    matrix.reverse()
    for i in range(len(matrix)):
        for j in range(i):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
```

```cpp
/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry around the diagonal
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}
```

One note on the implementation, instead of doing `for (int j = i + 1; j < matrix[i].size(); ++j)`
we can do `for (int j = 0; j < i; ++j)`, which essentially the same.
First code fragment doesn't perform swap of the elements on the diagonal of the matrix.
But the second code fragment, we perform
swap the symmetry on every element. The elements on the diagonal of the matrix 
will be swapped with itself as well.


## Reference

- https://leetcode.com/problems/rotate-image/discuss/18872