## Solution explanation

This problem is very similar to "Unique Path" problem on Leetcode. Detailed explanation
can be found in [Unique Path II](https://github.com/xxks-kkk/shuati/tree/master/leetcode/63-UniquePathsII)
solution explanation.

### Solution 1

We implement one version in `krakenCount` in the python file. The following is an alternative way of writting:

```python
def krakenCount(m, n):
    path = [[0 for j in range(n)] for i in range(m)]
    for i in range(m):
        path[i][0] = 1
    for j in range(n):
        path[0][j] = 1
    for i in range(1,m):
        for j in range(1,n):
            path[i][j] = path[i-1][j] + path[i][j-1] + path[i-1][j-1]
    return path[m-1][n-1]
```

### Optimization 1

We use two lists instead of a whole matrix to save space. The solution is implemented in `krakenCountOpt1`.

