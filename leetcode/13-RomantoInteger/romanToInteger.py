class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        i, res = 0, 0
        while i < len(s):
            s1 = dict[s[i]]
            if i + 1 < len(s):
                s2 = dict[s[i+1]]
                if s1 >= s2:
                    res += s1
                    i += 1
                else:
                    res = res + s2 - s1
                    i = i + 2
            else:
                res += s1
                i += 1
        return res

if __name__ == "__main__":
    sol = Solution()
    assert sol.romanToInt("MCMXCVI") == 1996