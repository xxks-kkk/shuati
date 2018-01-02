# Given a collection of distinct numbers, return all possible permutations.
#
# For example,
# [1,2,3] have the following permutations:
# [
#   [1,2,3],
#   [1,3,2],
#   [2,1,3],
#   [2,3,1],
#   [3,1,2],
#   [3,2,1]
# ]

class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(nums, path, visited, res):
            if len(path) == len(nums):
                res.append(path)
                return
            for i in range(len(nums)):
                if visited[i] == 0:
                    visited[i] = 1
                    dfs(nums, path+[nums[i]], visited, res)
                    visited[i] = 0
        res = []
        visited = [0] * len(nums)
        dfs(nums, [], visited, res)
        return res

if __name__ == "__main__":
    sol = Solution()
    print(sol.permute([1,2,3]))