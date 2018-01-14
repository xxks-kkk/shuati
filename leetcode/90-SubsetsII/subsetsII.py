# Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
#
# Note: The solution set must not contain duplicate subsets.
#
# For example,
# If nums = [1,2,2], a solution is:
#
# [
#   [2],
#   [1],
#   [1,2,2],
#   [2,2],
#   [1,2],
#   []
# ]

class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(res, path, index, length):
            if len(path) == length:
                res.append(path)
                return
            for i in range(index, len(nums)):
                if i > index and nums[i] == nums[i-1]:
                    continue
                dfs(res, path + [nums[i]], i+1, length)
        res = []
        nums.sort()
        for i in range(len(nums)+1):
            dfs(res, [], 0, i)
        return res


if __name__ == "__main__":
    sol = Solution()
    print(sol.subsetsWithDup([1,2,2]))