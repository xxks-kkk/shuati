# Follow up for "Search in Rotated Sorted Array":
# What if duplicates are allowed?
#
# Would this affect the run-time complexity? How and why?
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
#
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
#
# Write a function to determine if a given target is in the array.
#
# The array may contain duplicates.

class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        left, right = 0, len(nums)-1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < nums[right]:
                # case: [5 6 7 0 1 2 4] target: 2
                if nums[mid] < target and target <= nums[right]:
                    left = mid + 1
                # case: [6 7 0 1 2 4 5] target: 0
                # case: [6 7 0 1 2 4 5] target: 7
                else: # nums[mid] >= target or target > nums[right]
                    right = mid - 1
            elif nums[mid] > nums[right]:
                # case: [4 5 6 7 0 1 2] target: 5
                if nums[left] <= target and nums[mid] > target:
                    right = mid - 1
                # case: [4 5 6 7 0 1 2] target: 1
                # case: [2 4 5 6 7 0 1] target: 7
                else: # nums[left] > target or target >= nums[mid]
                    left = mid + 1
            else: # nums[mid] == nums[right] AND nums[mid] != target
                # case: [3 1 1]   target: 3
                # case: [1 1 3 1] target: 3
                right -= 1
        return False

if __name__ == "__main__":
    sol = Solution()
    assert sol.search([1,1,3],3) == True
    assert sol.search([1,3],1) == True
    assert sol.search([1,3],3) == True
    assert sol.search([1,3,5],5) == True

