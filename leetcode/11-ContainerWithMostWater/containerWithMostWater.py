class Solution(object):
    # Running time: O(n)
    # Space complexity: O(1)
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        numHeights = len(height)
        left_ptr = 0
        right_ptr = numHeights - 1
        maxArea = 0
        while left_ptr < right_ptr:
            maxArea = max(maxArea, min(height[left_ptr], height[right_ptr]) * (right_ptr - left_ptr))
            if height[left_ptr] < height[right_ptr]:
                left_ptr += 1
            else:
                right_ptr -= 1
        return maxArea

if __name__ == "__main__":
    sol = Solution()
    print(sol.maxArea([1,1]))