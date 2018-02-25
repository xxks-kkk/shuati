## Solution explanation

### Basic Observation

Firstly, we know that in order to make all the elements equal to each other with minimum moves, we need to do the 
increments in all but the maximum element of the array. Thus, in the brute force approach, 
we scan the complete array to find the maximum and the minimum element. 
After this, we add 1 to all the elements except the maximum element, and 
increment the count for the number of moves done. Again, we repeat the same process, 
and this continues until the maximum and the minimum element become equal to each other.

In the above description, we added 1 to every element in a single step. 
But, we can modify this approach to some extent. 
In order to make the minimum element equal to the maximum element, 
we need to add 1 at least $k$ times, after which, the maximum element could change. 
Thus, instead of incrementing in steps of 1, we increment in bursts, where each burst will be of size 
$k=\text{max}-\text{min}$. Thus, we scan the complete array to find the maximum and minimum element. 
Then, we increment every element by $k$ units and add $k$ to the count of moves. 
Again we repeat the same process, until the maximum and minimum element become equal.

### Approach 1: Using sorting [Accpted]

The problem gets simplified if we sort the given array first. Now, we use the difference $\text{diff}=\text{max}-\text{min}$ 
to update the elements of the array, but we need not traverse the whole array to find the maximum and minimum 
element every time because we can find the maximum and minimum element after update in $O(1)$ time. 
Further, we need not actually update all the elements of the array. 
To understand how this works, we'll go in a stepwise manner.

Firstly, assume that we are updating the elements of the sorted array after every step of calculating the difference 
$diff$. We'll see how to find the maximum and minimum element without traversing the array. 
In the first step, the last element is the largest element. Therefore, $\text{diff}=a[n-1]-a[0]$. 
We add $diff$ to all the elements except the last one (i.e., $a[n-1]$). 
Now, the updated element at index 0, $a'[0]$ will be $a[0]+\text{diff}=a[n-1]$. 
Thus, the smallest element $a'[0]$ is now equal to the previous largest element $a[n-1]$. 
Since, the elements of the array are sorted, the elements up to index $i-2$ satisfy the property $a[j] \ge a[j-1]$. 
Thus, after updation, the element $a'[n-2]$ will become the largest element due to the sorted array property. 
Also, $a[0]$ is still the smallest element.

Thus, for the second update, we consider the difference $\text{diff} =a[n-2]-a[0]$. After update, $a[0]$ 
will become equal to $a[n-2]$ similar to the first iteration. Further, since $a[0] = a[n-1]$ from
the first iteration and now $a[0] = a[n-2]$, now the largest element will be $a[n-3]$. 
Thus, we can continue in this fashion, and keep on incrementing the number of moves with 
the difference found at every step.

Now, let's come to step 2. In the first step, we assumed that we are updating the elements of the array $a$ at every step, 
but we need not do this. This is because, even after updating the elements 
the difference which we consider to add to the number of moves required remains the same 
because both the elements $\text{max}$ and $\text{min}$ required to find the $\text{diff}$ get 
updated by the same amount everytime.

Thus, we can simply sort the given array once and use $\text{moves}=\sum_{i=1}^{n-1} (a[i]-a[0])$.

The solution is implemented in `minMoves`.

- Time complexity : $O\big(nlog(n)\big)$. Sorting will take $O\big(nlog(n)\big)$ time.
- Space complexity : $O(1)$. No extra space required.

### Approach 2: Using DP [Accpted]

The given problem can be simplified if we sort the given array once. If we consider a sorted array $a$, 
instead of trying to work on the complete problem of equalizing every element of the array, 
we can break the problem for array of size nn into problems of solving arrays of smaller sizes. 
Assuming, the elements up to index $i-1$ have been equalized, we can simply consider the element at index $i$
 and add the difference $\text{diff}=a[i]-a[i-1]$ to the total number of moves for the array up to index $i$ to be equalized 
(i.e. $\text{moves}=\text{moves}+\text{diff}$. But when we try to proceed with this step, as per a valid move, 
the elements following $a[i]$ will also be incremented by the amount \text{diff} (i.e. $a[j]=a[j]+\text{diff}), for $j>i$. 
But while implementing this approach, we need not increment all such $a[j]$'s. Instead, 
we'll add the number of moves done so far to the current element (i.e. $a[i]$) and update it to $a'[i]=a[i]+\text{moves}$.

In short, we sort the given array, and keep on updating the movesmoves required so far in order to equalize the 
elements up to the current index without actually changing the elements of the array except the current element. 
After the complete array has been scanned `moves` gives the required solution.

To better understand the above text, let's consider a simple example `[3,10,13]`.

- `[3,10,13]`: when `i = 1`, `moves = 0` and `diff = 10 - 3 + 0 = 7`. Then, by DP recursion, we equalize the
element upto `i` and we have `[10,10,13]` and `moves = 7`. By the problem definition, we should have
`[10,10,20]`. 
- `[10,10,13]`: when `i = 2`, `moves = 7` and `diff = 13 - 10 + 7 = 10`. Calculation of `diff` is essentially equivalent
to take `[10,10,20]` and calculate `diff = 20 - 10 = 10`. Then, by DP recursion, we equalize the element upto
`i` and we have `[20,20,20]` and `moves = 7 + 10 = 17`.

The solution is implemented in `minMoves1`.

- Time complexity : $O\big(nlog(n)\big)$. Sorting will take $O\big(nlog(n)\big)$ time.
- Space complexity : $O(1)$. Only single extra variable is used.

### Approach 3: Using Math [Accepted]

This approach is based on the idea that adding 1 to all the elements except one is equivalent to 
decrementing 1 from a single element, since we are interested in the relative levels of the elements which need to be equalized. 
Thus, the problem is simplified to find the number of decrement operations required to equalize all the elements of the given array. 
For finding this, it is obvious that we'll reduce all the elements of the array to the minimum element. 
But, in order to find the solution, we need not actually decrement the elements. We can find the number of moves required as 
$\text{moves}=\sum_{i=0}^{n-1} a[i] - min(a)*n$ where $n$ is the length of the array.

Another way to think about it is that adding 1 to all the elements except one is equivalent to 
decrementing 1 from a single element. we assume that we want to reduce all the elements to `0` and the total moves required
is $\sum_{i=0}^{n-1} a[i]$. However, since problem is only required as to equalize all the elements and we
can only target at equalizing all the elements to the minimum value of the array. Thus, the number of moves
in total becomes $\text{moves}=\sum_{i=0}^{n-1} a[i] - min(a)*n$.

The solution is implemented in `minMoves2`.

- Time complexity : $O(n)$. We traverse the complete array once.
- Space complexity : $O(1)$. No extra space required.

### Approach 4: Modified Approach Using Maths [Accepted]

There could be a problem with the above approach. The value $\sum_{i=0}^{n-1} a[i]$ could be very large and 
hence could lead to integer overflow if the $a[i]$'s are very large. To avoid this problem, 
we can calculate the required number of moves on the fly: $\sum_{i=0}^{n-1} (a[i]-min(a))$.

- Time complexity : $O(n)$. One pass for finding minimum and one pass for calculating moves.
- Space complexity : $O(1)$. No extra space required.

## Reference

- https://leetcode.com/problems/minimum-moves-to-equal-array-elements/solution/