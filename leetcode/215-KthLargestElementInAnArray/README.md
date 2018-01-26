## Solution explanation

There a ton of ways to solve this problem. 

### Solution 1: Use built-in `sort` [Accepted]

We can use the built-in `sort` routine and then select the $k$th largest element from
the sorted array. The solution is implemented in `findKthLargest`.

- Time complexity: $O(n\log n)$
- Space complexity: $O(1)$

### Solution 2: Use heap [Accepted]

We can also build a min heap and keep popping the smallest element from the min heap
until we have the $k$th largest element. The solution is implemented in `findKthLargest1`.

- Time complexity: $O(n + (n-k)\log n)$
- Space complexity: $O(n)$

### Solutin 3: Partition [Accepted]

In quicksort, in each iteration, we need to select a pivot and then partition the array into three parts:

- Elements smaller than the pivot;
- Elements equal to the pivot;
- Elements larger than the pivot.

Now, let’s do an example with the array `[3, 2, 1, 5, 4, 6]` in the problem statement. 
Let’s assume in each time we select the leftmost element to be the pivot, in this case, `3`. 
We then use it to partition the array into the above 3 parts, which results in `[1, 2, 3, 5, 4, 6]`. 
Now `3` is in the third position and we know that it is the third smallest element. 
Now, do you recognize that this subroutine can be used to solve this problem?

In fact, the above partition puts elements smaller than the pivot before the pivot 
and thus the pivot will then be the $k$th smallest element if it is at the $k-1$th position. 
Since the problem requires us to find the $k$th largest element, we can simply modify 
the partition to put elements larger than the pivot before the pivot. 
That is, after partition, the array becomes `[5, 6, 4, 3, 1, 2]`. 
Now we know that `3` is the $4$th largest element. 
If we are asked to find the $2$nd largest element, 
then we know it is left to `3`. If we are asked to find the $5$th largest element, 
then we know it is right to `3`. So, in the average sense, the problem is 
reduced to approximately half of its original size, giving the recursion $T(n) = T(n/2) + O(n)$ in which 
$O(n)$ is the time for partition. This recursion, once solved, gives $T(n) = O(n)$ and 
thus we have a linear time solution. Note that since we only need to consider one half of the array, 
the time complexity is $O(n)$. If we need to consider both the two halves of the array, 
like quicksort, then the recursion will be $T(n) = 2T(n/2) + O(n)$ and the complexity will be $O(nlogn)$.

Of course, $O(n)$ is the average time complexity. 
In the worst case, the recursion may become $T(n) = T(n - 1) + O(n)$ and the complexity will be $O(n^2)$.

Now let’s briefly write down the algorithm before writing our codes.

- Initialize `left` to be `0` and `right` to be `len(nums)-1`
- Partition the array, if the pivot is at the $k-1$th position, return it (we are done);
- If the pivot is right to the $k-1$th position, update right to be the left neighbor of the pivot;
- Else update left to be the right neighbor of the pivot.
- Repeat 2.

The solution is implemented in `findKthLargest2`. The code structure resembles the binary search structure
with the invariant: the $k$th largest element $\in [\texttt{left}, \texttt{right}]$. The `partition` function
is very typical and should be remembered.

## Reference

- http://www.cnblogs.com/grandyang/p/4539757.html
- https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309