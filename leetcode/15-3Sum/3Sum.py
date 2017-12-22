# Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
# Find all unique triplets in the array which gives the sum of zero.
#
# Note: The solution set must not contain duplicate triplets.
#
# For example, given array S = [-1, 0, 1, 2, -1, -4],
#
# A solution set is:
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]

class Solution(object):
    def threeSum2(self, nums):
        nums = sorted(nums)
        re = []
        i = 0
        while i < len(nums)-2:
            if i == 0 or (i > 0 and nums[i] != nums[i-1]):
                lo = i + 1
                hi = len(nums)-1
                target = -nums[i]
                while lo < hi:
                    if nums[lo] + nums[hi] == target:
                        re.append([nums[i], nums[lo], nums[hi]])
                        if lo < hi and nums[lo] == nums[lo+1]:
                            lo = lo + 1
                        elif lo < hi and nums[hi] == nums[hi-1]:
                            hi = hi - 1
                        lo = lo + 1
                        hi = hi - 1

                    elif nums[lo] + nums[hi] < target:
                        lo = lo + 1
                    else:
                        hi = hi - 1
            i = i + 1
        return re

    def threeSum3(self, nums):
        res = []
        nums.sort()
        # -2 because we need to leave space for left and right
        for i in range(len(nums)-2):
            if i == 0 or (i > 0 and nums[i] != nums[i - 1]):
                left = i+1
                right = len(nums)-1
                while left < right:
                    s = nums[i] + nums[left] + nums[right]
                    if s < 0:
                        left += 1
                    elif s > 0:
                        right -= 1
                    else:
                        res.append([nums[i], nums[left], nums[right]])
                        while left < right and nums[left] == nums[left+1]:
                            left += 1
                        while left < right and nums[right] == nums[right-1]:
                            right -= 1
                        left += 1
                        right -= 1
        return res


if __name__ == "__main__":
    sol = Solution()
    s = [-1, 0, 1, 2, -1, -4]
    print(sol.threeSum2(s))
    print(sol.threeSum3(s))