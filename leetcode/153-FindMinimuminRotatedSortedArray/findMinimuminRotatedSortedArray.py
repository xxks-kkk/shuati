#!/usr/local/bin/python3

# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
#
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
#
# Find the minimum element.
#
# You may assume no duplicate exists in the array.
from typing import List

class Solution:
    def findMin(self, nums: List[int]) -> int:
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while left < right:
            if nums[left] < nums[right]:
                return nums[left]
            mid = (left + right) // 2
            if nums[mid] >= nums[left]:
                left = mid + 1
            else:
                right = mid
        return nums[left]


if __name__ == "__main__":
    sol = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]
    assert sol.findMin(nums) == 0
    nums = [2, 1]
    assert sol.findMin(nums) == 1
    nums = [1]
    assert sol.findMin(nums) == 1
    nums = [5,6,7,0,1,2,4]
    assert sol.findMin(nums) == 0
    nums = [3,4,5,1,2]
    assert sol.findMin(nums) == 1
