## Solution Explanation

The solution structure is quite similar with "CombinationSum", "CombinationSumII". Two things
to note in the implementation:

- We don't need to do `nums.sort()` because we are given a collection of **distinct** numbers.
- `for i in range(len(nums))` instead of `for i in range(index, len(nums))` because
we need to use all the numbers in the collection and the order matters in permutation
(i.e., which position that `1` appears matters).


## Reference

- https://leetcode.com/problems/permutations/discuss/18239
- http://www.cnblogs.com/grandyang/p/4358848.html