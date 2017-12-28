# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
#
# (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
#
# You are given a target value to search. If found in the array return its index, otherwise return -1.
#
# You may assume no duplicate exists in the array.

class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low, high = 0, len(nums)-1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < nums[high]:
                if (nums[mid] < target and target <= nums[high]):
                    low = mid + 1
                else:
                    high = mid - 1
            else:
                if (nums[low] <= target and nums[mid] > target):
                    high = mid - 1
                else:
                    low = mid + 1
        return -1


if __name__ == "__main__":
    sol = Solution()
    print(sol.search([4,5,6,7,0,1,2], 6))