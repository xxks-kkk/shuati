# A matrix is Toeplitz if every diagonal from top -left to bottom - right has the same element.
#
# Now given an MxN matrix, return True if and only if the matrix is Toeplitz.
#
# Example 1:
#
# Input: matrix = [[1, 2, 3, 4], [5, 1, 2, 3], [9, 5, 1, 2]]
# Output: True
# Explanation:
# 1234
# 5123
# 9512
#
# In the above grid, the diagonals are
# "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so
# the answer is True.
#
# Example 2:
#
# Input: matrix = [[1, 2], [2, 2]]
# Output: False
#
# Explanation:
#
# The diagonal "[1, 2]" has different elements.
#
# Note:
#
# matrix will be a 2D array of integers.
# matrix will have a number of rows and columns in range[1, 20].
# matrix[i][j] will be integers in range[0, 99].

class Solution:
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        pass

if __name__ == "__main__":
    sol = Solution()