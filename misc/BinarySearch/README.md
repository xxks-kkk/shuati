## Ways to write binary search

注意二分查找法的写法并不唯一，主要可以变动的地方有四处：

1. 第一处是high的初始化，可以写成 len(nums) 或者 len(nums) - 1

2. 第二处是low和high的关系，可以写成 low < high 或者 low <= high

3. 第三处是low的赋值，可以写成 low = mid 或者 low = mid + 1

3. 第三处是high的赋值，可以写成 high = mid 或者 high = mid - 1

但是这些不同的写法并不能随机的组合，若high初始化为了len(nums)，那么就必须用low < high，
low的赋值哪个都可以，但是high的赋值必须为high = mid。但是如果我们high初始化为 len(nums) - 1，
那么就必须用 low <= high. low的赋值必须为low = mid +1 但是right的赋值哪个都可以。
建议选择一套自己喜欢的写法，并且记住，实在不行就带简单的例子来一步一步执行，确定正确的写法也行。

## Reference

- http://www.cnblogs.com/grandyang/p/6854825.html