## Solution explanation

This problem can be solved via Kadane's algorithm, which is discussed by Jon Bentley
(Sep. 1984 Vol. 27 No. 9 Communications of the ACM P885).

algorithm that operates on arrays: it starts at the left end (element `nums[1]`) and scans through to
the right end (element `nums[n-1]`), keeping track of the maximum sum subvector seen so far.
The maximum is initially `nums[0]`. Suppose we've solved the problem for `nums[0 .. i - 1]`; how can we extend that to
`nums[0 .. i]`? The maximum
sum in the first `i` elements is either the maximum sum in the first `i - 1` elements (which we'll call `maxSoFar`),
or it is that of a subvector that ends in position `i` (which we'll call `maxEndingHere`).

`maxEndingHere` is either `nums[i]` plus the previous `maxEndingHere`, or just `nums[i]`, whichever is larger.

## Reference

- https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts
- https://leetcode.com/problems/maximum-subarray/discuss/20211/Accepted-O(n)-solution-in-java