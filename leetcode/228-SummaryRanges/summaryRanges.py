# Given a sorted integer array without duplicates, return the summary of its ranges.
#
# Example 1:
# Input: [0,1,2,4,5,7]
# Output: ["0->2","4->5","7"]
# Example 2:
# Input: [0,2,3,4,6,8,9]
# Output: ["0","2->4","6","8->9"]

class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        res = []
        i = 0
        while i < len(nums):
            a = nums[i]
            while(i+1 < len(nums) and nums[i+1] - nums[i] == 1):
                i += 1
            if a != nums[i]:
                res.append(str(a) + "->" + str(nums[i]))
            else:
                res.append(str(a))
            i += 1
        return res

if __name__ == "__main__":
    sol = Solution()
    assert sol.summaryRanges([0,1,2,4,5,7]) == ["0->2","4->5","7"]
    assert sol.summaryRanges([0,2,3,4,6,8,9]) == ["0","2->4","6","8->9"]