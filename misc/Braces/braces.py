import fileinput
import collections

# Similar to leetcode 20: Valid Parentheses
# Complete the braces function below.
def braces(values):
    def check(s):
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
    res = []
    for val in values:
        braceList = list(val)
        if check(braceList):
            res.append('YES')
        else:
            res.append('NO')
    return res

if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    n = int(input_string_list.popleft())
    values = []
    while len(input_string_list) > 0:
        values.append(input_string_list.popleft())
    braces(values)