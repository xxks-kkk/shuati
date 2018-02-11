# Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
#
# If the fractional part is repeating, enclose the repeating part in parentheses.
#
# For example,
#
# Given numerator = 1, denominator = 2, return "0.5".
# Given numerator = 2, denominator = 1, return "2".
# Given numerator = 2, denominator = 3, return "0.(6)".

class Solution:
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0:
            return "0"
        res = []
        if (numerator < 0) ^ (denominator < 0):
            # If either one is negative (not both)
            res.append("-")
        dividend = abs(numerator)
        divisor = abs(denominator)
        res.append(str(dividend // divisor))
        remainder = dividend % divisor
        if remainder == 0:
            return "".join(res)
        res.append(".")
        dict = {}
        while remainder != 0:
            if remainder in dict:
                res.insert(dict[remainder], "(") # insert right before the specified index
                res.append(")")
                break
            dict[remainder] = len(res)
            # Below three lines mimic how the long division works
            remainder *= 10
            res.append(str(remainder // divisor))
            remainder %= divisor
        return ''.join(res)


if __name__ == "__main__":
    sol = Solution()
    assert sol.fractionToDecimal(0,1) == "0"
    assert sol.fractionToDecimal(20,4) == "5"
    assert sol.fractionToDecimal(1,2) == "0.5"
    assert sol.fractionToDecimal(-1,4) == "-0.25"
    assert sol.fractionToDecimal(1, -4) == "-0.25"
    assert sol.fractionToDecimal(-1,-4) == "0.25"
    assert sol.fractionToDecimal(-2147483648,-1) == "2147483648"
    assert sol.fractionToDecimal(2,3) == "0.(6)"
    assert sol.fractionToDecimal(1,6) == "0.1(6)"