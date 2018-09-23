import os
import collections
import hashlib

class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        # key: content of the file
        # val: list of filepaths with this content
        table = {}
        for path in paths:
            tokens = path.split(" ")
            filepath = tokens[0]
            files = tokens[1:]
            for file in files:
                tokens2 = file.split("(")
                filename = tokens2[0]
                filecontent = tokens2[1].split(")")[0]
                if filecontent in table:
                    table[filecontent].append(os.path.join(filepath, filename))
                else:
                    table[filecontent] = [os.path.join(filepath, filename)]
        res = []
        for key in table:
            if len(table[key]) > 1:
                res.append(table[key])
        return res

class Solution2:
    def findDuplicate(self, path):
        """
        Can work in the real life and follow 面经
        :return: List[List[str]]
        """
        def dfs(path):
            """
            return a file list that contain absolute file path under the given path
            :param path:
            :return: List[str]
            """
            fileList = []
            st = collections.deque()
            st.append(path)
            while len(st) != 0:
                currPath = st.pop()
                if os.path.isfile(currPath):
                    fileList.append(currPath)
                else:
                    for dirpath, dirnames, filenames in os.walk(currPath):
                        for filename in filenames:
                            fileList.append(os.path.join(dirpath, filename))
                        for dirname in dirnames:
                            st.append(os.path.join(dirpath, dirname))
                        # We break because we only care about the immediate child files/directories under currPath
                        # Not recursively further under
                        break
            return fileList
        # key: file content
        # val: list of files with the same content
        table = {}
        fileList = dfs(path)
        res = []
        for file in fileList:
            with open(file, 'rb') as f:
                content = f.read()
                hashcode = hashlib.md5(content).digest()
                if hashcode in table:
                    table[hashcode].append(file)
                else:
                    table[hashcode] = [file]
        for key in table:
            if len(table[key]) > 1:
                res.append(table[key])
        return res

def test(pfcn):
    sol = Solution()
    paths = ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
    ans =  [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
    res = pfcn(sol, paths)
    count = 0
    for cand in res:
        if cand in ans:
            count+=1
    if count == len(res):
        assert True
    else:
        assert False

def test2(pfcn):
    sol = Solution2()
    res = pfcn(sol, '/Users/zeyuan/Documents/projects/shuati/leetcode/609-FindDuplicateFileinSystem/test')
    print(res)

if __name__ == "__main__":
    test(Solution.findDuplicate)
    test2(Solution2.findDuplicate)