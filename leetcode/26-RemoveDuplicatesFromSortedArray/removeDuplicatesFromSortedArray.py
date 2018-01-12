# Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.
#
# Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
#
# Example:
#
# Given nums = [1,1,2],
#
# Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
# It doesn't matter what you leave beyond the new length.

class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        n = len(nums)
        slow, fast = 0, 0
        while fast < n:
            if nums[fast] == nums[slow]:
                fast += 1
            else:
                slow += 1
                nums[slow] = nums[fast]
                fast += 1
        return slow + 1

    def removeDuplicates2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n < 2:
            return n
        end = 0
        for i in range(1, n):
            if nums[i] == nums[end]:
                continue
            else:
                end += 1
                nums[end] = nums[i]
        return end + 1

if __name__ == "__main__":
    sol = Solution()
    a = [1,1,2]
    n = sol.removeDuplicates(a)
    assert n == 2
    assert a[:n] == [1,2]

