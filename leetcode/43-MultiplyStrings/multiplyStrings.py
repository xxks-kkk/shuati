# Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
#
# Note:
#
# The length of both num1 and num2 is < 110.
# Both num1 and num2 contains only digits 0-9.
# Both num1 and num2 does not contain any leading zero.
# You must not use any built-in BigInteger library or convert the inputs to integer directly.

class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == '0' or num2 == '0':
            return '0'
        pos = [0]*(len(num1) + len(num2))
        # Step 1: get all one-digit products
        # Time complexity: O(n1*n2)
        for i in range(len(num1)):
            for j in range(len(num2)):
                mul = int(num1[i]) * int(num2[j])
                pos[i+j+1] += mul % 10
                pos[i+j] += mul // 10
        # Step 2: Sweep through the stored products with carry
        # Time complexity: O(n1+n2)
        carry = 0
        for i in range(1, len(pos)+1):
            tmp = pos[-i] + carry
            pos[-i], carry = str(tmp%10), tmp//10
        return ''.join(pos) if pos[0] != '0' else ''.join(pos[1:])

if __name__ == "__main__":
    sol = Solution()
    assert sol.multiply('123', '456') == '56088'
