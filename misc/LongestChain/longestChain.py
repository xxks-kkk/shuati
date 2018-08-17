import collections
import fileinput


def longestChain(words):
    if len(words) == 0:
        return 0
    # invariant: a dictionary that maintains { # word: the longest chain starting from the word }
    d = {}
    max_len = 0
    # remove duplicates
    words = list(set(words))
    # We need to sort the words because we want to use a bottom-up approach to build our
    # answer from the shortest word to the longest word to maintain our invariant in `d`
    sorted_words = sorted(words, key=lambda x: len(x))
    for word in sorted_words:
        if word in d:
            continue
        d[word] = 1
    for word in sorted_words:
        # key: iterate the words from the shortest one to the longest one
        # Try input001.txt without order here to get a sense (i.e. for word in words: )
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
        assert longestChain(w) == 4
    if filename == "input001.txt":
        assert longestChain(w) == 4
    if filename == "input002.txt":
        assert longestChain(w) == 4
