# Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
# An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
# You may assume all four edges of the grid are all surrounded by water.
#
# Example 1:
#
# 11110
# 11010
# 11000
# 00000
# Answer: 1
#
# Example 2:
#
# 11000
# 11000
# 00100
# 00011
# Answer: 3

class Solution:
    def numIslands(self, grid):
        """
        DFS
        :type grid: List[List[str]]
        :rtype: int
        """
        def dfs(i,j):
            grid[i][j] = '0'
            if i+1 < m and grid[i+1][j] == '1':
                dfs(i+1, j)
            if i-1 >= 0 and grid[i-1][j] == '1':
                dfs(i-1, j)
            if j+1 < n and grid[i][j+1] == '1':
                dfs(i,j+1)
            if j-1 >= 0 and grid[i][j-1] == '1':
                dfs(i, j-1)
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        numIslands = 0
        for i in range(m):
            for j in range(n):
               if grid[i][j] == '1':
                    dfs(i,j)
                    numIslands += 1
        return numIslands

    def numIslands1(self, grid):
        """
        BFS
        :type grid: List[List[str]]
        :rtype: int
        """
        def bfs(i,j):
            grid[i][j] = '0'
            queue = []
            queue.insert(0, (i,j))
            while queue:
                i,j = queue.pop()
                if i + 1 < m and grid[i + 1][j] == '1':
                    queue.insert(0,(i+1,j))
                    grid[i+1][j] = '0'
                if i - 1 >= 0 and grid[i - 1][j] == '1':
                    queue.insert(0,(i-1,j))
                    grid[i-1][j] = '0'
                if j + 1 < n and grid[i][j + 1] == '1':
                    queue.insert(0,(i,j+1))
                    grid[i][j+1] = '0'
                if j - 1 >= 0 and grid[i][j - 1] == '1':
                    queue.insert(0,(i,j-1))
                    grid[i][j-1] = '0'
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        numIslands = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    bfs(i,j)
                    numIslands += 1
        return numIslands

    def numIslands2(self, grid):
        """
        Union-find
        :type grid: List[List[str]]
        :rtype: int
        """
        def union(i,j):
            setX = find(i)
            setY = find(j)
            if setX == setY:
                return False
            if sizes[setX] >= sizes[setY]:
                sizes[setX] += sizes[setY]
                nodes[setY] = setX
            else:
                sizes[setY] += sizes[setX]
                nodes[setX] = setY
            return True

        def find(i):
            while nodes[i] != i:
                nodes[i] = nodes[nodes[i]]
                i = nodes[i]
            return i

        count = 0
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        nodes = [i for i in range(m*n)]
        sizes = [1 for i in range(m*n)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    count += 1
                    p = i * n + j
                    if i > 0 and grid[i-1][j] == '1':
                        q = (i-1)*n + j
                        if union(p,q):
                            count -= 1
                    if j > 0 and grid[i][j-1] == '1':
                        q = i*n + (j-1)
                        if union(p,q):
                            count -= 1
                    if i < m - 1 and grid[i+1][j] == '1':
                        q = (i+1)*n + j
                        if union(p, q):
                            count -= 1
                    if j < n - 1 and grid[i][j+1] == '1':
                        q = i * n + j+1
                        if union(p, q):
                            count -= 1
        return count

if __name__ == "__main__":
    sol = Solution()
    grid = [["1","1","1","1","0"],
            ["1","1","0","1","0"],
            ["1","1","0","0","0"],
            ["0","0","0","0","0"]]
    assert sol.numIslands(grid) == 1
    grid = [["1","1","1","1","0"],
            ["1","1","0","1","0"],
            ["1","1","0","0","0"],
            ["0","0","0","0","0"]]
    assert sol.numIslands1(grid) == 1
    grid = [["1","1","1","1","0"],
            ["1","1","0","1","0"],
            ["1","1","0","0","0"],
            ["0","0","0","0","0"]]
    assert sol.numIslands2(grid) == 1