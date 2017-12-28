## Solution explanation

The problem can be solved by [Generation in lexicographic order](https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order).
The algorithm follows:

- Find the largest index `k` such that `nums[k] < nums[k + 1]`. 
If no such index exists, the permutation is sorted in descending order, 
just reverse it to ascending order and we are done. 
For example, the next permutation of `[3, 2, 1]` is `[1, 2, 3]`.
- Find the largest index `l` greater than `k` such that `nums[k] < nums[l]`.
- Swap the value of `nums[k]` with that of `nums[l]`.
- Reverse the sequence from `nums[k + 1]` up to and including the final element `nums[len(nums) - 1]`.

Quite simple, yeah? Now comes the following code, which is barely a translation.

## Reference

- https://leetcode.com/problems/next-permutation/discuss/13867
- https://leetcode.com/problems/next-permutation/discuss/13907
- https://www.nayuki.io/page/next-lexicographical-permutation-algorithm