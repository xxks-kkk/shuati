# Given a set of distinct integers, nums, return all possible subsets (the power set).
#
# Note: The solution set must not contain duplicate subsets.
#
# For example,
# If nums = [1,2,3], a solution is:
#
# [
#   [3],
#   [1],
#   [2],
#   [1,2,3],
#   [1,3],
#   [2,3],
#   [1,2],
#   []
# ]

class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(res, index, path, length):
            if len(path) == length:
                res.append(path)
                return
            for i in range(index, len(nums)):
                dfs(res, i+1, path+[nums[i]], length)
        res = [[]]
        for i in range(1, len(nums)+1):
            dfs(res, 0, [], i)
        return res

if __name__ == "__main__":
    sol = Solution()
    print(sol.subsets([1,2,3]))
