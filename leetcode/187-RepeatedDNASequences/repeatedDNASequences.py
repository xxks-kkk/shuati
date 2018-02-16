# All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
#
# Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
#
# For example,
#
# Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
#
# Return:
# ["AAAAACCCCC", "CCCCCAAAAA"].

class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        dict = {}
        res = []
        for i in range(len(s)):
            string = s[i:i+10]
            if len(string) != 10:
                break
            if string in dict and dict[string] != 1:
                res.append(string)
                # We already add the key to the result set, and we set the
                # value to 1
                dict[string] = 1
            elif string not in dict:
                # We haven't seen the pattern before, add it to the dictionary
                dict[string] = 0
        return res

if __name__ == "__main__":
    sol = Solution()
    s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
    assert set(sol.findRepeatedDnaSequences(s)) == set(["AAAAACCCCC", "CCCCCAAAAA"])
    s = "AAAAAAAAAAAA"
    assert sol.findRepeatedDnaSequences(s) == ["AAAAAAAAAA"]
