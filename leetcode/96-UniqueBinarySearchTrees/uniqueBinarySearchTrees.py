# Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
#
# For example,
# Given n = 3, there are a total of 5 unique BST's.
#
#    1         3     3      2      1
#     \       /     /      / \      \
#      3     2     1      1   3      2
#     /     /       \                 \
#    2     1         2                 3

class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * (n+1)
        dp[0] = 1
        for i in range(1,n+1):
            for j in range(1,i+1):
                dp[i] += dp[j-1] * dp[i-j]
        return dp[n]

    def numTrees2(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0 or n == 1:
            return 1
        sum = num_left_subtrees = num_right_subtrees = 0
        for i in range(1,n+1):
            num_left_subtrees = self.numTrees2(i-1)
            num_right_subtrees = self.numTrees2(n-i)
            sum += num_left_subtrees * num_right_subtrees
        return sum

if __name__ == "__main__":
    sol = Solution()
    assert sol.numTrees(3) == 5