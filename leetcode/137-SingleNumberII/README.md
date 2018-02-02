## Solution explanation

If we recall "Single Number", we have XOR operator, which satisfy the following two properties:

- If we take XOR of zero and some bit, it will return that bit

    - $a \oplus 0 = a$

- If we take XOR of two same bits, it will return 0

    - $a \oplus a =0$

- $a \oplus b \oplus a = a \oplus a \oplus b  = (a \oplus a) \oplus b = 0 \oplus b = b$

Those properties ensure us that:
 
1) the order of input doesn't have the impact on the final result (i.e., 
$B \oplus A \oplus B = B \oplus B \oplus A = A$)
2) $A \oplus B \oplus \dots \oplus B = A$ as long as the number of $B$ is a multiple of 2.

The solution to "Single Number" inspires us two ways to solve "Single Number II":

1) For $k = 3$, we can simulate "single number" pattern by making sure whenever the same number appears
three times, we make the final result to 0 and result only keeps the exception number

2) We design an operator that works like XOR in the sense that it has the same properties as the XOR
and then we can apply this operator in the same way we did with "Single Number" problem to get our 
answer.


### Solution 1: Ones & Twos [Accepted]

We think of the counting of appearance of a number as the transitions among states:
we start with state 0, which indicate the number has appeared. Then, we move to 
state 1, state 2, and then back to state 0, which implies that the appearance of the
same three numbers means nothing to us (i.e., pretending they are not in the list).
Since each number appears three times except for one number, we can use 2 bits to 
keep track of the states:

```
0  -> 1  -> 2  -> 0
00 -> 01 -> 10 -> 00
00 -> 10 -> 01 -> 00
```

The third line of above is just for the convenice of implementation, which we swap the position
of `01` with position of `10`. We use `twos` to represent the first bit counting from right and `twos`
to represent the second bit counting from right. The idea roughly looks like:

1. When we see a number appears for the first time, we store it to `ones` (representing `10`)
2. When we see a number appears twice, we store it to `twos` and clear up the number on `ones` 
(representing `01`)
3. When we see a number appears for the third time, we clear `twos` (representing `00`)

The following picture illustrates the idea above:

```
ones     twos
0        0
0 -> 1   0 -> 0
1 -> 0   0 -> 1
0 -> 0   1 -> 0
```

The code above works well for a sequence like `[1, 1, 1, 2]`. But, it is still unclear to me that
how the magic happens for a sequence like `[1,1,2,1]`, where the appearance of the same number
no consecutively. We return `ones | twos` because we don't know how many times the exception number
can appear. If it appears only once, we can return `ones` only, which represents `10` state, which 
comes immediately after state `00`. If the exception number appears twice, we can return `twos` only,
which represent `01` state, which comes from `00 -> 10 -> 01`.

The solution is implemented in `singleNumber`.

### Solution 2: Digital Circuit Design [Accepted]

This solution can work for any problem: every one occurs $k$ times except one occurs $m$ times
as long as $m$ is not a multiple of $k$. The solution itself is very confusing to me. Here, I just
describe the workflow for this approach:

1. We design the state transition table

To represent 3 state, we need two bit. let say it is `a` and `b`, and `c` is the incoming bit.
then we can design a table to implement the state move:

```
current   incoming  next
a b            c    a b
0 0            0    0 0
0 1            0    0 1
1 0            0    1 0
0 0            1    0 1
0 1            1    1 0
1 0            1    0 0
```

like circuit design, we can find out what the next state will be with the incoming bit.( we only need find the ones)
then we have for `a` to be 1, we have

```
current   incoming  next
a b            c    a b
1 0            0    1 0
0 1            1    1 0
```

and this is can be represented by `a=a&~b&~c + ~a&b&c` and `b` can do the same we , and we find that
`b= ~a&b&~c+~a&~b&c`.
,
2. That's it!

We need to use a temporary variable `ta` just because all the calculation is based upon the old `a` and
`b`. The reason we return `a|b` (`|` means bit-wise OR) with the same reasoning as we do with the 
previous solution `ones|twos`.

The solution is implemented in `singleNumber1`.

## Reference

- https://www.youtube.com/watch?v=1m5e5d_OFzU
- https://discuss.leetcode.com/topic/22821/an-general-way-to-handle-all-this-sort-of-questions