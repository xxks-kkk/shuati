# Implement strStr().
#
# Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
#
# Example 1:
#
# Input: haystack = "hello", needle = "ll"
# Output: 2
# Example 2:
#
# Input: haystack = "aaaaa", needle = "bba"
# Output: -1

class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) == 0:
            return 0
        for idx, char in enumerate(haystack):
            if char == needle[0] and haystack[idx:idx + len(needle)] == needle:
                return idx
        return -1

if __name__ == "__main__":
    sol = Solution()
    assert sol.strStr("hello", "ll") == 2
    assert sol.strStr("aaaaa", "bba") == -1
    assert sol.strStr("a", "") == 0
