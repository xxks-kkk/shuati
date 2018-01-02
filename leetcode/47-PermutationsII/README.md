## Solution Explanation

The solution structure is very similar to "combinationSum", "combinationSumII", "Combination", and
"Permutation". The key part in this solution is to understand:

```python
if i > 0 and nums[i] == nums[i-1] and visited[i-1]:
```

In "CombinationSumII", we use similar code structure:

```python
for i in range(index, len(nums)):
    if i > index and nums[i] == nums[i-1]:
```

We use `visited[i-1]` in this solution becasue different orders of duplicates should only be considered as one permutation.
Take `[1,1,2]` as an example. We use the first `1` as the first number of permutation.
If without code fragment above, we will use the second `1` as the first number of
permutation. Unlike `index` way in "CombinationSumII", our loop is `for i in range(len(nums))`,
which consider all the given numbers. Thus, use the second `1` as the first number
in permutation is the same as using the first `1` as the first number in generating
permutation, which will lead to the duplicates.

One quick way to remember is that following our analysis in "Combination" problem, we
use `visited` for order matters case and similar to "CombinationSumII", we use
`nums[i] == nums[i-1]` to avoid duplicates.


## Reference

- 