## Solution Explanation

We use Fast Power Algorithm, which can be written recursively or iteratively. 

### Recursive

#### Intuition

Assuming we have got the result of $x^n$, how can we get $x^{2 * n}$? 
Obviously we do not need to multiply `x` for another `n` times. 
Using the formula $(x ^ n) ^ 2 = x ^ {2 * n}$, we can get $x ^ {2 * n}$
at the cost of only one computation. 
Using this optimization, we can reduce the time complexity of our algorithm.

Algorithm

Assume we have got the result of $x ^ {n / 2}$​, and now we want to get the result of x ^ n.
​Let A be result of $x ^ {n / 2}$, we can talk about $x ^ n$ based on the parity of `n` respectively. 
If `n` is even, we can use the formula $(x ^ n) ^ 2 = x ^ {2 * n}$ to get $x ^ n = A * A$. 
​If `n` is odd, then $A * A = x ^ {n - 1}$. Intuitively, We need to multiply another `x` to the result, 
so $x ^ n = A * A * x$. 
This approach can be easily implemented using recursion. We call this method "Fast Power", 
because we only need at most $O(log(n))$ computations to get $x ^ n$.

- Time complexity : $O(log(n))$ Each time we apply the formula $(x ^ n) ^ 2 = x ^ {2 * n}$, 
$n$ is reduced by half. Thus we need at most $O(log(n))$ computations to get the result.

- Space complexity : $O(log(n))$. For each computation, we need to store the result of $x ^ {n / 2}$. 
We need to do the computation for $O(log(n))$ times, so the space complexity is $O(log(n))$.

### Iterative

#### Intuition

Using the formula $x ^ {a + b} = x ^ a * x ^ b$, 
we can write `n` as a sum of positive integers, $n = \sum_i b_i$.
​​If we can get the result of $x ^ {b_i}$ quickly, the total time for computing 
$x ^ n$ will be reduced.

#### Algorithm

We can use the binary representation of n to better understand the problem. 
Let the binary representation of `n` to be $b_1, b_2, ..., b_{length\_limit}$,
from the Least Significant Bit(LSB) to the Most Significant Bit(MSB). 
For the `i`th bit, if $b_i = 1$, it means we need to multiply the result by $x ^ {2 ^ i}$.
It seems to have no improvement with this representation, since $\sum_i b_i * 2 ^ i = n$.
But using the formula $(x ^ n) ^ 2 = x ^ {2 * n}$ we mentioned above, we can see some differences. 
Initially $x ^ 1 = x$, and for each $i > 1$, we can use the result of $x ^ {2 ^ {i - 1}}$
to get $x ^ {2 ^ i}$ in one step. Since the number of $b_i$ is at most $O(log(n))$, 
we can get all $x ^ {2 ^ i}$ in $O(log(n))$ time. After that, for all `i`s that satisfy $b_i = 1$, 
we can multiply $x ^ {2 ^ i}$ to the result. This also requires $O(log(n))$ time.

- Time complexity : $O(log(n))$. For each bit of n 's binary representation, we will at most multiply once. So the total time complexity is O(log(n))O(log(n)).

- Space complexity : $O(1)$. We only need two variables for the current product and the final result of x.

## Reference

- https://en.wikipedia.org/wiki/Exponentiation_by_squaring