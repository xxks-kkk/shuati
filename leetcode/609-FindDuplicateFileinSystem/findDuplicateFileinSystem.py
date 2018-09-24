import os
import collections
import hashlib
from timeit import default_timer as timer

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
        Solution without any optimization
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
        # key: file content hash code
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

    def findDuplicate2(self, path):
        """
        Optimization: In a real life solution we will not hash the entire file content, since it's not practical
        (too slow to generate the hash and we have to read the file content into memory).
        Instead we will first map all the files according to size.
        Files with different sizes are guaranteed to be different.
        We will than hash a small part of the files with equal sizes (using MD5 for example).
        Only if the md5 is the same, we will compare the files byte by byte
        :param path:
        :return:
        """
        def dfs(path):
            """
            return a file list that contain absolute file path under the given path
            :param path:
            :return: List[List[str]] files with the same size are grouped into one sublist
            """
            fileList = []
            # key: file size
            # val: a list of files with the same size
            table = {}
            stack = collections.deque()
            stack.append(path)
            while len(stack) != 0:
                currPath = stack.pop()
                if os.path.isfile(currPath):
                    st = os.stat(currPath)
                    size = st.st_size
                    if size in table:
                        table[size].append(currPath)
                    else:
                        table[size] = [currPath]
                else:
                    for dirpath, dirnames, filenames in os.walk(currPath):
                        for filename in filenames:
                            filepath = os.path.join(dirpath, filename)
                            st = os.stat(filepath)
                            size = st.st_size
                            if size in table:
                                table[size].append(filepath)
                            else:
                                table[size] = [filepath]
                        for dirname in dirnames:
                            stack.append(os.path.join(dirpath, dirname))
                        # We break because we only care about the immediate child files/directories under currPath
                        # Not recursively further under
                        break
            for key in table:
                fileList.append(table[key])
            return fileList

        def compare(fileList):
            """
            Given a list of files, we group the duplicates into the same group.
            :param fileList: a list of files
            :return: List[List[str]]
            """
            table = {}
            res = []
            for file in fileList:
                with open(file, 'rb') as f:
                    # Here, we compute md5 for the rest of file content (filesize - 4096 bytes)
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

        # key: file content hash code
        # val: list of files with the same content
        table = {}
        fileList = dfs(path)
        res = []
        for sameSizeFileList in fileList:
            # Iterate through the files with the same size (potentially to be duplicate files)
            for file in sameSizeFileList:
                # We compute the md5 value of the first 1KB of file
                with open(file, 'rb') as f:
                    # We read 4096 bytes (4KB) from the file
                    content = f.read(4096)
                    hashcode = hashlib.md5(content).digest()
                    if hashcode in table:
                        table[hashcode].append(file)
                    else:
                        table[hashcode] = [file]
            for key in table:
                if len(table[key]) > 1:
                    # We now compare the files with the same key
                    res.extend(compare(table[key]))
            table = {}
        return res

def test(pfcn):
    """
    Verify the correctness of Solution.findDuplicate(self, paths)
    :param pfcn:
    :return:
    """
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
    """
    Verify the correctness of functions under Solution2
    :param pfcn:
    :return:
    """
    sol = Solution2()
    res = pfcn(sol, '/Users/zeyuan/Documents/projects/shuati/leetcode/609-FindDuplicateFileinSystem/test')
    ans = [
        ['/Users/zeyuan/Documents/projects/shuati/leetcode/609-FindDuplicateFileinSystem/test/4.txt',
         '/Users/zeyuan/Documents/projects/shuati/leetcode/609-FindDuplicateFileinSystem/test/c/d/4.txt',
         '/Users/zeyuan/Documents/projects/shuati/leetcode/609-FindDuplicateFileinSystem/test/a/2.txt'],
        ['/Users/zeyuan/Documents/projects/shuati/leetcode/609-FindDuplicateFileinSystem/test/c/3.txt',
         '/Users/zeyuan/Documents/projects/shuati/leetcode/609-FindDuplicateFileinSystem/test/a/1.txt']]
    count = 0
    for cand in res:
        if cand in ans:
            count+=1
    if count == len(res):
        assert True
    else:
        assert False

def test3(pfcn):
    """
    Benchmark different functions under Solution2
    :param pfcn:
    :return:
    """
    sol = Solution2()
    res = pfcn(sol, '/Users/zeyuan/Documents/projects/shuati')

if __name__ == "__main__":
    test(Solution.findDuplicate)
    test2(Solution2.findDuplicate)
    test2(Solution2.findDuplicate2)

    start = timer()
    print(f'executing Solution2.findDuplicate ...')
    test3(Solution2.findDuplicate)
    end = timer()
    print(f'Solution2.findDuplicate \t execution time: \t {end-start}\n') # 118s, 92s

    start = timer()
    print(f'executing Solution2.findDuplicate2 ...')
    test3(Solution2.findDuplicate2)
    end = timer()
    print(f'Solution2.findDuplicate2 \t execution time: \t {end-start}\n') # 92s, 31s