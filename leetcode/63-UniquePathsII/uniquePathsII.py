# Follow up for "Unique Paths":
#
# Now consider if some obstacles are added to the grids. How many unique paths would there be?
#
# An obstacle and empty space is marked as 1 and 0 respectively in the grid.
#
# For example,
# There is one obstacle in the middle of a 3x3 grid as illustrated below.
#
# [
#   [0,0,0],
#   [0,1,0],
#   [0,0,0]
# ]
# The total number of unique paths is 2.
#
# Note: m and n will be at most 100.

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        path = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    path[i][j] = 0
                elif i == 0 and j == 0:
                    path[i][j] = 1
                elif i == 0 and j > 0:
                    path[i][j] = path[i][j - 1]
                elif i > 0 and j == 0:
                    path[i][j] = path[i - 1][j]
                else:
                    path[i][j] = path[i - 1][j] + path[i][j - 1]
        return path[m - 1][n - 1]

    def uniquePathsWithObstaclesOpt1(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        terminateEarly = True
        curr, prev = [0]*m, [0]*m
        for i in range(m):
            if obstacleGrid[i][0] != 1:
                prev[i] = 1
            else:
                break
        for j in range(1,n):
            if obstacleGrid[0][j] != 1:
                curr[0] = prev[0]
                if curr[0]:
                    terminateEarly = False
            else:
                curr[0] = 0
            for i in range(1,m):
                if obstacleGrid[i][j] != 1:
                    curr[i] = curr[i-1] + prev[i]
                    if curr[i]:
                        terminateEarly = False
                else:
                    curr[i] = 0
            if terminateEarly:
                return 0
            curr, prev = prev, curr
        return prev[-1]

    def uniquePathsWithObstaclesOpt2(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        curr = [0]*m
        curr[0] = 1
        for j in range(n):
            for i in range(m):
                if obstacleGrid[i][j] == 1:
                    curr[i] = 0
                elif i > 0:
                    curr[i] += curr[i-1]
        return curr[-1]


if __name__ == "__main__":
    sol = Solution()
    obstacleGrid = [
                    [0,0,0],
                    [0,1,0],
                    [0,0,0]
                  ]
    assert sol.uniquePathsWithObstacles(obstacleGrid) == 2
    assert sol.uniquePathsWithObstaclesOpt1(obstacleGrid) == 2
    assert sol.uniquePathsWithObstaclesOpt2(obstacleGrid) == 2

