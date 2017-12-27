# Given a digit string, return all possible letter combinations that the number could represent.
#
# A mapping of digit to letters (just like on the telephone buttons) is given below.
#
# 0: "", 1: "", 2: "abc", 3: "def", 4: "ghi", 5: "jkl", 6: "mno", 7: "pqrs", 8: "tuv", 9: "wxyz"
#
# Input:Digit string "23"
# Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
# Note:
# Although the above answer is in lexicographical order, your answer could be in any order you want.

class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        mapping = ["0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        res = []
        if (len(digits) == 0):
            return res
        res.append("")
        for i, c in enumerate(digits):
            # This is actually a level-matter of BFS.
            # Very smart point is to use top element's length to determine the level of traversal
            while len(res[0]) == i:
                t = res.pop(0)
                for s in list(mapping[int(c)]):
                    res.append(t+s)
        return res


if __name__ == "__main__":
    sol = Solution()
    digits = '23'
    print(sol.letterCombinations(digits=digits))