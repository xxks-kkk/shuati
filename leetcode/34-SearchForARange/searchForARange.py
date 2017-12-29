# Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# If the target is not found in the array, return [-1, -1].
#
# For example,
# Given [5, 7, 7, 8, 8, 10] and target value 8,
# return [3, 4].

class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        def extreme_insertion_index(nums, target, right):
            # returns leftmost (or rightmost) index at which `target` should be inserted in sorted
            # array `nums` via binary search.
            low, high = 0, len(nums) - 1
            while low <= high:
                mid = (low + high) // 2
                if nums[mid] < target or (right and target == nums[mid]):
                    low = mid + 1
                else:
                    high = mid - 1
            return high

        right_index = extreme_insertion_index(nums, target, True)
        if right_index == -1 or nums[right_index] != target:
            return [-1, -1]
        return [extreme_insertion_index(nums, target, False)+1, right_index]



if __name__ == "__main__":
    sol = Solution()
    assert sol.searchRange([5, 7, 7, 8, 8, 10], 8) == [3, 4]
    assert sol.searchRange([1, 2, 5, 5, 5], 5) == [2,4]
    assert sol.searchRange([], 0) == [-1, -1]