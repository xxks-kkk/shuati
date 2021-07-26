import fileinput
import collections

def entryTime(s, keypad):
    """

    :param s: each character is a number in the inclusive range from 1 to 9
    :param keypad: consisting of a permutation of the nine distinct numbers from 1 to 9 describing the ordering of the
    3x3 keypad's digits row-by-row from left to right and top to bottom.
    :return: an interger denoting the minimum amount of time it takes to type string s (i.e., the amount of time spent
    switching between keys)
    """
    pass

if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))

    s = input_string_list.popleft()
    keypad = input_string_list.popleft()

    filename = fileinput.filename()
    if filename == 'input000.txt':
        entryTime(s, keypad)

