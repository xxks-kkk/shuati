import fileinput
import collections

class Solution:
    def maxPoints(self, elements):
        if len(elements) == 0:
            return 0
        if len(elements) == 1:
            return elements[0]
        upper_limit = max(elements) + 1
        dict = [0] * upper_limit
        for i in elements:
            dict[i] += i
        dp = [0] * upper_limit
        dp[0] = dict[0]
        dp[1] = max(dict[0], dict[1])
        for i in range(2, upper_limit):
            dp[i] = max(dict[i] + dp[i-2], dp[i-1])
        return dp[-1]

    def maxPoints1(self, elements):
        if len(elements) == 0:
            return 0
        if len(elements) == 1:
            return elements[0]
        upper_limit = max(elements) + 1
        dict = [0] * upper_limit
        for i in elements:
            dict[i] += i
        # last := f(k-2), now := f(k-1)
        last, now = 0, 0
        for i in range(upper_limit):
            last, now = now, max(dict[i] + last, now)
        return now

if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    elements = []
    n = int(input_string_list.popleft())
    while len(input_string_list) > 0:
        elements.append(int(input_string_list.popleft()))

    sol = Solution()
    assert sol.maxPoints(elements) == 10
    assert sol.maxPoints1(elements) == 10

    ### Code below for quick tests
    elements = [1,1,1,2]
    assert sol.maxPoints(elements) == 3
    assert sol.maxPoints1(elements) == 3
    elements = [3,4,2]
    assert sol.maxPoints(elements) == 6
    assert sol.maxPoints1(elements) == 6
