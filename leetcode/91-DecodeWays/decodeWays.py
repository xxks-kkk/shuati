# A message containing letters from A-Z is being encoded to numbers using the following mapping:
#
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
# Given an encoded message containing digits, determine the total number of ways to decode it.
#
# For example,
# Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
#
# The number of ways decoding "12" is 2.

class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s or not len(s):
            return 0
        n = len(s)
        dp = [0] * (n+1)
        dp[0] = 1
        dp[1] = 1 if s[0] != '0' else 0
        for i in range(2, n+1):
            first = int(s[i-1:i])
            second = int(s[i-2:i])
            if first >= 1 and first <= 9:
                dp[i] += dp[i-1]
            if second >= 10 and second <= 26:
                dp[i] += dp[i-2]
        return dp[n]

    # space complexity: O(1)
    def numDecodingsOpt1(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s or not len(s):
            return 0
        n = len(s)
        prev = 1
        curr = 1 if s[0] != '0' else 0
        for i in range(2, n+1):
            tmp = 0
            first = int(s[i-1:i])
            second = int(s[i-2:i])
            if first >= 1 and first <= 9:
                tmp += curr
            if second >= 10 and second <= 26:
                tmp += prev
            curr, prev = tmp, curr
        return curr

if __name__ == "__main__":
    sol = Solution()
    assert sol.numDecodings("123") == 3
    assert sol.numDecodingsOpt1("123") == 3
