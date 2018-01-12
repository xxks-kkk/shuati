## Solution explanation

这道题是典型的深度优先遍历DFS的应用，原二维数组就像是一个迷宫，可以上下左右四个方向行走，
我们以二维数组中每一个数都作为起点和给定字符串做匹配，我们还需要一个和原数组等大小的visited数组. 
用来记录当前位置是否已经被访问过，因为题目要求一个cell只能被访问一次。
如果二维数组board的当前字符和目标字符串word对应的字符相等，则对其上下左右四个邻字符分别调用DFS的递归函数，
只要有一个返回true，那么就表示可以找到对应的字符串，否则就不能找到.

The code structure and the general idea is very similar to "Permutation" problem.

## Reference

- http://www.cnblogs.com/grandyang/p/4332313.html