# Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
#
# For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        for i in range(1,len(nums)):
            if (i%2 == 0 and nums[i] > nums[i-1]) or (i % 2 == 1 and nums[i] < nums[i-1]):
                nums[i], nums[i-1] = nums[i-1], nums[i]

if __name__ == "__main__":
    sol = Solution()
    nums = [3,5,2,1,6,4]
    sol.wiggleSort(nums)
    print(nums)