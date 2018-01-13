## Solution explanation

和"Remove Duplicates From Sorted Array" 一样的思路，区别仅仅在于当`A[end-1] == A[end] == A[i]` 时，
`A[i]`为重复元素需跳过。而实际只需要比较`A[end-1]`和`A[i]`，因为当`A[end-1] == A[i]`时，
根据sorted array特性: `A[i] >= A[end] >= A[end-1]`并且`A[end-1] == A[i]`, 因此只有
`A[i] == A[end] == A[end-1]`这一种情况。

## Reference

- http://bangbingsyb.blogspot.com/2014/11/leetcode-remove-duplicates-from-sorted.html