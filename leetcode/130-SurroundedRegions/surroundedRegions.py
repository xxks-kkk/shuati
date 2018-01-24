# Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
#
# A region is captured by flipping all 'O's into 'X's in that surrounded region.
#
# For example,
# X X X X
# X O O X
# X X O X
# X O X X
# After running your function, the board should be:
#
# X X X X
# X X X X
# X X X X
# X O X X
class disjSet(object):
    # Implementation follows: https://algs4.cs.princeton.edu/lectures/15UnionFind-2x2.pdf
    def __init__(self, n):
        self.disjSet = range(n)
        self.size = [1] * n

    def find(self, x):
        # Implements find operation using path compression
        while self.disjSet[x] != x:
            self.disjSet[x] = self.disjSet[self.disjSet[x]] # Make every other node in path point to its grandparent
            x = self.disjSet[x]
        return x

    def union(self, p, q):
        # Implements union operation using union-by-size (aka smart-union)
        pType = self.find(p) # get the class name for p
        qType = self.find(q) # get the class name for q
        if pType == qType:
            return
        if self.size[p] <= self.size[q]:
            self.disjSet[pType] = qType
            self.size[qType] += self.size[pType]
        else:
            self.disjSet[qType] = pType
            self.size[pType] += self.size[qType]

    def getDisjSet(self):
        return self.disjSet

    def getSize(self):
        return self.size

class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        m = len(board)
        n = len(board[0])
        S = disjSet(m*n+1)
        dummyNode = m*n
        for i in range(m):
            if board[i][0] == 'O':
                S.union(i * n, dummyNode)
            if board[i][n - 1] == 'O':
                S.union(i * n + n - 1, dummyNode)
        for j in range(n):
            if board[0][j] == 'O':
                S.union(j, dummyNode)
            if board[m - 1][j] == 'O':
                S.union((m - 1) * n + j, dummyNode)
        for i in range(1,m-1):
            for j in range(1,n-1):
                if board[i][j] == 'O':
                    if board[i-1][j] == 'O':
                        S.union((i-1)*n+j, i*n+j)
                    if board[i+1][j] == 'O':
                        S.union((i+1)*n+j, i*n+j)
                    if board[i][j-1] == 'O':
                        S.union(i*n+j-1, i*n+j)
                    if board[i][j+1] == 'O':
                        S.union(i*n+j+1, i*n+j)
        for i in range(m):
            for j in range(n):
                if S.find(i*n+j) != S.find(dummyNode):
                    board[i][j] = 'X'

    def solve2(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if not board:
            return
        m = len(board)
        n = len(board[0])
        save = [ij for k in range(m + n) for ij in ((0, k), (m - 1, k), (k, 0), (k, n - 1))]
        while save:
            i, j = save.pop()
            if 0 <= i < m and 0 <= j < n and board[i][j] == 'O':
                board[i][j] = 'S'
                save += (i, j - 1), (i, j + 1), (i - 1, j), (i + 1, j)
        board[:] = [['XO'[c == 'S'] for c in row] for row in board]


if __name__ == "__main__":
    # S = disjSet(10)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    # S.union(1,2)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    # S.union(3,4)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    # S.union(5,6)
    # S.union(7,8)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    # S.union(7,9)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    # S.union(2,8)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    # S.union(0,5)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    # S.union(1,9)
    # print("disjSet: ", S.getDisjSet())
    # print("size: ", S.getSize())
    sol = Solution()
    board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    sol.solve(board)
    for row in board:
        print(row)

    board = [["O","O"],["O","O"]]
    sol.solve(board)
    for row in board:
        print(row)

    board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    sol.solve2(board)
    for row in board:
        print(row)

    board = [["O","O"],["O","O"]]
    sol.solve2(board)
    for row in board:
        print(row)