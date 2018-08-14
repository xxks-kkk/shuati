import fileinput
import collections

def countMatches(grid1, grid2):
    print(f'grid1: {grid1}')
    print(f'grid2: {grid2}')
    def createGrid(grid1, grid2):
        grid1vect = [[] for _ in range(len(grid1))]
        grid2vect = [[] for _ in range(len(grid2))]
        for i, row in enumerate(grid1):
            grid1vect[i].extend(map(int, list(row)))
        # We assume the size of two grids can be different
        for i, row in enumerate(grid2):
            grid2vect[i].extend(map(int, list(row)))
        return grid1vect, grid2vect

    def dfs_visit(gridvect, coordinate, n, region):
        # We assume input gridvect is square-shape. Thus, only needs n
        i, j = coordinate[0], coordinate[1]
        region[-1].add(coordinate)
        # Mark as visited
        gridvect[i][j] = 0
        if i > 0 and gridvect[i-1][j] == 1:
            dfs_visit(gridvect, (i-1,j), n, region)
        if i < n - 1 and grid1vect[i+1][j] == 1:
            dfs_visit(grid1vect, (i+1,j), n, region)
        if j > 0 and grid1vect[i][j-1] == 1:
            dfs_visit(grid1vect, (i,j-1), n, region)
        if j < n - 1 and grid1vect[i][j+1] == 1:
            dfs_visit(grid1vect, (i,j+1), n, region)

    grid1vect, grid2vect = createGrid(grid1, grid2)
    print(grid1vect)
    print(grid2vect)
    region1 = []
    region2 = []
    n = len(grid1vect)
    for i in range(n):
        for j in range(n):
            if grid1vect[i][j] == 1:
                region1.append(set())
                dfs_visit(grid1vect, (i,j), n, region1)
    print(region1)
    count = 0
    for area in region1:
        # retrieve a value from the set (e.g. area)
        for start in area: break
        region2.append(set())
        dfs_visit(grid2vect, start, len(region2), region2)
        if region2[-1] == area:
            count += 1
    print(count)
    return count


if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))

    grid1 = []
    ngrid1 = int(input_string_list.popleft())
    for i in range(ngrid1):
        grid1.append(input_string_list.popleft())

    grid2 = []
    ngrid2 = int(input_string_list.popleft())
    for i in range(ngrid2):
        grid2.append(input_string_list.popleft())

    filename = fileinput.filename()
    if filename == 'input000.txt':
        assert countMatches(grid1, grid2) == 1
    elif filename == 'input001.txt':
        assert countMatches(grid1, grid2) == 2
    elif filename == 'input002.txt':
        assert countMatches(grid1, grid2) == 0
    elif filename == 'input003.txt':
        assert countMatches(grid1, grid2) == 0
    elif filename == 'input004.txt':
        assert countMatches(grid1, grid2) == 0