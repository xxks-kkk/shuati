# Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
#
# For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

class Solution:
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        result = []
        nums.append(upper+1)
        pre = lower - 1
        for num in nums:
           if (num == pre + 2):
               result.append(str(num-1))
           elif (num > pre + 2):
               result.append(str(pre + 1) + "->" + str(num -1))
           pre = num
        return result


if __name__ == "__main__":
    sol = Solution()
    assert sol.findMissingRanges([0, 1, 3, 50, 75], 0, 99) == ["2", "4->49", "51->74", "76->99"]
    assert sol.findMissingRanges([],1,1) == ["1"]
    assert sol.findMissingRanges([-1], -2, -1) == ["-2"]