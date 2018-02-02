# Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
#
# Note:
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ones = twos = 0
        for num in nums:
            ones = (ones ^ num) & ~twos
            twos = (twos ^ num) & ~ones
        return ones|twos

    def singleNumber1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = b = 0
        for c in nums:
            ta = (~a&b&c) | (a&~b&~c)
            b = (~a & ~b & c) | (~a & b & ~c)
            a = ta
        return a | b

if __name__ == "__main__":
    sol = Solution()
    nums = [121,7,121,121]
    assert sol.singleNumber(nums) == 7
    assert sol.singleNumber1(nums) == 7
