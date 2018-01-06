## Solution Explanation

 First of all you should understand that we need to do $n+m-2$ movements:
 $m-1$ down, $n-1$ right because we start from cell (1,1)
 
 Secondly, the path it is the sequence of movements (go down / go right), therefore
 we can say that two paths are different when there is i-th (1 ... $m+n-2$)
 movement in path1 differ i-th movement in path2.
 
 So, how can we build paths? Let's choose (n-1) movements (i.e., number of steps to the right)
 from $m+n-2$, and rest (m-1) is the number of steps down.
 
 Thus, to count of different paths is C(m+n-2, n-1).
 
 The problem can also be solved by [DP](https://leetcode.com/problems/unique-paths/discuss/22954).
 
 ## Reference
 
 - http://www.cnblogs.com/grandyang/p/4353555.html