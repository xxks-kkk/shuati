# Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
#
# Example 1:
# Input:nums = [1,1,1], k = 2
# Output: 2
# Note:
# The length of the array is in range [1, 20,000].
# The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

import collections

class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count = collections.Counter()
        count[0] = 1
        cnt = sum = 0
        for num in nums:
            sum += num
            cnt += count[sum - k]
            count[sum] += 1
        return cnt


if __name__ == "__main__":
    sol = Solution()
    nums = [1,1,1]
    assert sol.subarraySum(nums, k=2) == 2
    assert sol.subarraySum(nums, k=3) == 1
    nums = [0,0,0,0,0,0,0,0,0,0]
    assert sol.subarraySum(nums, 0) == 55
    nums = [0,1,-1,1]
    assert sol.subarraySum(nums, 1) == 5
