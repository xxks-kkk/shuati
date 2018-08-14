import fileinput
import collections
import string

def closest(s, queries):
    def findClosestNumberToTheTarget(nums, target):
        left = 0
        n = len(nums)
        right = n
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                if mid == 0:
                    return nums[mid+1]
                elif mid == n-1:
                    return nums[mid-1]
                else:
                    return nums[mid-1]  if abs(nums[mid+1] - target) >= abs(nums[mid-1] - target) else nums[mid+1]
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        return -1

    alphabet = list(string.ascii_lowercase)
    table = {}
    for a in alphabet:
        table[a] = []
    for idx,c in enumerate(list(s)):
        table[c].append(idx)
    res = []
    for q in queries:
        nums = table[s[q]]
        if len(nums) > 1:
            res.append(findClosestNumberToTheTarget(nums, q))
        else:
            res.append(-1)
    return res

if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    elements = []
    s = input_string_list.popleft()
    nquery = int(input_string_list.popleft())
    while len(input_string_list) > 0:
        elements.append(int(input_string_list.popleft()))

    name = fileinput.filename()
    if name == 'input000.txt':
        assert closest(s, elements) == [-1, 7, 5, -1]  # input001.txt
    elif name == 'input001.txt':
        assert closest(s, elements) == [0]             # input000.txt

