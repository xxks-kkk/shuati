# There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature.
# For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
# And we defined a friend circle is a group of students who are direct or indirect friends.
#
# Given a N*N matrix M representing the friend relationship between students in the class.
# If M[i][j] = 1, then the ith and jth students are direct friends with each other,
# otherwise not. And you have to output the total number of friend circles among all the students.
#
# Example 1:
# Input:
# [[1,1,0],
#  [1,1,0],
#  [0,0,1]]
# Output: 2
# Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
# The 2nd student himself is in a friend circle. So return 2.
#
# Example 2:
# Input:
# [[1,1,0],
#  [1,1,1],
#  [0,1,1]]
# Output: 1
# Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
# so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
#
# Note:
# N is in range [1,200].
# M[i][i] = 1 for all students.
# If M[i][j] = 1, then M[j][i] = 1.

import collections


class Solution:
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """

        def dfs(i):
            for j in range(cols):
                if M[i][j] == 1 and visited[j] == 0:
                    visited[j] = 1
                    dfs(j)

        rows = len(M)
        cols = len(M[0])
        count = 0
        # we think of M as adjacency matrix and each row represents one node in
        # the graph. Thus, we create "visited" to track which node we have visited so far
        visited = [0 for _ in range(rows)]
        for i in range(rows):
            if visited[i] == 0:
                dfs(i)
                count += 1
        return count

    def findCircleNum2(self, M):
        rows = len(M)
        cols = len(M[0])
        count = 0
        queue = collections.deque()
        visited = [0 for _ in range(rows)]
        for i in range(rows):
            if visited[i] == 0:
                queue.append(i)
                while len(queue) != 0:
                    node = queue.popleft()
                    visited[node] = 1
                    for j in range(cols):
                        if M[node][j] == 1 and visited[j] == 0:
                            queue.append(j)
                count += 1
        return count

    def findCircleNum3(self, M):
        # MAW type of union-find implementation
        def find(i):
            # Note: we don't implment compression here as it quite complex with our current definition of id
            if id[i] < 0:
                return i
            return find(id[i])

        def union(i, j):
            # We implement union-by-size
            xset = find(i)
            yset = find(j)
            if xset != yset:
                # we merge two sets only when the sets containing i and j are different sets
                if id[xset] < id[yset]:
                    # xset's size is greater than yset's (we use negative number to track the size)
                    id[xset] += id[yset]
                    id[yset] = xset
                else:
                    id[yset] += id[xset]
                    id[xset] = yset

        rows = len(M)
        # we use negative number of id[i] to represent the size of the set, which also implies that i is the root
        # if id[i] is positive, that indicates i's parent is id[i]
        # example:
        #  for a disjoint set: 0, 1, 2, {3,4,5,6,7}
        #  id looks like:
        #  | i     | 0  | 1  | 2  | 3 | 4  | 5 | 6 | 7 |
        #  |-------|----|----|----|---|----|---|---|---|
        #  | id[i] | -1 | -1 | -1 | 4 | -5 | 4 | 4 | 6 |
        id = [-1 for _ in range(rows)]
        for i in range(rows):
            for j in range(rows):
                if M[i][j] == 1 and i != j:
                    union(i, j)
        count = 0
        for i in range(rows):
            if id[i] < 0:
                count += 1
        return count

    def findCircleNum4(self, M):
        # We use segiweick implmentation of the union-find
        # link: https://algs4.cs.princeton.edu/15uf/UF.java.html
        def find(i):
            # We implement the path compression here
            while i != id[i]:
                id[i] = id[id[i]]
                i = id[i]
            return i

        def union(i,j):
            xset = find(i)
            yset = find(j)
            if xset != yset:
                if size[xset] > size[yset]:
                    size[xset] += size[yset]
                    id[yset] = xset
                else:
                    size[yset] += size[xset]
                    id[xset] = yset

        rows = len(M)
        # id[i] == i means i is the root of the set
        id = [i for i in range(rows)]
        # we use another list to keep track of the size in each set
        size = [1 for _ in range(rows)]
        for i in range(rows):
            for j in range(rows):
                if M[i][j] == 1 and i != j:
                    union(i, j)
        count = 0
        for i in range(rows):
            if id[i] == i:
                count += 1
        return count


if __name__ == "__main__":
    sol = Solution()
    assert sol.findCircleNum([[1, 1, 0], [1, 1, 0], [0, 0, 1]]) == 2
    assert sol.findCircleNum([[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]) == 1

    assert sol.findCircleNum2([[1, 1, 0], [1, 1, 0], [0, 0, 1]]) == 2
    assert sol.findCircleNum2([[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]) == 1

    assert sol.findCircleNum3([[1, 1, 0], [1, 1, 0], [0, 0, 1]]) == 2
    assert sol.findCircleNum3([[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]) == 1

    assert sol.findCircleNum4([[1, 1, 0], [1, 1, 0], [0, 0, 1]]) == 2
    assert sol.findCircleNum4([[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]) == 1