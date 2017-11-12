 # [Source] 
 #          
 # https://leetcode.com/problems/unique-paths/description/
 #          
 # [Problem Description]
 #          
 # A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 # the diagram below).
 # The robot can only move either down or right at any point in time. The robot is
 # trying to reach the bottom-right corner of the grid (marked 'Finish' in the
 # diagram below).
 # How many possible unique paths are there?
 # Above is a 3 x 7 grid. How many possible unique paths are there?
 # Note: m and n will be at most 100.
 #          
 # [Comments]
 #          
 # First of all you should understand that we need to do $n+m-2$ movements:
 # $m-1$ down, $n-1$ right because we start from cell (1,1)
 #
 # Secondly, the path it is the sequence of movements (go down / go right), therefore
 # we can say that two paths are different when there is i-th (1 ... $m+n-2$)
 # movement in path1 differ i-th movement in path2.
 #
 # So, how can we build paths? Let's choose (n-1) movements (i.e., number of steps to the right)
 # from $m+n-2$, and rest (m-1) is the number of steps down.
 #
 # Thus, to count of different paths is C(m+n-2, n-1).
 #
 # [Companies]


class Solution(object):
    def uniquePaths(self, m, n):
    """
    :type m: int
    :type n: int
    :rtype: int
    """
    # How many steps we need to move in total
    N = n + m - 2
    # Number of steps we need to go down
    K = m - 1
    # Here we calculate the total possible path number
    # Combination(N,K) = \frac{N!}{K!(N-K)!}
    numerator = 1
    denominator = 1
    for i in range(1, K+1):
        denominator *= i
        numerator *= (N-K+i)
    return numerator / denominator
