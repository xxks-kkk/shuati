import collections
import fileinput


def longest_chain(w):
    if len(w) == 0:
        return 0
    # a dictionary that maintains { # word: the longest chain starting from the word }
    d = {}
    max_len = 0
    for word in w:
        d[word] = 1
    for word in w:
        for i in range(len(word)):
            new_word = str(word[:i]) + str(word[i+1:])
            if new_word in d and d[new_word] + 1 > d[word]:
                d[word] = d[new_word] + 1
        if d[word] > max_len:
            max_len = d[word]
    return max_len

if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    n = int(input_string_list.popleft())
    w = []
    while len(input_string_list) > 0:
        w.append(input_string_list.popleft())

    filename = fileinput.filename()
    if filename == "input000.txt":
        assert longest_chain(w) == 4
