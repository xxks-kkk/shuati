# Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal,
# where a move is incrementing n - 1 elements by 1.
#
# Example:
#
# Input:
# [1,2,3]
#
# Output:
# 3
#
# Explanation:
# Only three moves are needed (remember each move increments two elements):
#
# [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        count = 0
        for i in range(len(nums)-1, 0, -1):
            count += nums[i] - nums[0]
        return count

    def minMoves1(self, nums):
        nums.sort()
        moves = 0
        for i in range(1, len(nums)):
            diff = moves + nums[i] - nums[i-1]
            nums[i] += moves
            moves += diff
        return moves

    def minMoves2(self, nums):
        moves = 0
        min_val = 2147483647
        for num in nums:
            moves += num
            min_val = min(min_val, num)
        return moves - min_val * len(nums)

    def minMoves3(self, nums):
        moves = 0
        min_val = 2147483647
        for num in nums:
            if min_val > num:
                min_val = num
        for num in nums:
            moves += (num - min_val)
        return moves


if __name__ == "__main__":
    sol = Solution()
    nums = [1,2,3]
    assert sol.minMoves(list(nums)) == 3
    assert sol.minMoves2(nums) == 3
    assert sol.minMoves3(nums) == 3

    nums = [13,18, 3,10,35,68,50,20,50]
    assert sol.minMoves1(list(nums)) == 240
