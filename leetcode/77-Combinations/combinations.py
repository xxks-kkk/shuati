# Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
#
# For example,
# If n = 4 and k = 2, a solution is:
#
# [
#   [2,4],
#   [3,4],
#   [2,3],
#   [1,2],
#   [1,3],
#   [1,4],
# ]

class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        def dfs(nums, index, path, res):
            if len(path) == k:
                res.append(path)
                return
            for i in range(index, len(nums)):
                dfs(nums, i+1, path+[nums[i]], res)
        res = []
        nums = range(1, n+1)
        dfs(nums, 0, [], res)
        return res

if __name__ == "__main__":
    sol = Solution()
    print(sol.combine(4,2))
