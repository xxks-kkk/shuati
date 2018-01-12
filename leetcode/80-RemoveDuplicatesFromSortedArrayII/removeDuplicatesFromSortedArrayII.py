# Follow up for "Remove Duplicates":
# What if duplicates are allowed at most twice?
#
# For example,
# Given sorted array nums = [1,1,1,2,2,3],
#
# Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
# It doesn't matter what you leave beyond the new length.


class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n < 3:
            return n
        end = 1
        for i in range(2, n):
            if nums[i] != nums[end-1]:
                end += 1
                nums[end] = nums[i]
        return end + 1


if __name__ == "__main__":
    sol = Solution()
    a = [1,1,1,2,2,3]
    n = sol.removeDuplicates(a)
    assert n == 5
    assert a[:n] == [1,1,2,2,3]
    a = [1]
    n = sol.removeDuplicates(a)
    assert n == 1
    assert a[:n] == [1]