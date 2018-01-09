## Solution explanation

The problem is also called [Dutch national flag problem](https://en.wikipedia.org/wiki/Dutch_national_flag_problem),which
essentially deals with the partition step happens in the quicksort:

Pick any element $v$ in S. This is called pivot. Partition $S-{v}$ (the remaining elements in $S$) into
two disjoints groups: $S_1 = {X \in S-{v}|x \le v}$, and $S_2 = {x \in S-{v}|x \ge v}$.

We implement two solutions. `sortColors` keep a loop invariant that $[0,i)$, $[i, j)$, $[j, k)$ 
are 0s, 1s and 2s sorted in place for $[0,k)$. The implementation is interesting because we always
set `nums` element to 2 by default and then based on the specific value of `v`, we advance our pointers
`i` and `j` differently. One drawback of this solution is that if the value represents some key value
of the objects, we always want to perform the swap operation instead of set the value.

`sortColors2` is a python implementation of the pseudocode appeared on the Wiki page of the "Dutch national flag problem".
One thing to point out is when `nums[i] == 2`, we don't increment `i`. This is because
once we swap the values between `nums[i]` and `nums[blue]`, we essentially put `2` to the righthand of the
array. However, the value originally pointed by `blue` may be `1` or `0`. The general idea of the 
algorithm is to put `0` to the left-hand side of the array and `2` to the right-hand side and leave `1` in
the middle. If we increment `i` and when the value originally pointed by `blue` is `0`, we would have
the situation where `0` appears in the middle area of the array after swap (i.e., `[0,0,1,1,1,0,2,2]`).
 

## Reference

- https://leetcode.com/problems/sort-colors/discuss/26479
- http://www.cnblogs.com/grandyang/p/4341243.html