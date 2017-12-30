## Solution Explanation

It could be overwhelming thinking of all possibilities on which houses to rob.
A natural way to approach this problem is to work on the simplest case first.

Let us denote that:

- $f(k)$ = Largest amount that you can rob from the first k houses.
- $A_i$ = Amount of money at the ith house.

Let us look at the case `n = 1`, clearly $f(1) = A_1$.
Now, let us look at `n = 2`, which $f(2) = max(A_1, A_2)$.
For n = 3, you have basically the following two options:

- Rob the third house, and add its amount to the first house's amount. We cannot
rob the second house because the third house and the second house are adjacent.

- Do not rob the third house, and stick with the maximum amount of the first two houses.

Clearly, you would want to choose the larger of the two options at each step.
Therefore, we could summarize the formula as following:

- $f(k) = max(f(k – 2) + A_k, f(k – 1))$

We choose the base case as `f(–1) = f(0) = 0`, which will greatly simplify our code as you can see.

The answer will be calculated as `f(n)`. 
We could use an array to store and calculate the result, 
but since at each step you only need the previous two maximum values, two variables are suffice.

To summarize the recursion formula above, we have

```
f(0) = nums[0]
f(1) = max(num[0], num[1])
f(k) = max( f(k-2) + nums[k], f(k-1) )
```

In the implementation, `last` refers to the `f(k-2)` and `now` refers to `f(k-1)`. To
help with the understanding, you can think of 3 houses case and `last` points to the first
house and `now` points to the second house. We are trying to figure out the maximum
amount we can rob given 3 houses.

```
0      1      2
^      ^      ^
|      |      |
last   now    ?
```


## Reference

- https://leetcode.com/problems/house-robber/discuss/55696
- https://leetcode.com/problems/house-robber/solution/
