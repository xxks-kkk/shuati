## Solution Explanation

The idea of the algorithm is following:

1. For each house, find its position between those heaters (thus we need the heaters array to be sorted).
2. Calculate the distances between this house and left heater and right heater, get a min value of those two values. 
Corner cases are there is no left or right heater.
3. Get max value among distances in step 2. It’s the answer.

For step 1, we use the modification of binary search: [findFirstGreaterEqualTo](https://github.com/xxks-kkk/shuati/blob/master/misc/BinarySearch/binarySearch-2.py).

## Reference

- https://leetcode.com/problems/heaters/discuss/95886
- http://www.cnblogs.com/grandyang/p/6181626.html