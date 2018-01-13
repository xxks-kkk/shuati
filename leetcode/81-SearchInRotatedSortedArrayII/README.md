## Solution explanation

当有重复数字，会存在 `A[mid] == A[end]`的情况。此时右半序列`A[mid-1 : end]`可能是sorted，也可能并没有sorted，如下例子。

```
3 1 2 3 3 3 3 
3 3 3 3 1 2 3
```

所以当 `A[mid] == A[end] != target` 时，无法排除一半的序列，而只能排除掉`A[end]`：

`A[mid] == A[end] != target` 时：搜寻`A[start : end-1]`

正因为这个变化，在最坏情况下，算法的复杂度退化成了$O(n)$：
序列 2 2 2 2 2 2 2 中寻找target = 1。

## Reference

- http://bangbingsyb.blogspot.com/2014/11/leetcode-search-in-rotated-sorted-array.html (this one is good)
- http://www.cnblogs.com/grandyang/p/4325840.html