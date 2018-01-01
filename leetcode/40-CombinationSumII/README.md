## Solution Explanation

The problem is very similar to [Combination Sum](https://leetcode.com/problems/combination-sum/). Let's
take a look at their differences:

- Combination Sum:
    - a set of candidate numbers (C) do not have duplicates. So, there is no 
    such case `[10, 1, 2, 7, 6, 1, 5]` as `1` appears twice.
    - The same repeated number may be chosen from C unlimited number of times.
    
- Combination Sum II:
    - No constraint on a set of candidate numbers
    - Each number in C may only be used once in the combination.
    
Even though the major code structure between two problems are the same, the problem
description difference listed above will determine the implementation subtlety.

```python
if i > index and nums[i] == nums[i-1]:
    continue
```

make sure there is no duplicate combination appeared in the result set. For example,
after we sort `[10, 1, 2, 7, 6, 1, 5]`, we have `[1,1,2,5,6,7,10]`. The code will
first find all the combinations with the first `1` as the first element. However, there
are two `1`. Without code fragment above, the code will use the second `1` as the first
element of the combination, which will lead to the duplicate `[1,7]`. "combinationSum"
problem doesn't need this code fragment because the candidate numbers (C) do not contain
duplicates.

```python
dfs(nums, target - nums[i], i+1, path + [nums[i]], res)
```

Here, we use `i+1` instead of `i` because of the constraint 
"Each number in C may only be used once in the combination".

## Reference

- https://leetcode.com/problems/combination-sum-ii/discuss/16862/
- https://leetcode.com/problems/combination-sum-ii/discuss/16944/