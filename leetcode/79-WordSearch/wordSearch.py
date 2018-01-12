# Given a 2D board and a word, find if the word exists in the grid.
#
# The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally
# or vertically neighboring.
# The same letter cell may not be used more than once.
#
# For example,
# Given board =
#
# [
#   ['A','B','C','E'],
#   ['S','F','C','S'],
#   ['A','D','E','E']
# ]
# word = "ABCCED", -> returns true,
# word = "SEE", -> returns true,
# word = "ABCB", -> returns false.

class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def search(board, word, index, i, j, visited):
            if index == len(word):
                return True
            if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]) or visited[i][j] or board[i][j] != word[index]:
                return False
            visited[i][j] = True
            res = search(board, word, index+1, i-1, j, visited) or \
                  search(board, word, index+1, i+1, j, visited) or \
                  search(board, word, index+1, i, j+1, visited) or \
                  search(board, word, index+1, i, j-1, visited)
            visited[i][j] = False
            return res
        m = len(board)
        n = len(board[0])
        visited = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if search(board, word, 0, i, j, visited):
                    return True
        return False


if __name__ == "__main__":
    sol = Solution()
    board = [
        ['A','B','C','E'],
        ['S','F','C','S'],
        ['A','D','E','E']
    ]
    assert sol.exist(board, "ABCCED") == True
    assert sol.exist(board, "SEE") == True
    assert sol.exist(board, "ABCB") == False