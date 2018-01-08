# Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
#
# Follow up:
# Did you use extra space?
# A straight forward solution using O(mn) space is probably a bad idea.
# A simple improvement uses O(m + n) space, but still not the best solution.
# Could you devise a constant space solution?

class Solution:
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        col_0 = False
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            if matrix[i][0] == 0:
                col_0 = True
            for j in range(1,n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(m-1, -1, -1):
            for j in range(n-1, 0, -1):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
            if col_0:
                matrix[i][0] = 0


if __name__ == "__main__":
    sol = Solution()
    matrix = [[1,2,3],[4,0,6],[7,8,9]]
    sol.setZeroes(matrix)
    print(matrix)
    matrix = [[1,2,3,4],[5,0,5,2],[8,9,2,0],[5,7,2,1]]
    sol.setZeroes(matrix)
    print(matrix)