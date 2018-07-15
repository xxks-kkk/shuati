## Solution explanation

The key is how we can handle the "*"

### Dynamic Programming

We let $DP[i][j] = \text{whether} p[0 \dots j-1] \text{matches} s[0 \dots i-1]$. Then we have the following recurrence
relations:

- When `s[i] == p[j]` or `p[j] == '.'`:  we have $DP[i][j] = DP[i-1][j-1]$
- When `p[j] == '*'`: we have two subconditions:
    - When `p[j-1] != s[i]`:
        - We treat 'a*' as empty (in order to make $DP[i][j]$ be true): $DP[i][j] = DP[i][j-2]$
    - When `p[j-1] == s[i]` or `p[j-1] == '.'`:
        - We treat 'a*' as empty: $DP[i][j] = DP[i][j-2]$
        - We treat 'a*' as single 'a': $DP[i][j] = DP[i][j-1]$
        - We treat 'a*' as multiple 'a': $DP[i][j] = DP[i-1][j]$

To better understand the above equations, let's consider the following example

| s | a | a | a |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|
| p | a | b | * | a | * | c | * | a |

When we get to '*', since 'b' != 'a', we can only ignore 'b*' as whole and that leads $DP[i][j] = DP[i][j-2]$. If
we change 'b' to 'a', then we have three possible options. For example, we can let '*' to match multiple 'a' in s,
which effectively doesn't consume char in p but consume char in s: $DP[i][j] = DP[i-1][j]$.

**NOTE:** when think of the DP relation equation, we can think about S, P in the backward, which means following
the $DP[i][j]$ definition exactly. For the example above, we can think about as

```
+++++++++++  DP[2][2]
          +
| s | a | +  a | a |   |   |   |   |   |
|---|---| + ---|---|---|---|---|---|---|
| p | a | +  b | * | a | * | c | * | a |
          +
+++++++++++
```


## Reference

- https://leetcode.com/problems/regular-expression-matching/discuss/5651/Easy-DP-Java-Solution-with-detailed-Explanation
- http://xiaohuiliucuriosity.blogspot.com/2014/12/regular-expression-matching.html