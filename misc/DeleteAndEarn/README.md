## Problem Description

从一个数组里选出一个数字x，删掉，得到x分，但是同时会删除这个数组中所有的(x-1)和(x+1)，可以无限重复操作直到数组空，问最大能得几分？会有duplicates
比如【2，3，3，4，4】答案就是10，删除两个4和一个2

Given an array of n integers named elements, we can perform several steps on the array. In each step, we choose an elementsi from the array and delete it to earn elements i points; However, deleting elements i also deletes any integers equal to elements i + 1 and elements i - 1 from elements. For exampls, if elements = [1,2,3,4], deleting 2 results in elements becoming [4] and earns us 2 points.

Compute the maxPoints function that has one parameter; an array of n integers named elements. The function must return a long integer denoting the maximum number of points we can earn by performing steps.

Constraints

1<= n <= 10 (to the power 5)

1 <= elements i <= 10 (to the power 5)

Sample Input : `[3,4,2]`

Output : `6`

Explanation:

Given `elements = [3,4,2]`, we maximize our score by performing the following steps:

Delete 4 to earn 4 points, which also deletes 4 - 1 = 3 and elements becomes `[2]`.
Delete 2 to earn 2 points and elements become `[]`
There are no more elements to delete, so we can't perform any more steps. 
The function returns the total number of points which is 4 + 2 = 6.

## Solution Explanation

The problem is essentially the same as the LC 198 - House Robber. However, we may need to take some
observation to see it.

First I come up with the idea that each time we delete the maximum value. 
But it obviously doesn't work in this case: `[1, 1, 1, 2]`. Here, we can get `3` instead of `2`.

So I think about storing how many times a certain value occurs. Then each time we delete the element whose sum is the largest. 
But again it doesn't work in this case: `[1,1,1,2,2,3]`. The sum of `2` is `4`. So we delete `2` first. 
We get only `4`. But if we delete `1` (has sum `3`) and then `3` (has sum `3`), we get `6`.

Then, this problem starts to look like the "House Robber" problem. Suppose we have the following
elements: `[1,1,1,2,2,3]`, then we can build a dictionary first with key be the each unique element in
the list and values be the corresponding sum:

```
1  2  3
--------
3  4  3
```

Then, we can treat the sum of each element as the "Amount of money" in each house (i.e., element) and each
element represents the house and our constraint is once we decide to delete (i.e., rob) one element (i.e., house),
we cannot delete the elements surrounding it (i.e., trigger the alert). Thus, we can use the DP to solve this problem.

Let 

- $dp[i] = the max amount of points we can get from the first i elements by perform some delete operations$
- $dict[i] = the point we can get from the ith element$

Then, our recursion formula becomes $dp[i] = \max (dict[i] + dp[i-2], dp[i-1])$. This recursion formula
is exactly the same as the "House Robber" one.

One note on the implementation is that, we use the array to build our dictionary. The length of the 
array is equal to `max(elements) + 1` __not__ `len(elements) + 1`. However, we may waste a lot of space
(i.e., `[1,2,1000]`). Alternatively, we can use hashMap way to build our dictionary and then we need to 
sort the dictionary keys, which can lead to $O(n\log n)$ algorithm (exactly the space vs. speed tradeoff).

Similar to "House Robber", we can optimize our code towards `maxPoint1`.

## Reference

- http://www.1point3acres.com/bbs/thread-308341-1-1.html
- https://discuss.leetcode.com/topic/102381/delete-and-earn/2