## Solution explanation

In the problem, we are given two arrays and asked to find the median. Let's start from one array.

### One-array case

The key observation to solve this problem is on the definition of median:

Given a sorted array, the median is the cut that divides the array into two subarrays with equal length. The median's value
can be calculated by take average of the maximum value of the left subarray (denoted as $L$)
and the minimum value of the right subarray (denoted as $R$)
(i.e., the average of two numbers that are immediately next to the cut).

- Example 1:

Given a sorted array `[2,3,5,7]`, we cut it like `[2 3 / 5 7]` (we use `/` to denote the cut) and left subarray is
`[2 3]` and the right subarray is `[5 7]`. The median is (3+5)/2 = 4, which is the average of the max number in left
subarray ($L=3$) and the min number in the right subarray ($R=5$).

- Example 2:

Given a sorted array `[1,2,3]`, the median is `2` represented as `[1, (2/2), 3]`. We split 2 into two halves and
both left and right subarray contains 2. The median is (2+2)/2 = 2.

Next, we observe the relationship between the index of $L$, index of $R$, and $N$, and we have:

```
N        Index of L / Index of R
1                 0 / 0
2                 0 / 1
3                 1 / 1
4                 1 / 2
5                 2 / 2
6                 2 / 3
7                 3 / 3
8                 3 / 4
```

We can see that:

- Index of $L$ is $(N-1)/2$
- Index of $R$ is $N/2$

Thus, the median value can be calculated as $\frac{A[(N-1)/2] + A[N/2]}{2}$. We will use this observation for the two
array case.

From the above observation, we obtain the relations between index of $L$, index of $R$, and $N$. In fact, the relations
also hold for cut position. In other words, we have:

- Index of $L$ is $(\text{cutPos} - 1)/2$
- Index of $R$ is $(\text{cutPos})/2$

To see this, let's add a few imaginary 'positions' (represented as #'s) in between numbers, and treat numbers as 'positions'.
Doing so allows us to obtain position for cut as well:

```
[6 9 13 18]     ->    [# 6 # 9 # 13 # 18 #]        (N = 4)
position index         0 1 2 3 4 5  6 7  8         (N_Position = 9)

[6 9 11 13 18]  ->    [# 6 # 9 # 11 # 13 # 18 #]   (N = 5)
position index         0 1 2 3 4 5  6 7  8 9 10    (N_Position = 11)
```

As you can see, there are always exactly $2N+1$ 'positions' regardless of length $N$. Therefore,
the middle cut should always be made on the $N$th position (0-based). Since index of $L$ is
$(N-1)/2$ and index of $R$ is $N/2$ in this situation, we can infer that
index of $L$ is $(\text{cutPos} - 1)/2$ and index of $R$ is $(\text{cutPos})/2$.


### Two-array case

```
A1: [# 1 # 2 # 3 # 4 # 5 #]    (N1 = 5, N1_positions = 11)

A2: [# 1 # 1 # 1 # 1 #]        (N2 = 4, N2_positions = 9)
```

Similar to one-array problem, we need to find a cut that divides the two arrays each into two subarrays such that:
all numbers in the left two subarrays $\le$ all numbers in the right two subarrays.

We make the following observations:

- There are $2N1+2N2+2$ position altogether. Therefore, there must be exactly
$N1+N2$ positions in total for left two subarrays and $N1 + N2$ positions in total
for right two subarrays. There are 2 cuts take 2 positions.

- When we cut at position C2 = k in A2, then the cut position for A1 = N1 + N2 - K. For instance,
if C2 = 2, then we must have C1 = 4 + 5 - C2 = 7:

```
 [# 1 # 2 # 3 # (4/4) # 5 #]

 [# 1 / 1 # 1 # 1 #]
```

- When the cuts are made, we'd have two $L$'s and two $R$'s. They are, by the observation we make from one-array case:

```
 L1 = A1[(C1-1)/2]; R1 = A1[C1/2];
 L2 = A2[(C2-1)/2]; R2 = A2[C2/2];
```

For the above example, we have:

```
L1 = A1[(7-1)/2] = A1[3] = 4; R1 = A1[7/2] = A1[3] = 4;
L2 = A2[(2-1)/2] = A2[0] = 1; R2 = A1[2/2] = A1[1] = 1;
```

Now, to determine which two cuts we want, we have to use the definition of median by ensuring that

$$L1 \le R1 \land L1 \le R2 \land L2 \le R1 \land L2 \le R2$$

This will make sure that we have all numbers in the left two subarrays $\le$ all numbers in the right two subarrays
as L1, L2 are the greatest numbers on the left two subarrays and R1, R2 are the smallest numbers on the right two subarrays.
Since both A1 and A2 are sorted, $L1 \le R1$ and $L2 \le R2$ are guaranteed. Thus, we only need to ensure that
$L1 \le R2 \land L2 \le R1$. This is the invariant we want to keep in our binary search solution:

- If we have $L1 > R2$, this means there are too many large numbers on the left subarray of A1, thus we need to move C1 to
the left, which means we move C2 to the right (as C1 + C2 = N1 + N2)

- If we have $L2 > R1$, this means that there are too many large numbers on the left subarray of A2, thus we need to move
C2 to the left.

- Otherwise, we get the right cuts, and compute median as $(\max(L1,L2) + \min(R1,R2))/2$

**NOTE:**

- Once we determine C1, C2 is determined automatically. We want to search the cut in the shorter array as this will reduce
our total running time to $O(\log(\min(m,n)))$.

- There is one special case that when a cut falls on the 0th(first) or the 2Nth(last) position. For instance,
if C2 = 2N2, then R2 = A2[2*N2/2] = A2[N2], which exceeds the boundary of the array.
To solve this problem, we can imagine that both A1 and A2 actually have two extra elements,
`INT_MAX` at A[-1] and `INT_MAX` at A[N]. These additions don't change the result,
but make the implementation easier: If any L falls out of the left boundary of the array,
then $L$ = `INT_MIN`, and if any $R$ falls out of the right boundary, then R = `INT_MAX`.

## Key Points

- The definition of median

- Obtain $L$, $R$, cutPos relations:

    - Index of $L$ is $(\text{cutPos} - 1)/2$
    - Index of $R$ is $(\text{cutPos})/2$

- Maintain the definition of median: all numbers in the left two subarrays $\le$ all numbers in the right two subarrays

- Observe C1 + C2 = N1 + N2

- Handle the special case

## Reference

- https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation