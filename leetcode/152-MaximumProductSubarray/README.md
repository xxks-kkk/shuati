## Solution explanation

We use DP approach of this problem. Besides keeping track of the largest product, 
we also need to keep track of the smallest product. Why? 
The smallest product, which is the largest in the negative sense could 
become the maximum when being multiplied by a negative number.

- $f(k) = \text{Largest product subarray, from index 0 up to k}$
- $g(k) = \text{Smallest product subarray, from index 0 up to k}$

Then

- $f(k) = \max( f(k-1) * A[k], A[k], g(k-1) * A[k] )$
- $g(k) = \min( g(k-1) * A[k], A[k], f(k-1) * A[k] )$

Then the code follows. The code can be further optimized by using only one variable to
keep track of both min and max but DP idea is the same. You can check further optimization
version in the reference link.

### Remarks

DP formula falls into the category of "all possible situations of picking up the current element",
which is similar to "whether to pick up the current element or not" (i.e. "House Robber"). 

## Reference

- http://www.cnblogs.com/grandyang/p/4028713.html