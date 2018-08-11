import fileinput
import collections

# 6 <-- number of nodes
# 5 <--- [start] u
# 1
# 2
# 2
# 1
# 3
# 5 <--- [start] v
# 2
# 4
# 5
# 3
# 6
# 6 <--- number of values
# 2 <--- [start] values
# 2
# 6
# 5
# 4
# 3
# 5 <--- number of query
# 1
# 4
# 5
# 6
# 2

class Vetex:
    def __init__(self, n, x):
        self.n = n # numbering
        self.val = x

def is_prime(n):
  if n == 2 or n == 3: return True
  if n < 2 or n%2 == 0: return False
  if n < 9: return True
  if n%3 == 0: return False
  r = int(n**0.5)
  f = 5
  while f <= r:
    if n%f == 0: return False
    if n%(f+2) == 0: return False
    f +=6
  return True

def primeQuery(n, u, v, values, queries):
    # note: the tree here is a generic term. It doesn't
    # necessarily contain one parent for a given node.
    # print(f'n: {n}')
    # print(f'u: {u}')
    # print(f'v: {v}')
    # print(f'values: {values}')
    # print(f'queries: {queries}')
    def query(root):
        count = 0
        if(is_prime(values[root-1])):
            count += 1
        for node in adjacencyList[root]:
            if node != root:
                if node not in d:
                    sr = query(node)
                    d[node] = sr
                count += d[node]
        return count

    adjacencyList = [-999] # add a dummy value to all 1-index
    d = {} # {node : # of prime nodes in the subtree with root `node`}

    for i in range(n):
        adjacencyList.append([])
    for i,j in zip(u,v):
        adjacencyList[i].append(j)
    # print(adjacencyList)
    res = []
    for q in queries:
        if q not in d:
            ans = query(q)
            d[q] = ans
        res.append(d[q])
    # print(res)
    # print(d)
    return res

if __name__ == "__main__":
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))
    u = []
    v = []
    values = []
    queries = []
    # number of nodes
    n = int(input_string_list.popleft())
    for i in range(n):
        u.append(int(input_string_list.popleft()))
    for i in range(n):
        v.append(int(input_string_list.popleft()))
    nval = int(input_string_list.popleft())
    for i in range(nval):
        values.append(int(input_string_list.popleft()))
    nquery = int(input_string_list.popleft())
    for i in range(nquery):
        queries.append(int(input_string_list.popleft()))

    assert primeQuery(n, u, v, values, queries) == [4, 1, 0, 1, 2]
