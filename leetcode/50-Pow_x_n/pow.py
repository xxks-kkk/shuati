# Implement pow(x, n).
#
#
# Example 1:
#
# Input: 2.00000, 10
# Output: 1024.00000
# Example 2:
#
# Input: 2.10000, 3
# Output: 9.26100

class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        def fastPow(x, N):
            if N == 0:
                return 1
            if N == 1:
                return x
            half = fastPow(x, N//2)
            if N % 2 == 0:
                return half * half
            else:
                return half * half * x
        N = n
        if N < 0:
            x = 1 / x
            N = -N
        return fastPow(x, N)

    def myPowIterative(self, x, n):
        N = n
        if N < 0:
            x = 1 / x
            N = -N
        i = N
        ans = 1
        current_product = x
        while i > 0:
            if i % 2:
                ans *= current_product
            current_product *= current_product
            i //= 2
        return ans

if __name__ == "__main__":
    sol = Solution()
    print(sol.myPow(2.00000, 10))
    print(sol.myPow(2.10000, 3))
    print(sol.myPowIterative(2.00000, 10))
    print(sol.myPowIterative(2.10000, 3))