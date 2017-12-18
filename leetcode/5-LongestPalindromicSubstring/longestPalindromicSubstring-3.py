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
    # DP solution
    # Running time: $O(N^2)$
    # Space: $O(N^2)$. It uses $O(N^2)$ space to store the table
    # NOTE: This solution is overtime on leetcode
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        numChars = len(s)
        # Length of the longest palindrome
        maxLength = 1
        # index where the longest palindrome begins
        palindromeBeginsAt = 0
        # boolean table to store palindrom truth
        P = [[0 for i in range(numChars)] for j in range(numChars)]

        # Trivial case: single letter palindromes
        for i in range(numChars):
            P[i][i] = 1

        # Finding palindromws of two characters
        for i in range(numChars-1):
            if s[i] == s[i+1]:
                P[i][i+1] = 1
                palindromeBeginsAt = i
                maxLength = 2

        # Finding all palindromes of length 3 to n and saving the longest
        for curr_len in range(3, numChars+1):
            for i in range(numChars - curr_len + 1):
                j = i + curr_len - 1
                # 1. The first and the last character should match
                # 2. Rest of the substring should be a palindrome
                if s[i] == s[j] and P[i+1][j-1]:
                    P[i][j] = 1
                    palindromeBeginsAt = i
                    maxLength = curr_len

        return s[palindromeBeginsAt: palindromeBeginsAt + maxLength]

if __name__ == "__main__":
    sol = Solution()
    print(sol.longestPalindrome('banana'))
