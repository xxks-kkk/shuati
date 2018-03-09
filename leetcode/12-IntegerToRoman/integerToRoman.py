# Given an integer, convert it to a roman numeral.
#
# Input is guaranteed to be within the range from 1 to 3999.


class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        I = ["","I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        X = ["","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        C = ["","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        M = ["", "M", "MM", "MMM"]
        return M[num//1000] + C[num % 1000//100] + X[num % 100//10] + I[num % 10]

if __name__ == "__main__":
    sol = Solution()
    print(sol.intToRoman(1990))
    print(sol.intToRoman(1996))
    print(sol.intToRoman(996))