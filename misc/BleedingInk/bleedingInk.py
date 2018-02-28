import heapq
import collections

# BFS achieves best test case pass rate: 10/12. The rest two are time out.
# DFS achieves test case pass rate: 8/12. The rest are time out.
# Direct calculation makes error on basic test case.

# TODO: 1. Develop more test cases 2. Figure out bottle neck for the solution

class Group:
    """
    Represents a group of input:

    Group 1:
    3 4 # 第一张纸的高和宽
    2 # 第一张纸的墨水点数
    0 0 255 # 第一张纸上第一个墨水点的row col value
    1 2 255 # 第一张纸上第二个墨水点的row col value

    Group 2:
    5 6
    4
    1 0 10
    2 2 9
    2 3 5
    4 2 9
    """
    def __init__(self):
        self.dimension = [0]*2
        self.dropLoc = []

    def __str__(self):
        return "dimension: " + str(self.dimension) + " dropLoc: " + str(self.dropLoc)

    def __repr__(self):
        return "dimension: " + str(self.dimension) + " dropLoc: " + str(self.dropLoc)

class Solution:
    def bleedingInk(self, groupList):
        # Time complexity: O(m1 * n1 * # of drops + m2 * n2 * # of drops + ...)
        # Space complexity: O(# of matrices) (we don't really need matrix variable)
        res = []
        for group in groupList:
            summation = 0
            m = group.dimension[0]
            n = group.dimension[1]
            matrix = [[0] * n for _ in range(m)]
            for i in range(m):
                for j in range(n):
                    vals = []
                    dropLoc = group.dropLoc
                    for drop in dropLoc:
                        x = drop[0]
                        y = drop[1]
                        darkness = drop[2]
                        vals.append(darkness - abs(i-x) - abs(j-y))
                    matrix[i][j] = max(vals)
                    summation += matrix[i][j]
            res.append(summation)
        return res

    def bleedingInk2(self, groupList):
        """
        Implement DFS approach
        :param groupList: A list of groups
        :return: A list contains summation of darkness for each group
        """
        def dfs(matrix, i, j, darkness):
            if 0 <= i < len(matrix) and 0 <= j < len(matrix[0]) and darkness > matrix[i][j]:
                matrix[i][j] = darkness
                dfs(matrix, i-1, j, darkness-1)
                dfs(matrix, i+1, j, darkness-1)
                dfs(matrix, i, j-1, darkness-1)
                dfs(matrix, i, j+1, darkness-1)
        res = []
        for group in groupList:
            m = group.dimension[0]
            n = group.dimension[1]
            matrix = [[0] * n for _ in range(m)]
            dropLoc = group.dropLoc
            heap = []
            for drop in dropLoc:
                x = drop[0]
                y = drop[1]
                darkness = drop[2]
                heap.append((-darkness, [x,y]))
            heapq.heapify(heap)
            while heap:
                darkness, locs = heapq.heappop(heap)
                darkness = -darkness
                x = locs[0]
                y = locs[1]
                if matrix[x][y] < darkness:
                    dfs(matrix, x, y, darkness)
            res.append(sum([sum(matrix[i]) for i in range(m)]))
        return res

    def bleedingInk3(self, groupList):
        """
        Implement BFS approach
        :param groupList: A list of groups
        :return: A list contains summation of darkness for each group
        """
        # Time complexity: O(4 * d) where d = min(m, n, darkness) (d也就是递归深度)
        # Space complexity: same as time complexity
        res = []
        for group in groupList:
            m = group.dimension[0]
            n = group.dimension[1]
            matrix = [[0] * n for _ in range(m)]
            dropLoc = group.dropLoc
            heap = []
            for drop in dropLoc:
                x = drop[0]
                y = drop[1]
                darkness = drop[2]
                heap.append((-darkness, [x,y]))
            heapq.heapify(heap)
            queue = collections.deque()
            while heap:
                darkness, locs = heapq.heappop(heap)
                darkness = -darkness
                x = locs[0]
                y = locs[1]
                queue.appendleft((darkness, x, y))
                while queue:
                    darkness, x, y = queue.pop()
                    if matrix[x][y] < darkness:
                        matrix[x][y] = darkness
                        if 0 <= x - 1:
                            queue.appendleft((darkness-1, x-1,y))
                        if x+1 < m:
                            queue.appendleft((darkness-1, x+1, y))
                        if y+1 < n:
                            queue.appendleft((darkness-1, x, y+1))
                        if y-1 >= 0:
                            queue.appendleft((darkness-1, x, y-1))
            res.append(sum([sum(matrix[i]) for i in range(m)]))
        return res


if __name__ == "__main__":
    sol = Solution()

    with open("input001.txt", 'r') as f:
        content = f.readlines()
        input001 = [line.rstrip('\n') for line in content]
        num_paper = int(input001[0])
        groupList = []
        seeAgain = False
        for line in input001[1:]:
            stream = line.split(' ')
            if len(stream) == 2:
                if not seeAgain:
                    grp = Group()
                    groupList.append(grp)
                groupList[-1].dimension[0] = int(stream[0]) # m
                groupList[-1].dimension[1] = int(stream[1]) # n
                matrix = [[0] * groupList[-1].dimension[1] for _ in range(groupList[-1].dimension[0])]
                seeAgain = False
            if len(stream) == 3:
                data = list(map(int, stream))
                darkness = data[2]
                x = data[0]
                y = data[1]
                # If multiple drops at the same spot, we only keep the drop with largest darkness value.
                if matrix[x][y] < darkness:
                    groupList[-1].dropLoc.append(data)
                    matrix[x][y] = darkness
    f.close()
    print(input001)
    print(groupList)

    with open("output001.txt", 'r') as f:
        content = f.readlines()
        output001 = [line.rstrip('\n') for line in content]
        for output, target in zip(sol.bleedingInk(groupList), output001):
            assert output == int(target)
        for output, target in zip(sol.bleedingInk2(groupList), output001):
            assert output == int(target)
        for output, target in zip(sol.bleedingInk3(groupList), output001):
            assert output == int(target)
    f.close()