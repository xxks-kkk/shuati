# Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
#
# Input: "babad"
# Output: "bab"
# Note: "aba" is also a valid answer.
#
# Input: "cbbd"
# Output: "bb"


# TODO: O(n) algorithm called Manacher's algorithm
class Solution:
    # Running time: $O(N^2)$ but the algorithm only uses constant space
    def longestPalindrome(self, s):
        def expandAroundCenter(s, left, right):
            i = left
            j = right
            while(i >= 0 and j < len(s) and s[i] == s[j]):
                i -= 1
                j += 1
            return j - i - 1
        start = 0
        end = 0
        for i in range(len(s)):
            # Assume odd length
            len1 = expandAroundCenter(s, i, i)
            # Assume even length
            len2 = expandAroundCenter(s, i, i+1)
            maxLength = max(len1, len2)
            if (maxLength > end - start):
                # integer division // is enforced in Python3
                start = i - (maxLength - 1) // 2
                end = i + maxLength // 2
        return s[start: end+1]


if __name__ == "__main__":
    sol = Solution()
    print(sol.longestPalindrome('banana'))
    print(sol.longestPalindrome('cbbd'))
