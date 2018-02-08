# Given two strings S and T, determine if they are both one edit distance apart.

class Solution(object):
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) == len(t) == 0:
            return False
        if abs(len(s) - len(t)) >= 2:
            return False
        if len(s) - len(t) == 0:
            numDiff = 0
            for i in range(len(s)):
                if ord(s[i]) - ord(t[i]) != 0:
                    numDiff += 1
                if numDiff > 1:
                    return False
            if numDiff == 0:
                return False
        if abs(len(s) - len(t)) == 1:
            num = len(s) if len(s) > len(t) else len(t)
            for i in range(num-1):
                if ord(s[i]) - ord(t[i]) != 0:
                    if len(s) > len(t):
                        if s[:i] + s[i+1:] != t:
                            return False
                        else:
                            break
                    else:
                        if t[:i] + t[i+1:] != s:
                            return False
                        else:
                            break
        return True

    def isOneEditDistance1(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        m = len(s)
        n = len(t)
        if abs(m - n) > 1:
            return False
        for i in range(min(m,n)):
            if s[i] == t[i]:
                # guarantee that substrings up to i in two strings are
                # the same
                continue
            if m == n:
                # "abc","adc" case
                return s[i+1:] == t[i+1:]
            if m > n:
                # "abdc", "abc" case (extra char in s)
                return s[i+1:] == t[i:]
            else:
                # "abc", "adbc" case (extra char in t)
                return s[i:] == t[i+1:]
        # Only last char different case left "abc", "abcd"
        return m != n

if __name__ == "__main__":
    sol = Solution()
    assert sol.isOneEditDistance("abcd", "abce") == True
    assert sol.isOneEditDistance("abc", "abcd") == True
    assert sol.isOneEditDistance("abc", "adbc") == True
    assert sol.isOneEditDistance("adbc", "acb") == False
    assert sol.isOneEditDistance("", "a") == True
    assert sol.isOneEditDistance("ab", "acd") == False
    assert sol.isOneEditDistance("c","c") == False
    assert sol.isOneEditDistance("ac", "a") == True
    assert sol.isOneEditDistance("", "") == False
