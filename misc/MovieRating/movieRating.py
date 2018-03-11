import fileinput
import collections

class Solution:
    def movieRating(self, elements):
        # last := f(k-2), now := f(k-1)
        # Initialize like this to handle the test case: [-1,-2,-3,-4]
        last = elements[0]
        now = max(elements[0], elements[1], elements[0] + elements[1])
        skipped = False if now == elements[1] or now == elements[0] + elements[1] else True
        for num in elements[2:]:
            if last < num + now and not skipped:
                last, now = now, num + now
            elif last > num + now and not skipped:
                skipped = True
                last, now = now, now
            elif skipped:
                last, now = now, num + now
                skipped = False
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
    assert sol.movieRating(elements) == 5


    ### Code below for quick tests
    elements = [1,2,-3,2,1]
    assert sol.movieRating(elements) == 6 # [1,2,2,1]

    elements = [1,2,-1,-3,2,1]
    assert sol.movieRating(elements) == 5 # [1,2,-1,2,1]

    elements = [-1, -2, -3, -4]
    assert sol.movieRating(elements) == -4 # [-1,-3]

    elements = [-5,9,-1,-3,4,5]
    assert sol.movieRating(elements) == 17 # [9,-1,4,5]