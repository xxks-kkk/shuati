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
    # The running time: O(K*N) where K is the maxLength.
    # For loop takes O(N). The string comparison check theoretically is O(N)
    # but is amortized to O(1) by the implementation of operation (i.e., optimized
    # by the interpreter's C code). The slicing and reversing of the string is
    # O(h) where h is the sliced/reversed string length. Here, h = k.
    def longestPalindrome(self, s):
        if len(s) == 0:
            return 0
        maxLength = 1
        palindromeBeginsAt = 0
        numChars = len(s)
        for i in range(numChars):
            # Test for P + 2 case
            if i - maxLength >= 1 and s[i-maxLength-1: i+1] == s[i-maxLength-1:i+1][::-1]:
                palindromeBeginsAt = i - maxLength - 1
                maxLength += 2
            # Test for P + 1 case
            elif i - maxLength >= 0 and s[i-maxLength: i+1] == s[i-maxLength: i+1][::-1]:
                palindromeBeginsAt = i - maxLength
                maxLength += 1
        return s[palindromeBeginsAt: palindromeBeginsAt+maxLength]

if __name__ == "__main__":
    sol = Solution()
    print(sol.longestPalindrome('banana'))
