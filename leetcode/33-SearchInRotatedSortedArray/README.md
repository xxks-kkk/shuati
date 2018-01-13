## Solution Explanation

Use `[0,1,2,4,5,6,7]` as an example. There are 7 ways of rotation:

```
0,1,2,4,5,6,7
7,0,1,2,4,5,6
6,7,0,1,2,4,5
5,6,7,0,1,2,4
4,5,6,7,0,1,2
2,4,5,6,7,0,1
1,2,4,5,6,7,0
```

二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段.
通过上面例子，我们可以观察出规律，如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，
我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了


## Reference

- http://www.cnblogs.com/grandyang/p/4325648.html
- http://bangbingsyb.blogspot.com/2014/11/leetcode-search-in-rotated-sorted-array.html