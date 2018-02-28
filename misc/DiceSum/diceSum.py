
class Solution:
    def sumPossibility(self, n, m, target):
        """
        Solve the problem using DFS
        :param n: number of dices
        :param m: number of faces that each dice has
        :param target: the target value
        :return: the number of ways to get to the target
        """
        def dfs(count, n, m, target):
            if target == 0 and n == 0:
                count[0] += 1
                return
            if target < 0:
                return
            for i in range(1, m+1):
                dfs(count, n-1, m, target-i)
        count = [0]
        dfs(count, n, m, target)
        return count[0]

    def sumPossibility1(self, n, m, target):
        """
        Solve the problem using DP
        :param n:
        :param m:
        :param target:
        :return:
        """
        DP = [[0] * (target + 1) for _ in range(n+1)]
        for j in range(1, target+1):
            if j <= m:
                DP[1][j] = 1
            else:
                break
        for i in range(2, n+1):
            for j in range(2, target+1):
                for k in range(1, m+1):
                    if k < j:
                        DP[i][j] += DP[i-1][j-k]
        return DP[n][target]


if __name__ == "__main__":
    sol = Solution()
    assert sol.sumPossibility(2,4,1) == 0
    assert sol.sumPossibility(2,2,3) == 2
    assert sol.sumPossibility(3,6,8) == 21
    assert sol.sumPossibility(2,4,5) == 4
    assert sol.sumPossibility(3,4,5) == 6

    assert sol.sumPossibility1(2,4,1) == 0
    assert sol.sumPossibility1(2,2,3) == 2
    assert sol.sumPossibility1(3,6,8) == 21
    assert sol.sumPossibility1(2,4,5) == 4
    assert sol.sumPossibility1(3,4,5) == 6