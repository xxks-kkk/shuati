# Compare two version numbers version1 and version2.
# If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
#
# You may assume that the version strings are non-empty and contain only digits and the . character.
# The . character does not represent a decimal point and is used to separate number sequences.
# For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
#
# Here is an example of version numbers ordering:
#
# 0.1 < 1.1 < 1.2 < 13.37


class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        ver1_sep = list(map(int, version1.split(".")))
        ver2_sep = list(map(int, version2.split(".")))
        m1 = len(ver1_sep)
        m2 = len(ver2_sep)
        if m1 - m2 > 0:
            ver2_sep.extend([0]*(m1-m2))
        elif m2 - m1 > 0:
            ver1_sep.extend([0]*(m2-m1))
        for i, j in zip(ver1_sep, ver2_sep):
            if i < j:
                return -1
            elif i > j:
                return 1
        return 0

if __name__ == "__main__":
    sol = Solution()
    assert sol.compareVersion("1", "1.1") == -1
    assert sol.compareVersion("1","0") == 1