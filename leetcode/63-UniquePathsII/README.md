## Solution explanation

### Basic solution

This is a fundamental DP problem. The solution here can be easily applied to "Unique Path" problem as well.
First of all, let’s make some observations.

Since the robot can only move right and down, when it arrives at a point, there are only two possibilities:

- It arrives at that point from above (moving down to that point).
- It arrives at that point from left (moving right to that point).

Thus, we have the following state equations: suppose the number of paths to arrive at a point $(i, j)$ is denoted as 
$P(i,j)$, and we have: $P(i,j) = P(i - 1,j) + P(i,j - 1)$ if `obstacleGrid[i][j] != 1` and $0$ otherwise.

The boundary conditions of the above equation occur at the leftmost column 
($P(i, j - 1)$ does not exist) and the uppermost row ($P(i - 1, j)$ does not exist).
Thus, 

- for the leftmost column, we have $P(i,0) = P(i-1,0) + 0 = P(i-1,0)$ if `obstacleGrid[i][j] != 1` and $0$ otherwise
- for the uppermost column, we have $P(0,j) = 0 + P(0, j-1) = P(0, j-1)$ if `obstacleGrid[i][j] != 1` and $0$ otherwise 

The solution is implemented as `uniquePathsWithObstacles`.

### Optimization 1

Usually, for DP problem, the optimization happens in the space complexity. The code above has space 
complexity $O(mn)$ because we maintain the `path` matrix. However, as one can see, each time 
when we update $P(i,j)$, we only need value from $P(i-1, j)$ (the same column as $P(i,j)$)and 
$P(i,j-1)$ (the left column of the column containing $P(i,j)$). Thus, it is enough to maintain 
two columns (the current column and the left column) instead of maintaining the full $m\times n$ matrix. 

In addition, there are some cases that the loop can be terminated earlier. Suppose 

```
obstacleGrid = [
            [0, 1, 0, 0], 
            [0, 1, 0, 0], 
            [0, 1, 0, 0]
               ]
```

Then we can see that it is impossible to reach the bottom-right corner after updating the second column 
since the number of paths to reach each element in the second column is `0`. 

The solution is implemented as `uniquePathsWithObstaclesOpt1`.

### Optimization 2

Further inspecting the above code, keeping two vectors only serve for the purpose of recovering `preb[i]`, 
which is simply `curr[i]` before its update. So we can use only one vector and the space is further optimized.
Here, we don't implement the early termination strategy to have a cleaner code.

The solution is implemented as `uniquePathsWithObstaclesOpt2`.

## Reference

- http://www.cnblogs.com/grandyang/p/4353680.html
- https://leetcode.com/problems/unique-paths-ii/discuss/23252
- https://leetcode.com/problems/unique-paths/discuss/22954