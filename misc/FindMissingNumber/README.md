## Solution explanation

### $O(N)$ approach

We use two pointers

### $O(\log N)$ appraoch

We know the given array is sorted. Take `[4,5,6,8,9]` as an example. Instead
of thinking about this array, we think about `[0,1,2,4,5]`, which is obtained
by subtracting every number of the original array with the beginning number of
the original array (i.e. `4`). We call this new array `b`. The nice thing about doing this is that:

If there is no missing number, we should have `b[i] = i`. This is the key insight
for the binary search. Now we have:

| a   | 4 | 5 | 6 | 8 | 9 | 10 |
|-----|---|---|---|---|---|----|
| b   | 0 | 1 | 2 | 4 | 5 | 6  |
| idx | 0 | 1 | 2 | 3 | 4 | 5  |

From this table, we can see that if `a[mid] == mid + a[0]`, then we can safely
get rid of number to left of the `mid` including `mid` (i.e. `mid = 2`). On the other hand,
if `a[mid] > mid + a[0]` (i.e. `mid = 4`), then we know the missing number is
to the left of the `mid`. By maintaining the invariant, we find the solution.


## Reference

- https://www.geeksforgeeks.org/find-the-first-missing-number/
