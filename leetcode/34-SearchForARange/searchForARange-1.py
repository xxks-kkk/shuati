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
        def extreme_insertion_index(nums, target, left):
            # returns leftmost (or rightmost) index at which `target` should be inserted in sorted
            # array `nums` via binary search.
            low, high = 0, len(nums) - 1
            while low <= high:
                mid = (low + high) // 2
                if nums[mid] > target or (left and target == nums[mid]):
                    high = mid - 1
                else:
                    low = mid + 1
            return low

        left_index = extreme_insertion_index(nums, target, True)
        if left_index == len(nums) or nums[left_index] != target:
            return [-1, -1]
        return [left_index, extreme_insertion_index(nums, target, False)-1]



if __name__ == "__main__":
    sol = Solution()
    assert sol.searchRange([5, 7, 7, 8, 8, 10], 8) == [3, 4]
    assert sol.searchRange([1, 2, 5, 5, 5], 5) == [2,4]
    assert sol.searchRange([], 0) == [-1, -1]
    assert sol.searchRange([2,2], 3) == [-1, -1]