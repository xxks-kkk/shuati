import re

class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        str = re.findall('^[\+\-]?\d+', str)

        try:
            res = int(''.join(str))
            MAX = 2147483647
            MIN = -2147483648
            if res > MAX:
                return MAX
            if res < MIN:
                return MIN
            return res
        except:
            return 0


if __name__ == "__main__":
    sol = Solution()
    s = "123"
    print(sol.myAtoi(s))