## Solution explanation

### Solution 1: Backtracking [Time Limit Exceeded]

A very natural idea is to use the backtracking method to calculate all possible path sums and return
the minimum one. However, since backtracking method uses the stack and do a lot of repetitive calculations,
it is not surprising that we reach the time limit.

### Solution 2: DP [Accepted]

Optimizing the backtracking method can be done through dynamic programming. Here, we use $O(n^2)$ space with
$n$ being the number of rows. This is "top-down" DP approach, which as one will see is very ineffective.
One observation to help the implementation is that the number of elements on $i$th row is equal to $i+1$.
This helps with `for j in range(i+1)`. One inefficiency of "top-down" DP approach is that we need to
take care of the leftmost element and rightmost element specially. The following example can help with
understanding.

```
-1                     -1    
 3 2       <->         / \
-3 1 -1               3   2
                     / \ / \
                    -3  1  -1
```


### Solution 3: DP [Accepted]

If we do "bott-up" DP, we can achieve $O(n)$ space complexity. The idea is simple:

- Go from bottom to top.
- We start form the row above the bottom row.
- Each number add the smaller number of two numbers that below it.
- And finally we get to the top we the smallest sum.

The size of DP table equals to the number of elements in the last row, which exactly equals to the
number of rows in the triangle. We initialize DP table to be the last row of triangle and follow
the procedure described above to get the min path sum.

The implementation is `minimumTotal2`.

### SOlution 4: DP [Accepted]

This approach is exactly the same as solution 3 except we directly modify the triangle itself.
By doing this way, we can achieve $O(1)$ space complexity.

The implementation is `minimumTotal3`.


## Reference

- https://discuss.leetcode.com/topic/8077/my-8-line-dp-java-code-4-meaningful-lines-with-o-1-space
- https://discuss.leetcode.com/topic/1669/dp-solution-for-triangle