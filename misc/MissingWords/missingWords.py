import fileinput
import collections

def missingWords(s,t):
    slist = s.split(' ')
    tlist = t.split(' ')
    # print(slist)
    # print(tlist)
    res = []
    i = 0
    j = 0
    for i in range(len(slist)):
        if j < len(tlist) and slist[i] == tlist[j]:
            j += 1
        else:
            res.append(slist[i])
    # print(res)
    return res


if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    s = input_string_list.popleft()
    t = input_string_list.popleft()

    assert missingWords(s,t) == ['I', 'using', 'programming']