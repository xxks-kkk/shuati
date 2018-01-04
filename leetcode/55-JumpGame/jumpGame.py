# Given an array of non-negative integers, you are initially positioned at the first index of the array.
#
# Each element in the array represents your maximum jump length at that position.
#
# Determine if you are able to reach the last index.
#
# For example:
# A = [2,3,1,1,4], return true.
#
# A = [3,2,1,0,4], return false.


class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lastPos = len(nums) - 1
        for i in range(len(nums)-1, -1, -1):
            if i + nums[i] >= lastPos:
                lastPos = i
        return lastPos == 0

if __name__ == "__main__":
    sol = Solution()
    assert sol.canJump([2,3,1,1,4]) == True
    assert sol.canJump([3,2,1,0,4]) == False