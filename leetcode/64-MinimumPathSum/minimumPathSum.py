# Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
#
# Note: You can only move either down or right at any point in time.
#
# Example 1:
# [[1,3,1],
#  [1,5,1],
#  [4,2,1]]
# Given the above grid map, return 7. Because the path 1->3->1->1->1 minimizes the sum.

class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        path = [[0] * n for _ in range(m)]
        for j in range(n):
            for i in range(m):
                if i == 0 and j == 0:
                    path[i][j] = grid[i][j]
                elif i == 0 and j > 0:
                    path[i][j] = grid[i][j] + path[i][j-1]
                elif i > 0 and j == 0:
                    path[i][j] = grid[i][j] + path[i-1][j]
                else:
                    path[i][j] = grid[i][j] +  min(path[i-1][j], path[i][j-1])
        return path[m-1][n-1]

    def minPathSumOpt2(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        curr = [0] * m
        for j in range(n):
            for i in range(m):
                if i > 0 and j > 0:
                    curr[i] = grid[i][j] + min(curr[i], curr[i-1])
                elif i == 0:
                    curr[i] = grid[i][j] + curr[i]
                elif j == 0:
                    curr[i] = grid[i][j] + curr[i-1]
        return curr[-1]

    def minPathSumOpt3(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        for j in range(n):
            for i in range(m):
                if i == 0 and j > 0:
                    grid[i][j] = grid[i][j] + grid[i][j-1]
                elif i > 0 and j == 0:
                    grid[i][j] = grid[i][j] + grid[i-1][j]
                elif i > 0 and j > 0:
                    grid[i][j] = grid[i][j] +  min(grid[i-1][j], grid[i][j-1])
        return grid[m-1][n-1]

if __name__ == "__main__":
    sol = Solution()
    grid = [[1,3,1],[1,5,1],[4,2,1]]
    assert sol.minPathSum(grid) == 7
    assert sol.minPathSumOpt2(grid) == 7
    assert sol.minPathSumOpt3(grid) == 7
    grid = [[1]]
    assert sol.minPathSum(grid) == 1
    assert sol.minPathSumOpt2(grid) == 1
    assert sol.minPathSumOpt3(grid) == 1
    grid = [[1,2],[1,1]]
    assert sol.minPathSum(grid) == 3
    assert sol.minPathSumOpt2(grid) == 3
    assert sol.minPathSumOpt3(grid) == 3