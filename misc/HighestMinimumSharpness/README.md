## Problem description

2-d array of "sharpness" values： Find the path from left to right which has the highest minimum sharpness. 
从最左一列中的任意一个出发，到达最右一列的任意一个，要求：

- 当前格子要想往右走，只能往右上、右边、右下三个格子移动
- 一条path中最小的那个值才是这条path的合格value
-  在所有path中找到合格value最大的那一条，输出它的value

也就是说，路径长度是列数$n$，假设路径为 $(i_1,1),(i_2,2), \dots ,(i_n,n)$，路径必须满足每对$i_k$与$i_{k-1}$的距离不能大于1.

Example 1:

```
0.5 0.7 0.2
0.7 0.5 0.8
0.9 0.1 0.5
```

在这个例子中，理想路径是`0.7->0.7->0.8`因为这条路径中的最小值.7在所有路径中最大。只需要返回这个值，不需要返回路径.

Example 2:

```
4    5    4    0    1    2
5    6    5    0    0    0
0    0    0    0    0    0.
1    3    1    2    3    3. 
3    0    3    0    0    0
```

最后的path是：`3->3->3->2->3->3`，所以最终结果就应该返回`2`。 
而比如第一行的path：`4->5->4->0->1->2`，合格value应该是`0`，所以不是最终结果。

## Solution



## Follow-up