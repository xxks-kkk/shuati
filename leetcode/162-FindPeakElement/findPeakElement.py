# A peak element is an element that is greater than its neighbors.
#
# Given an input array where num[i] != num[i+1], find a peak element and return its index.
#
# The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
#
# You may imagine that num[-1] = num[n] = -infinity.
#
# For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
#
# Note:
# Your solution should be in logarithmic complexity.

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # O(n) solution
        for i in range(0, len(nums)-1):
            if nums[i] > nums[i+1]:
                return i
        return len(nums)-1

    def findPeakElement1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        while left != right:
            mid = (left + right) // 2
            if nums[mid] <= nums[mid+1]:
                left = mid + 1
            else:
                right = mid
        return right


if __name__ == "__main__":
    sol = Solution()
    assert sol.findPeakElement([1, 2, 3, 1]) == 2
    assert sol.findPeakElement([1,2]) == 1
    assert sol.findPeakElement([1]) == 0

    assert sol.findPeakElement1([1, 2, 3, 1]) == 2
    assert sol.findPeakElement1([1,2]) == 1
    assert sol.findPeakElement1([1]) == 0

