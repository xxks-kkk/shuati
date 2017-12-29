# Determine if a Sudoku is valid, according to: [Sudoku Puzzles - The Rules.](http://sudoku.com.au/TheRules.aspx)
#
# The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
#
# Note:
# A valid Sudoku board(partially filled) is not necessarily solvable. Only the filled cells need to be validated.
class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(9):
            rows, columns, block = set(), set(), set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in rows:
                        return False
                    else:
                        rows.add(board[i][j])
                if board[j][i] != '.':
                    if board[j][i] in columns:
                        return False
                    else:
                        columns.add(board[j][i])
                rowIndex = 3*(i//3)
                colIndex = 3*(i%3)
                if board[rowIndex + j//3][colIndex + j%3] != '.':
                    if board[rowIndex + j//3][colIndex + j%3] in block:
                        return False
                    else:
                        block.add(board[rowIndex + j//3][colIndex + j%3])
        return True

if __name__ == "__main__":
    sol = Solution()
    board = [[".","8","7","6","5","4","3","2","1"],
             ["2",".",".",".",".",".",".",".","."],
             ["3",".",".",".",".",".",".",".","."],
             ["4",".",".",".",".",".",".",".","."],
             ["5",".",".",".",".",".",".",".","."],
             ["6",".",".",".",".",".",".",".","."],
             ["7",".",".",".",".",".",".",".","."],
             ["8",".",".",".",".",".",".",".","."],
             ["9",".",".",".",".",".",".",".","."]]
    assert sol.isValidSudoku(board) == True