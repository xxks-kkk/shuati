import fileinput
import collections

### Actual logic ###
def minimalOperations(words):
    res = []
    for word in words:
        table = {}
        count = 0
        for idx, c in enumerate(word):
            if c not in table or idx - table[c] > 1:
                table[c] = idx
            else:
                count += 1
        res.append(count)
    return res


if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    elements = []
    n = int(input_string_list.popleft())
    while len(input_string_list) > 0:
        elements.append(input_string_list.popleft())

    assert minimalOperations(elements) == [0,1,1,0,1,2]