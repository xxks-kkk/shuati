## Solution explanation

The problem is solved with DP. Let $F(n)$ denote the number of decode ways for a string of 
length $n$. Then we have the following recursive formula:


- $F(n) = F(n-1) + F(n-2)$ if $s[n]$ is a valid encoding digit and $s[n-1]s[n]$ is also a valid encoding
number.

- $F(n) = F(n-1)$ if $s[n]$ is a valid encoding digit and $s[n-1]s[n]$ is NOT a valid encoding number.

- $F(n) = F(n-2)$ if $s[n]$ is NOT a valid encoding digit and $s[n-1]s[n]$ is a valid encoding number.

- $F(n) = 0$ if $s[n]$ is NOT a valid encoding digit and $s[n-1]s[n]$ is NOT a valid encoding number.


Now, let's consider some examples to understand the recursive formula above:

1. For "12", there are two ways to decode it: 1) "1", "2" 2) "12". For a simple illustration, we denote
the decode ways as follows: each row represents one way of decoding:

```
1 2
- -
---
```

2. For "10", there are only one way to decode it: 1) "10" since there is no corresponding letter for "0" and
thus we cannot decode "10" as: "1", "0":

```
1 0
---
```

3. For "123", there are three ways to decode it: 1) "1", "2", "3" 2) "12", "3" 3) "1", "23". For the 
first two decode ways, they are the same as how we decode "12": first way is to treat each digit separately
and the second is to treat "12" as a whole and "3" as a single. For the third way, we treat "23" as a whole 
and treat "1" as a single.  Since both "3" (i.e., $s[n]$) and "23" (i.e., $s[n-1]s[n]$) are valid, then
by the recursive formula, we know $F(n) = F(n-1) + F(n-2)$ in this case. This formula is also consistent with our
observation. $F(n-1)$ represents ways to decode "12" and treat "3" as a single (another way of thinking
is to ignore "3" and see how many ways to decode "12" since "3" is valid. This is similar to the knapsack
problem, which we don't take the current item in the backpack or the house robber problem in which we don't
rob the current house.). $F(n-2)$ represents ways to decode "1" and treat "23" as a whole since "23" is
a valid number as well.

```
1 2 3
- - -
--- -
- ---
```

3. For "103", there is only one way to decode it: 1) "10", "3", which is $F(n-1)$ ways by treating "10"
as a whole and "3" as a single. Since "03" is invalid and thus, we cannot decode "103" as "1" and "03" and
thus, there is no $F(n-2)$ ways of decoding. Therefore, $F(n) = F(n-1)$.

```
1 0 3
--- - 
```

4. For "120", there is only one way to decode it: 1) "1", "20" since "0" is invalid and thus, we cannot
decode it as "12", "0" or "1", "2", "0". Here, we treat "20" as a whole and "1" as a single, which indicates
that $F(n) = F(n-2)$.

5. For "130", there is no way we can decode it: since "0" is invalid, we cannot decode it as either 
"1","3","0" or "13", "0". In addition, since "30" is invalid, we cannot decode it as "1", "30". Thus,
$F(n) = 0$.

The following table best summarizes the analysis above:


| Recursive formula        | $s[n]$ valid? | $s[n-1]$ valid? | Example |
|--------------------------|---------------|-----------------|---------|
| $F(n) = F(n-1) + F(n-2)$ | Yes           | Yes             | "123"   |
| $F(n) = F(n-1)$          | Yes           | No              | "103"   |
| $F(n) = F(n-2)$          | No            | Yes             | "120"   |
| $F(n) = 0$               | No            | No              | "130"   |


The above solution is exactly the same as for solving fibnacci number but in a bit different version by 
conditioning whether or not to include the value of `dp[i-1]` or `dp[i-2]`, 
while for real fibnacci number, these two values are always used to get the next number.

Of course, like the "unique path" or "house robber" problem, we can optimize the code in terms of space
complexity since we only need to keep track of two values. The code is implemented as `numDecodingsOpt1`.

## Reference

- https://www.sigmainfy.com/blog/leetcode-decode-ways.html
- https://leetcode.com/problems/decode-ways/discuss/30358
- http://www.cnblogs.com/grandyang/p/4313384.html