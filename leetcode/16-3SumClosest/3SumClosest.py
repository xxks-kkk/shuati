# Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
# Return the sum of the three integers. You may assume that each input would have exactly one solution.
# Example:
# Given array S = {-1, 2, 1, -4} and target = 1
# The sum that is closest to the target is 2. {-1 + 2 + 1 = 2}.

import sys

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :param nums: List[int
        :param target: int
        :return: int
        """
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)-2):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                if s == target:
                    return s
                if abs(s - target) < abs(result - target):
                    result = s
                if s < target:
                    left += 1
                elif s > target:
                    right -= 1
        return result


if __name__ == "__main__":
    sol = Solution()
    s = [-1, 2, 1, -4]
    assert sol.threeSumClosest(s, 1) == 2