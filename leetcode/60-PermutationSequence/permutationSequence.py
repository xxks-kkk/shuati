# The set [1,2,3, ... ,n] contains a total of n! unique permutations.
#
# By listing and labeling all of the permutations in order,
# We get the following sequence (ie, for n = 3):
#
# "123"
# "132"
# "213"
# "231"
# "312"
# "321"
# Given n and k, return the kth permutation sequence.
#
# Note: Given n will be between 1 and 9 inclusive.

class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = list(map(str,range(1,10)))
        k -= 1
        factorial = [1] * n
        for i in range(1, n):
            factorial[i] = factorial[i - 1] * i
        res=[]
        for i in range(n):
            index = k // factorial[n - 1 - i]
            res.append(nums[index])
            nums.remove(nums[index])
            k = k % factorial[n - 1 - i]
        return ''.join(res)

if __name__ == "__main__":
    sol = Solution()
    print(sol.getPermutation(4,9))
    print(sol.getPermutation(1,1))