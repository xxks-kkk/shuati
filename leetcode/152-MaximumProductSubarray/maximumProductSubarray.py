# Find the contiguous subarray within an array (containing at least one number) which has the largest product.
#
# For example, given the array [2,3,-2,4],
# the contiguous subarray [2,3] has the largest product = 6.

class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        curr_max = nums[0]
        curr_min = nums[0]
        result = nums[0]
        for i in range(1,len(nums)):
            old_max, old_min = curr_max, curr_min
            curr_max = max(old_max*nums[i], nums[i], old_min*nums[i])
            curr_min = min(old_min*nums[i], nums[i], old_max*nums[i])
            result = max(result, curr_max)
        return result

if __name__ == "__main__":
    sol = Solution()
    nums = [2,3,-2,4]
    assert sol.maxProduct(nums) == 6
    nums = [-2,-3,-4]
    assert sol.maxProduct(nums) == 12
    nums = [-2,-3,-4,-5]
    assert sol.maxProduct(nums) == 120