## Solution Explanation

### Intuition

If we sort the intervals by their start value, then each set of intervals that can be merged will 
appear as a contiguous "run" in the sorted list.

### Algorithm

First, we sort the list as described. Then, we insert the first interval into our `merged` list and 
continue considering each interval in turn as follows: If the current interval begins after the 
previous interval ends, then they do not overlap and we can append the current interval to `merged`. 
Otherwise, they do overlap, and we merge them by updating the `end` of the previous interval if it 
is less than the `end` of the current interval.

Proof by contradiction shows that this algorithm always produces the correct answer. 
First, suppose that the algorithm at some point fails to merge two intervals that should be merged. 
This would imply that there exists three intervals, $i$, $j$, and $k$ in a list of intervals `ints` 
such that $i < j < k$ and interval `ints[i]` and interval `ints[k]` can be merged together, 
but neither interval `ints[i]` and interval `ints[j]` nor 
interval `ints[j]` and interval `ints[k]` can be merged. 
From this scenario follow several inequalities:

- $ints[i].end < ints[j].start$
- $ints[j].end < ints[k].start$ 
- $ints[i].end \geq ints[k].start$ 

We can chain these inequalities to demonstrate a contradiction:

- $ints[i].end < ints[j].start \leq ints[j].end < ints[k].start$ which is contradict with $ints[i].end \geq ints[k].start$ 
 
Therefore, all mergeable intervals must occur in a contiguous run of the sorted list.

- Time complexity : $O(nlgn)$ Other than the sort invocation, we do a simple linear scan of the list, 
so the runtime is dominated by the $O(nlgn)$ complexity of sorting.

- Space complexity : $O(1)$ (or $O(n)$). If we can sort intervals in place, we do not need more than constant additional space. 
Otherwise, we must allocate linear space to store a copy of intervals and sort that.


## Reference

- https://leetcode.com/problems/merge-intervals/solution/
