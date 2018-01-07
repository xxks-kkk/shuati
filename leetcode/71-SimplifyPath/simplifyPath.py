# Given an absolute path for a file (Unix-style), simplify it.
#
# For example,
# path = "/home/", => "/home"
# path = "/a/./b/../../c/", => "/c"
#
# Corner Cases:
#
# - Did you consider the case where path = "/../"? In this case, you should return "/".
# - Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
#   In this case, you should ignore redundant slashes and return "/home/foo".

class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for p in path.split("/"):
            if p == "..":
                if stack: stack.pop()
            elif p and p != '.':
                stack.append(p)
        return "/" + "/".join(stack)

if __name__ == "__main__":
    sol = Solution()
    assert sol.simplifyPath("/") == "/"
    assert sol.simplifyPath("/home/") == "/home"
    assert sol.simplifyPath("/a/./b/../../c/") == "/c"
    assert sol.simplifyPath("/../") == "/"
    assert sol.simplifyPath("/home//foo/") == "/home/foo"