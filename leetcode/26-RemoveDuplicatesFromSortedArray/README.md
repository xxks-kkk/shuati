## Solution explanation

### Solution 1

这道题的解题思路是，我们使用快慢指针来记录遍历的坐标，最开始时两个指针都指向第一个数字，如果两个指针指的数字相同，则快指针向前走一步，
如果不同，则两个指针都向前走一步，这样当快指针走完整个数组后，慢指针当前的坐标加1就是数组中不同数字的个数.

This solution is implemented as `removeDuplicates`.

### Solution 2

The idea is similar to the first one but it may seem easier to think about for "Remove Duplicates From Sorted Array II"
as well.

双指针，一个指针 `i` 扫描数组，一个指针 `end` 记录没有重复数字的新数组的尾部。

- `A[end] == A[i]`，`A[i]`为重复数字，跳过。
- `A[end] != A[i]`，将`A[i]`放到`A[end+1]`位置，`end += 1`

## Reference

- http://www.cnblogs.com/grandyang/p/4329128.html
- http://bangbingsyb.blogspot.com/2014/11/leetcode-remove-duplicates-from-sorted.html