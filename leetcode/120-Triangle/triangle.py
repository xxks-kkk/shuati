# Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
#
# For example, given the following triangle
# [
#      [2],
#     [3,4],
#    [6,5,7],
#   [4,1,8,3]
# ]
# The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
#
# Note:
# Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        def dfs(index, currRow, totalRows, minSum, sum):
            sum += triangle[currRow][index]
            if currRow == totalRows - 1:
                if sum < minSum:
                    minSum = sum
                return minSum
            minSum = dfs(index, currRow + 1, totalRows, minSum, sum)
            minSum = dfs(index + 1, currRow + 1, totalRows, minSum, sum)
            return minSum

        minSum = 9223372036854775807
        return dfs(0, 0, len(triangle), minSum, 0)

    def minimumTotal1(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        m = len(triangle)
        n = m + 1
        dp = [[9223372036854775807] * n for _ in range(m)]
        dp[0][0] = triangle[0][0]
        for i in range(1, m):
            for j in range(i+1):
                if j == 0:
                    dp[i][j] = dp[i-1][j] + triangle[i][j]
                elif j == m:
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j] + triangle[i][j], dp[i-1][j-1] + triangle[i][j])
        return min(dp[-1][:])

    def minimumTotal2(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        m = len(triangle)
        dp = list(triangle[-1])
        for i in range(m - 2, -1, -1):
            for j in range(i+1):
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1])
        return dp[0]

    def minimumTotal3(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        m = len(triangle)
        for i in range(m - 2, -1, -1):
            for j in range(i+1):
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
        return triangle[0][0]


if __name__ == "__main__":
    sol = Solution()
    triangle =[
                 [2],
                [3,4],
               [6,5,7],
              [4,1,8,3]
              ]
    assert sol.minimumTotal(triangle) == 11
    assert sol.minimumTotal1(triangle) == 11
    assert sol.minimumTotal2(triangle) == 11
    assert sol.minimumTotal3(list(triangle)) == 11

    triangle = [[-1],[3,2],[-3,1,-1]]
    assert sol.minimumTotal(triangle) == -1
    assert sol.minimumTotal1(triangle) == -1
    assert sol.minimumTotal2(triangle) == -1
    assert sol.minimumTotal3(list(triangle)) == -1