# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
# The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dictionary = {"(": ")",
                      "{": "}",
                      "[": "]"}
        stack = []
        for c in s:
            if c in dictionary:
                stack.append(c)
            elif len(stack) == 0 or dictionary[stack.pop()] != c:
                return False
        return len(stack) == 0

if __name__ == "__main__":
    sol = Solution()
    s = '()'
    assert sol.isValid(s) == True

    s = '()[]{}'
    assert sol.isValid(s) == True

    s = '(]'
    assert sol.isValid(s) == False

    s = '([)]'
    assert  sol.isValid(s) == False