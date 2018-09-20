## Solution explanation

We can easily see whether it is rotated if B can be found in (A + A).
For example, with A = "abcde", B = "cdeab", we have

```
“abcdeabcde” (A + A)
  “cdeab” (B)
```

B is found in (A + A), so B is a rotated string of A.

## Reference

- https://leetcode.com/problems/rotate-string/discuss/118696/C%2B%2B-Java-Python-1-Line-Solution