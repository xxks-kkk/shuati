## Solution explanation 

We may want to build a hashtable to build  <the value of `nums2`, index of the value of `nums2`>
like [this solution suggests](https://discuss.leetcode.com/topic/79182/c-solution-3ms-beats-100).
However, I don't think that can make our situation better.

To understand the hashtable solution above, consider the following example

```
[3,1,5,7,9,2,6]
[1,2,3,5,6,7,9,11]
```

The size of the hashtable may not equal to the size of `nums2`. That's why
we may want to find the max element of `nums2` first.
