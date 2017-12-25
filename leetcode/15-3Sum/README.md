## Solution Explanation

The idea is to sort the input array and then run through all possible first element of a
triplet. For each possible first element, we make a standard bi-directional 2Sum sweep
of the remaining part of the array.

Essentially, we use the first element as 
our target and we find the sum of the rest two elements of the triplet can be added up
and equal to the first element (In the code, this is translated to 
`s = nums[i] + nums[left] + nums[right]`). 
Thus, we transform the problem of 3sum into a 2sum problem.

A couple of things to be noticed here:

- Unlike the 2Sum problem, there can be multiple solutions for the given target (i.e.,
first element of the triplet). In other words, we cannot use the dict approach for
2Sum problem to solve the 3Sum problem:

```python
def threeSum(self, nums):
    """
    :type nums: List[int]
    :rtype: List[List[int]]
    """
    nums = sorted(nums)
    res = []
    for i in range(len(nums)):
        if i == 0 or (i > 0 and nums[i] != nums[i-1]):
            keys = {}
            target = -nums[i]
            for j in range(len(nums)):
                if target - nums[j] in keys:
                    res.append([-target, nums[j], target-nums[j]])
                    break
                else:
                    keys[nums[j]] = 0
    return res
```

Concretely, since 2Sum gives "You may assume that each input would have exactly one solution", 
which can use `break` once we find a solution. However, the assumption does not held here.

- `-2` in `for i in range(len(nums)-2)` is because we need to give space
for both `left` and `right` pointers. Since `left = i+1` and `right = len(nums)-1`,
there will be index out of bound if `for i in range(len(nums))`.

- We use the following code fragments to avoid duplicates:

```python
...
if i == 0 or (i > 0 and nums[i] != nums[i - 1]):

...
while left < right and nums[left] == nums[left+1]:
    left += 1
while left < right and nums[right] == nums[right-1]:
    right -= 1
```

First part is to avoid duplicate in the first element of the triplet and the second
part is to avoid any duplicates in the rest elements of the triplet. Existence of
duplicates make the 2Sum approach also inefficient because we don't have a nice way
to eliminate the duplicates without going beyond $O(N)$.

## Reference

- https://discuss.leetcode.com/topic/8