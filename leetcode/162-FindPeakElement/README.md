## Solution explanation

### Solution 1: Linear Scan [Accepted]

In this approach, we make use of the fact that two consecutive numbers `nums[i]` and `nums[i + 1]`
 are never equal. Thus, we can traverse over the `nums` array starting from the beginning. 
 Whenever, we find a number `nums[i]`, we only need to check if it is larger than the next number 
 `nums[i+1]` for determining if `nums[i]` is the peak element. 
 The reasoning behind this can be understood by taking the following three cases which cover every case into 
 which any problem can be divided.
 
 - Case 1: All the numbers appear in a descending order. 
 
    In this case, the first element corresponds to the peak element. We start off by checking if the current element 
    is larger than the next one. The first element satisfies this criteria, and is hence identified as the peak correctly. 
    In this case, we didn't reach a point where we needed to compare `nums[i]` with `nums[i-1]` also, 
    to determine if it is the peak element or not.
    
    ![case1](case1.PNG)
    
- Case 2: All the elements appear in ascending order. 

    In this case, we keep on comparing `nums[i]` with `nums[i+1]` to determine if `nums[i]`
    is the peak element or not. None of the elements satisfy this criteria, indicating that we are currently on a 
    rising slope and not on a peak. Thus, at the end, we need to return the last element as the peak element, 
    which turns out to be correct. In this case also, we need not compare `nums[i]` with `nums[i-1]`, 
    since being on the rising slope is a sufficient condition to ensure that `nums[i]` isn't the peak element.

    ![case2](case2.PNG)

- Case 3: The peak appears somewhere in the middle. 

    In this case, when we are traversing on the rising edge, as in Case 2, none of the elements will satisfy 
    `nums[i] > nums[i + 1]`. We need not compare `nums[i]` with `nums[i-1]` on the rising slope as discussed above. 
    When we finally reach the peak element, the condition `nums[i] > nums[i + 1]` is satisfied. 
    We again, need not compare `nums[i]` with `nums[i-1]`. This is because, we could reach `nums[i]` as the current 
    element only when the check `nums[i] > nums[i + 1]` failed for the previous $(i-1)^{th}$ element, indicating that 
    `nums[i-1] < nums[i]`. Thus, we are able to identify the peak element correctly in this case as well.

    ![case3](case3.PNG)

- Time complexity: $O(n)$ 
- Space complexity: $O(1)$


### Solution 2: Binary Search [Accepted]

We can view any given sequence in numsnums array as alternating ascending and descending sequences. 
By making use of this, and the fact that we can return any peak as the result, 
we can make use of Binary Search to find the required peak element.

In case of simple Binary Search, we work on a sorted sequence of numbers and try to find out the required number 
by reducing the search space at every step. In this case, we use a modification of this simple Binary Search to our advantage. 
We start off by finding the middle element, `mid` from the given `nums` array. 
If this element happens to be lying in a descending sequence of numbers. or a local falling slope
(found by comparing `nums[i]` to its right neighbour), it means that the peak will always lie towards the left of this element. 
Thus, we reduce the search space to the left of `mid`(including itself) and perform the same process on left subarray.

If the middle element, `mid` lies in an ascending sequence of numbers, or a rising slope
(found by comparing `nums[i]` to its right neighbour), it obviously implies that the peak lies towards the right of this element. 
Thus, we reduce the search space to the right of `mid` and perform the same process on the right subarray.

In this way, we keep on reducing the search space till we eventually reach a state where only one element is 
remaining in the search space. This single element is the peak element.

In short, we want to maintain the invariant that: if there is a peak element in the array, its index $i$ has
be in the range $\[\text{left}, \text{right}\]$.


## Reference

- https://leetcode.com/problems/find-peak-element/solution/