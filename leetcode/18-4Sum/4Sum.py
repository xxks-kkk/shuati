# Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
# Find all unique quadruplets in the array which gives the sum of target.
#
# Note: The solution set must not contain duplicate quadruplets.
#
# For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
#
# A solution set is:
# [
#   [-1,  0, 0, 1],
#   [-2, -1, 1, 2],
#   [-2,  0, 0, 2]
# ]

class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        for i in range(len(nums)-3):
            if i == 0 or (i > 0 and nums[i] != nums[i-1]):
                for j in range(i+1, len(nums)-2):
                    if j == i+1 or (j > i+1 and nums[j] != nums[j-1]):
                        left = j + 1
                        right = len(nums) - 1
                        while left < right:
                            s = nums[i] + nums[j] + nums[left] + nums[right]
                            if s < target:
                                left += 1
                            elif s > target:
                                right -= 1
                            else:
                                res.append([nums[i], nums[j], nums[left], nums[right]])
                                while left < right and nums[left] == nums[left+1]:
                                    left += 1
                                while left < right and nums[right] == nums[right - 1]:
                                    right -= 1
                                left += 1
                                right -= 1
        return res

    def fourSum2(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def findNsum(nums, target, N, result, results):
            # early termination. Here, we assume input nums is sorted in ascending order
            # target < nums[0] * N means that target is smaller than the smallest possible sum that the given sequence can have.
            if len(nums) < N or N < 2 or target < nums[0] * N or target > nums[-1] * N:
                return
            if N == 2:  # two pointers solve sorted 2-sum problem
                left = 0
                right = len(nums) - 1
                while left < right:
                    s = nums[left] + nums[right]
                    if s < target:
                        left += 1
                    elif s > target:
                        right -= 1
                    else:
                        results.append(result + [nums[left], nums[right]])
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        left += 1
                        right -= 1
            else:  # recursively reduce N
                for i in range(len(nums) - N + 1):
                    if i == 0 or (i > 0 and nums[i - 1] != nums[i]):
                        findNsum(nums[i + 1:], target - nums[i], N - 1, result + [nums[i]], results)

        results = []
        findNsum(sorted(nums), target, 4, [], results)
        return results


if __name__ == "__main__":
    sol = Solution()
    s = [1, 0, -1, 0, -2, 2]
    print('fourSum', sol.fourSum(s, 0))
    print('fourSum2', sol.fourSum2(s, 0))

    s1 = [0,0,0,0]
    print('fourSum', sol.fourSum(s1, 0))

    s2 = [-3,-2,-1,0,0,1,2,3]
    print('fourSum', sol.fourSum(s2, 0))