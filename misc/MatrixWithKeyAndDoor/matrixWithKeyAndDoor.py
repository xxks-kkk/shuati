import collections

class Coordinate:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def constructPath(list_of_coordinate):
    res = ""
    for i in list_of_coordinate:
        res += "(" + str(i.x) + "," + str(i.y) + ")"  + "\n"
    return res

class Solution:
    def shortestPath(self, board):
        def traverse(board, x, y, keyRing, visited, path, shortestPathToGoal):
            # Outside board or already visited
            if x < 0 or x >= len(board) or y < 0 or y >= len(board[0]) or visited[x][y]:
                return
            cell = board[x][y]
            if cell == '0': # water
                return
            if cell == '3': # goal
                shortestPathToGoal.clear()
                shortestPathToGoal.extend(path)
                shortestPathToGoal.append(Coordinate(x,y))
                return # return to look for an alternative path
            if not len(shortestPathToGoal) == 0 and len(path) + 2 >= len(shortestPathToGoal):
                return # shorter (or equal) path already found
            if cell >= 'A' and cell <= 'Z':
                if cell.lower() not in keyRing or keyRing[cell.lower()] == 0:
                    return # missing key
                else:
                    keyRing[cell.lower()] -= 1
            if cell >= 'a' and cell <= 'z':
                keyRing[cell] += 1 # key
                # With the new key, we can re-visit the previously walked area
                visited = [[0] * len(board[0]) for _ in range(len(board))]
            visited[x][y] = 1
            path.append(Coordinate(x,y))
            traverse(board, x+1, y, keyRing, visited, path, shortestPathToGoal)
            traverse(board, x-1, y, keyRing, visited, path, shortestPathToGoal)
            traverse(board, x, y+1, keyRing, visited, path, shortestPathToGoal)
            traverse(board, x, y+1, keyRing, visited, path, shortestPathToGoal)
            path.pop()
            visited[x][y] = False
        visited = [[0] * len(board[0]) for _ in range(len(board))]
        shortestPathToGoal = []
        path = collections.deque()
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == '2':
                    traverse(board, i, j, collections.Counter(), visited, path, shortestPathToGoal)
        return constructPath(shortestPathToGoal)

if __name__ == "__main__":
    sol = Solution()
    board1 = ['02111',
             '01001',
             '01003',
             '01001',
             '01111']
    print(sol.shortestPath(board1))
    board2 = ['02a11',
              '0100A',
              '01003',
              '01001',
              '01111']
    print(sol.shortestPath(board2))
