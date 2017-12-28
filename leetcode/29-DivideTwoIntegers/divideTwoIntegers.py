# Divide two integers without using multiplication, division and mod operator.

# If it is overflow, return MAX_INT.

class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        positive = (dividend < 0) is (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            temp, multiple = divisor, 1
            while dividend >= temp << 1:
                temp <<= 1
                multiple <<= 1
            dividend -= temp
            res += multiple
        if not positive:
            res = -res
        return min(max(-2147483648, res), 2147483647)

if __name__ == "__main__":
    sol = Solution()
    print(sol.divide(15,3))