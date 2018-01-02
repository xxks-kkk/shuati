# Given a collection of numbers that might contain duplicates, return all possible unique permutations.
#
# For example,
# [1,1,2] have the following unique permutations:
# [
#   [1,1,2],
#   [1,2,1],
#   [2,1,1]
# ]

class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def dfs(nums, visited, path, res):
            if len(path) == len(nums):
                res.append(path)
                return
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1] and visited[i-1]:
                    continue
                if visited[i] == 0:
                    visited[i] = 1
                    dfs(nums, visited, path + [nums[i]], res)
                    visited[i] = 0
        res = []
        nums.sort()
        visited = [0]*len(nums)
        dfs(nums, visited, [], res)
        return res

if __name__ == "__main__":
    sol = Solution()
    print(sol.permuteUnique([1,1,2]))