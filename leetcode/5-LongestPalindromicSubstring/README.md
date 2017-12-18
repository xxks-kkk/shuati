
# Solution Explanation

Throughout this explanation, we'll use the word "bananas" for the demonstration
(i.e., `s = "bananas"`)

## Solution 1: Including characters


## Solution 2: Expand Around Center


## Solution 3: Dynamic Programming

string `s` is palindrome if:

- first char and last char of `s` should match
- substring (excluding first and last chars) is palindrome

We define $P(i,j)$ as follows:

- $P(i,j) = \text{True}$ if the substring $s_i \dots s_j$ is a palindrome
- $P(i,j) = \text{False}$ otherwise

Then the recursion we have:

- $P(i,j) = \text{True}$ if $P(i+1, j-1) = \text{True}$ and $s_i = s_j$

We have two base cases:

- When there is only a single char in `s`: $P(i,i) = \text{True}$
- When there are two chars in `s`: $P(i, i+1) = I_{s_i = s_{i+1}}$

Then we can first check palindrome for the substring contains one char and the substring
contains two chars. This is to finish all the base cases. Then we can work
our way up finding all the substring with three chars to see whether they are
palindrome and so on.

Programming-wise, we maintain a boolean table `P[n][n]` with `n` being
the number of chars in `s`. The value of `P[i][j]` is true if 
`s[i:j+1]` is palindrome. Otherwise, the value is false.

To calculate `P[i][j]` (for substrings with three chars and more), we
first check the value of `P[i+1][j-1]`, if the value is true and 
`s[i]` is the same as `s[j]`, then we make `P[i][j]` true. Otherwise,
the value of `P[i][j]` is set to false. This is the consistent with
palindrome definition.

For the example, we have the following table:

```
| i\j | B | A | N | A | N | A | S |
|-----|---|---|---|---|---|---|---|
| B   |   |   |   |   |   |   |   |
| A   |   |   |   |   |   |   |   |
| N   |   |   |   |   |   |   |   |
| A   |   |   |   |   |   |   |   |
| N   |   |   |   |   |   |   |   |
| A   |   |   |   |   |   |   |   |
| S   |   |   |   |   |   |   |   |

```

We first initialize the first basic case: substring with single char 
(ie. tracked by `curr_len` in code) and the table looks like below:

```
| i\j | B | A | N | A | N | A | S |
|-----|---|---|---|---|---|---|---|
| B   | T |   |   |   |   |   |   |
| A   |   | T |   |   |   |   |   |
| N   |   |   | T |   |   |   |   |
| A   |   |   |   | T |   |   |   |
| N   |   |   |   |   | T |   |   |
| A   |   |   |   |   |   | T |   |
| S   |   |   |   |   |   |   | T |
```

Then we initialize the second base case: substring with two chars

```
| i\j | B | A | N | A | N | A | S |
|-----|---|---|---|---|---|---|---|
| B   | T | F |   |   |   |   |   |
| A   |   | T | F |   |   |   |   |
| N   |   |   | T | F |   |   |   |
| A   |   |   |   | T | F |   |   |
| N   |   |   |   |   | T | F |   |
| A   |   |   |   |   |   | T | F |
| S   |   |   |   |   |   |   | T |
```

Now we can take a look at the substring with three chars. For example,
"BAN", which is `P[0][2]` and `P[1][1]` (i.e., "A") is `T` and `s[0]`
not equal to `s[2]` and thus, `P[0][2]` is false. We perform this operation
and fill the table like below:

```
| i\j | B | A | N | A | N | A | S |
|-----|---|---|---|---|---|---|---|
| B   | T | F | F |   |   |   |   |
| A   |   | T | F | T |   |   |   |
| N   |   |   | T | F | T |   |   |
| A   |   |   |   | T | F | T |   |
| N   |   |   |   |   | T | F | F |
| A   |   |   |   |   |   | T | F |
| S   |   |   |   |   |   |   | T |
```

Now, we look at the substring with four chars and so on. The table finally
will look like:

```
| i\j | B | A | N | A | N | A | S |
|-----|---|---|---|---|---|---|---|
| B   | T | F | F | F | F | F | F |
| A   |   | T | F | T | F | T | F |
| N   |   |   | T | F | T | F | F |
| A   |   |   |   | T | F | T | F |
| N   |   |   |   |   | T | F | F |
| A   |   |   |   |   |   | T | F |
| S   |   |   |   |   |   |   | T |
```

Thus, the answer we have is `ANANA`. Note that we keep track of
the max length of palindrome (i.e., `maxLength` in code) and
where the longest palindrome starts (i.e., `palindromeBeginsAt`).

## Reference


- https://leetcode.com/problems/longest-palindromic-substring/solution/
- http://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
- https://www.youtube.com/watch?v=obBdxeCx_Qs