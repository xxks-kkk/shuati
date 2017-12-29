## Solution Explanation

The solution is modification of the binary search. Instead of retuning the index once we
find the target value, we keep searching until the while loop in `extreme_insertion_index`
terminates. Whether we return `low` or `high` depends on the if check inside the function.
Usually, I think it is hard to rememeber how to write those functions. So, I remember the
basic binary search and modify the code whenever necessary. Overall, the modification
to the binary search is not different much from the basic one.


## Reference

- https://leetcode.com/problems/search-for-a-range/solution/
- https://leetcode.com/problems/search-for-a-range/discuss/14701