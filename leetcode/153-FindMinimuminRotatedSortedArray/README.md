## Solution explanation

The problem is similar to "33. Search in Rotated Sorted Array". 
Looking at subarray with index `[left,right]`. We can find out that 
if the first element is less than the last element, there’s no rotation in the array. 
So we could directly return the first element in this subarray.
If the first element is larger than the last one, then we compute the element in the middle, 
and compare it with the first element. If value of the element in the middle is larger than the first element, 
we know the rotation is at the second half of this array
(i.e., middle element is `7` in `[4,5,6,7,0,1,2]` and rotation is at the second half of the array
means that the minimum value is in the second half of the array). Else, it is in the first half in the array.


## Reference

- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/48493
- http://www.cnblogs.com/grandyang/p/4032934.html