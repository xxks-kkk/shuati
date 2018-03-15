## Solution explanation

### Brute-Force [Time Limit Exceeded]

```python
def subarraySum(self, nums, k):
    sum = 0
    cnt = 0
    for i in range(len(nums)):
        for j in range(i, len(nums)):
            sum += nums[j]
            if sum == k:
                cnt += 1
        sum = 0
    return cnt
```

- Time complexity: $O(n^2)$

### Use hashmap [Accepted]

The key idea of the algorithm is that any sum of subarray with starting index $i$ and end index $j$
can be thought of as `sum(nums[0:j]) - sum(nums[0:i])`. Thus, our goal is to find the number of such 
difference with value equal to $k$. This is the same as calculating the number of ways we can get
`sum(nums[0:j])` and number of ways we can get `sum(nums[0:i])` such that 
`sum(nums[0:j]) - sum(nums[0:i]) == k`. Then, we can add number of ways getting
 `sum(nums[0:j])`  and number of ways getting `sum(nums[0:i])` together to get the answer.

This intuition naturally leads to the hash map. We use the sum as the key and corresponding number of
ways to get such sum as the value. We can observe that both `nums[0:i]` and `nums[0:j]` starts with
index `0`. Thus, we can one pass the `nums` array and build our hash map.

The implementation details see `subarraySum`.

## Remarks 

The idea of this problem is very similar to the "Two Sum" problem.

## Reference

- https://leetcode.com/problems/subarray-sum-equals-k/solution/
- https://leetcode.com/problems/subarray-sum-equals-k/discuss/102111/Python-Simple-with-Explanation