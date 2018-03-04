import collections
import fileinput

class Folder:
    def __init__(self, id, shared):
        self.id = id
        self.shared = shared # boolean
        # Number of incoming arcs
        self.incoming = 0
        # Number of outcoming arcs
        self.outcoming = 0
        self.cows = []
        self.children = []

    def appendCow(self, newCows):
        self.cows.extend(newCows)

def findFolder(folders, id):
    try:
        return folders[id]
    except KeyError:
        return None

def traverse(cows, root):
    if root.outcoming == 0:
        # There is no outcoming arcs from the root
        # Thus, we are at a leaf node
        for i in root.cows:
            cows[i] += 1
    for f in root.children:
        if f.shared:
            f.appendCow(root.cows)
        traverse(cows, f)

if __name__ == "__main__":
    # HackerRank way to handle the stdin input
    # The advantage of doing is that we can have a unified interface to
    # handle both file input and stdin input. File input is easier to debug locally
    # and we don't need to modify the code to allow the code to run on HackerRank using stdin input.
    # We can do this because of fileinput module: supporting two ways of passing at the same time:
    # - support foldersAndCows.py < input000.txt
    # - support foldersAndCows.py input000.txt
    input_string = ""
    for line in fileinput.input():
        input_string += line
    input_string_list = collections.deque(input_string.split('\n'))

    # the number of cows
    Q = int(input_string_list.popleft())
    # M: the number of shared folder; N: the number of confidential folder
    M,N = list(map(int, input_string_list.popleft().split(' ')))
    folders = {}

    while M > 0:
        line = list(map(int, input_string_list.popleft().split(' ')))
        f = Folder(line[0], True)
        folders[line[0]] = f
        k = line[1]
        if k != 0:
            f.cows.extend(list(line[2:]))
        M -= 1

    while N > 0:
        line = list(map(int, input_string_list.popleft().split(' ')))
        f = Folder(line[0], False)
        folders[line[0]] = f
        k = line[1]
        if k != 0:
            f.cows.extend(list(line[2:]))
        N -= 1

    # parse and build trees
    G = int(input_string_list.popleft())
    while G > 0:
        G -= 1
        U,V = list(map(int, input_string_list.popleft().split(' ')))
        u = findFolder(folders, U)
        v = findFolder(folders, V)
        if u and v:
            u.children.append(v)
            u.outcoming += 1
            v.incoming += 1

    # traverse
    numLeaf = 0
    cows = [0] * Q
    for i in folders.keys():
        if folders[i].incoming == 0:
            traverse(cows, folders[i])
        if folders[i].outcoming == 0:
            numLeaf += 1

    res = []
    for i in range(Q):
        if cows[i] < numLeaf:
            res.append(str(i))

    print(' '.join(res))
