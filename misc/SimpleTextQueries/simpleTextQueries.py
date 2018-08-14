import fileinput
import collections

# TODO: Need a better solution:
# Checkout this one: https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13656/An-O(N)-solution-with-detailed-explanation
def textQueries(sentences, queries):
    print(f'sentences: {sentences}')
    print(f'queries: {queries}')
    res = []
    dict1 = {}
    for i, sent in enumerate(sentences):
        sentList = sent.split()
        dict1[i] = {}
        for word in sentList:
            if word not in dict1:
                dict1[i][word] = 1
            else:
                dict1[i][word] += 1
    print(dict1)
    dict2 = {}
    for i, query in enumerate(queries):
        queryList = query.split()
        dict2[i] = {}
        res.append([])
        j = 0
        for d in dict1:
            k = 0
            while k < len(queryList):
                word = queryList[k]
                if word in dict1[d]:
                    if word not in dict2:
                        dict2[i][word] = 1
                    else:
                        dict2[i][word] += 1
                    if dict2[i][word] > dict1[d][word]:
                        break
                else:
                    break
                k += 1
            if k == len(queryList):
                res[i].append(j)
            j += 1
        if len(res[i]) == 0:
            res[i].append(-1)
    return res


if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))

    sentences = []
    nsentences = int(input_string_list.popleft())
    for i in range(nsentences):
        sentences.append(input_string_list.popleft())

    queries = []
    nqueries = int(input_string_list.popleft())
    for i in range(nqueries):
        queries.append(input_string_list.popleft())

    if fileinput.filename() == "input000.txt":
        assert textQueries(sentences, queries) == [[2], [0, 1]]
    elif fileinput.filename() == "input001.txt":
        assert textQueries(sentences, queries) == [[0, 3], [0, 2, 3]]
    elif fileinput.filename() == "input002.txt":
        assert textQueries(sentences, queries) == [[0], [-1], [0, 2]]
