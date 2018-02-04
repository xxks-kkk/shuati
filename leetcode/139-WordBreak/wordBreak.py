# Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
#
# For example, given
# s = "leetcode",
# dict = ["leet", "code"].
#
# Return true because "leetcode" can be segmented as "leet code".
#
# UPDATE (2017/1/4):
# The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        def wordBreakHelper(s, wordDict, start, dp):
            if start == len(s):
                return True
            if dp[start] != -1:
                return dp[start]
            for end in range(start+1, len(s) + 1):
                if s[start:end] in wordDict and wordBreakHelper(s, wordDict, end, dp):
                    return True
            dp[start] = False
            return False
        dp = [-1] * len(s)
        return wordBreakHelper(s, set(wordDict), 0, dp)

    def wordBreak1(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        wordDict = set(wordDict)
        queue = []
        queue.insert(0, 0)
        visited = [0] * len(s)
        while queue:
            start = queue.pop()
            if not visited[start]:
                for end in range(start+1, len(s) + 1):
                    if s[start:end] in wordDict:
                        queue.insert(0, end)
                        if end == len(s):
                            return True
            visited[start] = 1
        return False

    def wordBreak2(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        wordDict = set(wordDict)
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        for i in range(1, len(s)+1):
            for j in range(0, i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = 1
                    break
        return True if dp[-1] else False

if __name__ == "__main__":
    sol = Solution()
    s = "leetcode"
    wordDict = ["leet", "code"]
    assert sol.wordBreak(s, wordDict) == True
    s = "ssa"
    wordDict = ["s", "sa"]
    assert sol.wordBreak1(s, wordDict) == True
    assert sol.wordBreak2(s, wordDict) == True