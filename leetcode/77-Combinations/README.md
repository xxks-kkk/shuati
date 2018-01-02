## Solution Explanation

If you understand "combinationSum", "combinationSumII", "Permutation", then it is easy 
to understand the solution to this problem.

Here, I want to note the difference between when to use 
`for i in range(index, len(nums)):` (i.e., sol to this problem) and 
when to use `visited` (i.e., [sol to "permutation"](https://github.com/xxks-kkk/shuati/blob/master/leetcode/46-Permutations/permutations.py)):

- We use `index` when the order doesn't matter. For example, `[1,2]` is the same
as `[2,1]` in the combination. Suppose we find combination `n = 4` and `k = 2`:

```
1 - 2
  - 3
  - 4
2 - 3
  - 4  
```

In the above example, we first pick `1` and then we pick `2`, `3`, `4`. Next, we first
pick `2`. However, we no longer want to pick `1` anymore because `[1,2]` and `[2,1]` are
the same. How can we do that? We use `index` to constraint our choices to `3` and `4`.
Another way to think about is that all the numbers in the combinations are in the increasing
order: `[1,2]`, `[1,3]`, `[1,4]`, `[2,3]`, `[2,4]` and so on. This idea is illustrated
in [1st link in reference section](http://blog.csdn.net/u010500263/article/details/18435495).

The idea also works for "combinationSum" problem because for example `[1,2,3,4]` and
target `5`. We don't want to have duplicate solution in the result set. No duplicate
means the same as the order inside a combination doesn't matter. Thus, `[1,4]` and `[4,1]`
are the same. Thus, we use `index`.

- We use `visited` when order matters. `[1,2]` and `[2,1]` are different in permutation.
Even `1` appears in the first position, it is different from `1` appears in the second 
position. We use `visited` as a way to avoid the same number appears in the permutation
mutiple times while allowing us to take order into account.


## Reference

- http://blog.csdn.net/u010500263/article/details/18435495
- http://www.cnblogs.com/grandyang/p/4332522.html