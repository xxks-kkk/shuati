## Solution explanation

There are many ways of solving this. For example, one can sort the array and swap elements pair-wise starting
from the second element. For example,

```
   [1, 2, 3, 4, 5, 6]
       ↑  ↑  ↑  ↑
       swap  swap

=> [1, 3, 2, 5, 4, 6]
```

The running time for this solution is $O(n\log n)$. However, we can do better by first observing that:

- The final sorted `nums` needs to satisfy two conditions:

    - If `i` is odd, then `nums[i] >= nums[i - 1]`
    - If `i` is even, then `nums[i] <= nums[i - 1]`
    
Then, the solution is just to fix the ordering of `nums` that do not satisfy the two conditions above.
The code is implemented in `wiggleSort`. Now, the tricky thing is that how do we prove that this
surprisingly simple solution is actually correct. We do this by using induction (we can also use 
the invariant: $nums[0] \dots nums[i-1]$ is wiggle sorted, which is equivalent as induction)

1. Base case. When there is only one element in `nums`, the hypothesis is trivially true.
2. Induction. Now for $i \ge 2$. Suppose $nums[0] \dots nums[i-1]$ are wiggle sorted. Then thre are
two cases:

    1) $i$ is odd:
    
        1) if $nums[i] \ge nums[i-1]$, then by the definition of the wiggle sort, we don't need to do anything
        and $nums[0] \dots nums[i]$ are wiggle sorted.
        2) if $nums[i] < nums[i-1]$, then we swap the value of $nums[i]$ and $nums[i-1]$. Let's use
        $nums[i]'$ and $nums[i-1]'$ to denote the value at $i$ and $i-1$ after the swap. By the induction
        hypothesis and $i$ is odd, we know that $i-1$ is even and $i-2$ is odd. Then, $nums[i-2] \ge nums[i-1]$.
        Before the swap, we have $nums[i-2] \ge nums[i-1] > nums[i]$. Then, after swap, we have
        $nums[i-2] > nums[i-1]' < nums[i]'$. We didn't break the wiggle sort constraints on $i-2$th element
        and $i-1$th element and we make sure that $i$th element follows wiggle sort constraints as well.
        Thus, $nums[0] \dots nums[i]$ are wiggle sort.
        
    2) $i$ is even:
    
        1) if $nums[i] \le nums[i-1]$, then by the definition of the wiggle sort, we don't need to do anything
        and $nums[0] \dots nums[i]$ are wiggle sorted.
        2) if $nums[i] > nums[i-1]$, then we swap the value of $nums[i]$ and $nums[i-1]$. Since $i$ is even,
        we know $i-1$ is odd and $i-2$ is even. Thus, we have $nums[i-2] <= nums[i-1] < nums[i]$ before
        the swapping. After swapping, we have $nums[i-2] <= nums[i-1]' > nums[i]'$, which satisfy the 
        wiggle sort constraint and we have $nums[0] \dots nums[i]$ are wiggle sorted.

3. By the principle of mathematical induction, we prove that the solution is correct.

## Reference

- https://discuss.leetcode.com/topic/23877/4-lines-o-n-c
- https://discuss.leetcode.com/topic/42605/my-explanations-of-the-best-voted-algo