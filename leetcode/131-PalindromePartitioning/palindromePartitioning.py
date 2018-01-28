# Given a string s, partition s such that every substring of the partition is a palindrome.
#
# Return all possible palindrome partitioning of s.
#
# For example, given s = "aab",
# Return
#
# [
#   ["aa","b"],
#   ["a","a","b"]
# ]

class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def dfs(index, path, res):
            if index == len(s):
                res.append(path)
                return
            for i in range(index, len(s)):
                if isPalindrome(index, i):
                    dfs(i+1, path+[s[index:i+1]], res)
        def isPalindrome(low, high):
            while low < high:
                if s[low] != s[high]:
                    return False
                low += 1
                high -= 1
            return True
        res = []
        dfs(0, [], res)
        return res


if __name__ == "__main__":
    sol = Solution()
    s = "aab"
    print(sol.partition(s))
    print(sol.partition2(s))