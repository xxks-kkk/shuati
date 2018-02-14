# Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
#
# The input string does not contain leading or trailing spaces and the words are always separated by a single space.
#
# For example,
# Given s = "the sky is blue",
# return "blue is sky the".
#
# Could you do it in-place without allocating extra space?
#
# Related problem: Rotate Array

class Solution:
    def reverseWords(self, str):
        """
        :type str: List[str]
        :rtype: void Do not return anything, modify str in-place instead.
        """
        def reverse(start, end):
            while start < end:
                str[start], str[end] = str[end], str[start]
                start += 1
                end -= 1
        # Three steps to reverse
        # 1. reverse the whole sequence
        reverse(0, len(str)-1)
        # 2. reverse each word
        start = i = 0
        while i < len(str):
            if str[i] == ' ':
                reverse(start, i-1)
                start = i+1
            i += 1
        # 3. reverse the last word
        # (b/c we check for ' ' in the loop and last word doesn't have space at the end)
        reverse(start, len(str)-1)

if __name__ == "__main__":
    sol = Solution()
    s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
    sol.reverseWords(s)
    #assert s == "blue is sky the"
    print(s)