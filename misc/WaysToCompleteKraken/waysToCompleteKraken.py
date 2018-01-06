# Kraken is a board game that contains m x n grids on a rectangular board. The objective in Kraken is to
# reach the bottom of the board (bottom right corner) from the top of the board (top left corner) while moving
# one grid at a time in either the down, right, or diagonally-downward (down-right) directions.
#
# Complete the method - krakenCount that takes in two integers representing m and n, and return the total
# number of ways a player can complete the game.
#
# Note: Kraken can be played online with a large number of players and with extremely large board sizes.
# You method will be used as a part of a service that has strict latency requirements - so you should try
# and optimize your code to run as fast as possible.
#
# Sample Input 1
# 2
# 2
#
# Sample Output 1
# 3
#
# Sample Input 2
# 2
# 3
#
# Sample Output 2
# 5

class Solution(object):
    def krakenCount(self, m, n):
        """
        :param m: int
        :param n: int
        :return:  int
        """
        path = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    path[i][j] = 1
                elif i == 0 and j > 0:
                    path[i][j] = path[i][j-1]
                elif i > 0 and j == 0:
                    path[i][j] = path[i-1][j]
                else:
                    path[i][j] = path[i-1][j-1] + path[i-1][j] + path[i][j-1]
        return path[m-1][n-1]

    def krakenCountOpt1(self, m, n):
        curr = [1] * m
        prev = [1] * m
        for j in range(1,n):
            for i in range(1,m):
                curr[i] = prev[i] + curr[i-1] + prev[i-1]
            curr, prev = prev, curr
        return prev[-1]

if __name__ == "__main__":
    sol = Solution()
    assert sol.krakenCount(2,2) == 3
    assert sol.krakenCount(2,3) == 5
    assert sol.krakenCountOpt1(2,2) == 3
    assert sol.krakenCountOpt1(2,3) == 5








