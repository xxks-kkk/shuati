# Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
#
# For example,
# Given n = 3,
#
# You should return the following matrix:
# [
#  [ 1, 2, 3 ],
#  [ 8, 9, 4 ],
#  [ 7, 6, 5 ]
# ]

class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        matrix = [[0]*n for _ in range(n)]
        dr = [0, 1, 0, -1]
        dc = [1, 0, -1, 0]
        seen = [[False] * n for _ in range(n)]
        r = c = di = 0
        for num in range(1, n*n+1):
            seen[r][c] = True
            matrix[r][c] = num
            r_new = r + dr[di]
            c_new = c + dc[di]
            if r_new < n and c_new < n and not seen[r_new][c_new]:
                r, c = r_new, c_new
            else:
                di = (di + 1) % 4
                r = r + dr[di]
                c = c + dc[di]
        return matrix

if __name__ == "__main__":
    sol = Solution()
    print(sol.generateMatrix(3))