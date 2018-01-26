# Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
# For example,
# Given [3,2,1,5,6,4] and k = 2, return 5.
#
# Note:
# You may assume k is always valid, 1 <= k <= array's length.

import heapq

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        return nums[-k]

    def findKthLargest1(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heapq.heapify(nums)
        for _ in range(len(nums)-k):
            heapq.heappop(nums)
        return heapq.heappop(nums)

    def findKthLargest2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        def partition(nums, left, right):
            pivot = nums[left]
            l, r = left + 1, right
            while l <= r:
                if nums[l] < pivot and nums[r] > pivot:
                    nums[l], nums[r] = nums[r], nums[l]
                    l += 1
                    r -= 1
                if nums[l] >= pivot: l += 1
                if nums[r] <= pivot: r -= 1
            nums[left], nums[r] = nums[r], nums[left]
            return r
        left, right = 0, len(nums) - 1
        while True:
            pos = partition(nums, left, right)
            if pos == k - 1:
                return nums[k-1]
            elif pos > k - 1:
                right = pos - 1
            else:
                left = pos + 1

if __name__ == "__main__":
    sol = Solution()
    nums = [3,2,1,5,6,4]
    k = 2
    assert sol.findKthLargest(nums, k) == 5
    assert sol.findKthLargest1(list(nums), k) == 5
    assert sol.findKthLargest2(nums, k) == 5