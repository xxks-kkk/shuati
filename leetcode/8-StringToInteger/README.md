## Solution Explanation

First we need to figure out the requirement for `myAtoi` function:

- The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

- The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

- If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

- If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Once we figure out the requirement, the key part is to understand the following
the regular expression:

```
'^[\+\-]?\d+'
```

- `^` matches the starting position within the string
- `[]` matches a single character that is contained within the brackets. For example,
`[abc]` matches "a", "b", or "c".
- `\+` means the plus symbol
- `\-` means the minus symbol
- `?` matches the preceding element zero or one time. For example, 
`ab?c` matches only "ac" or "abc".
- `\d` means decimal digits
- `+` matches the preceding element one or more times. For example, 
`ab+c` matches "abc", "abbc", "abbbc", and so on, but not "ac".


## Reference

- https://discuss.leetcode.com/topic/10740/python-solution-based-on-regex/7