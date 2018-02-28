import heapq
import collections

# Enter your code here. Read input from STDIN. Print output to STDOUT
class Group:
    def __init__(self):
        self.dimension = [0]*2
        self.dropLoc = []

    def __str__(self):
        return "dimension: " + str(self.dimension) + " dropLoc: " + str(self.dropLoc)

    def __repr__(self):
        return "dimension: " + str(self.dimension) + " dropLoc: " + str(self.dropLoc)

num_paper = int(input())
groupList = []
seeAgain = False
while True:
    try:
        line = input()
    except EOFError:
        break
    stream = line.rstrip('\n').split(' ')
    if len(stream) == 2:
        if not seeAgain:
            grp = Group()
            groupList.append(grp)
        groupList[-1].dimension[0] = int(stream[0]) # m
        groupList[-1].dimension[1] = int(stream[1]) # n
        matrix = [[0] * groupList[-1].dimension[1] for _ in range(groupList[-1].dimension[0])]
        seeAgain = False
    if len(stream) == 3:
        data = list(map(int,stream))
        darkness = data[2]
        x = data[0]
        y = data[1]
        if matrix[x][y] < darkness:
            groupList[-1].dropLoc.append(data)
            matrix[x][y] = darkness

class Solution:
    def bleedingInk(self, groupList):
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

sol = Solution()
for output in sol.bleedingInk(groupList):
    print(output)