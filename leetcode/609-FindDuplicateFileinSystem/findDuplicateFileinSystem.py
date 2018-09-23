import os

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

if __name__ == "__main__":
    test(Solution.findDuplicate)