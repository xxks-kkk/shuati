## Solution explanation

The problem is based on the pattern observation. There are many corner cases we need to consider.

1. When the length of two strings differed by more than two chars, we know that there is no way that
two strings can be one edit distance away.

2. When two strings have the same length, the only possible scenario is the following, which is only
one char is different and the position of those two chars are the same in the respective strings:

```
s: a b c
t: a d c
```

3. When two strings' lengths differ by one, there are two possible situations:

```
s: a b d c   |  a   b c
t: a b   c   |  a d b c
```

The implementation follows those cases closely. There is one implementation subtlety needs to point out:

For the third case, we want to index the string with longer length because for the case, there essentially
one extra char in the longer length string that we need to find out. That's why we have
`num = len(s) if len(s) > len(t) else len(t)`. In addition, we have `num-1` in `for i in range(num-1)`
because there might be the case that the extra char appears in the very end of the string, which 
can lead to index out of bound for the shorter string. 

```
s: a b c
t: a b c d
```

Thus, we need to check only until the second last char. If by that time we still haven't found the extra
char, that means the extra appears at the end of the longer string and thus, we can return `True`.

The above idea can be implemented more compactly in `isOneEditDistance1`, which borrows from the reference
link.

## Reference

- https://leetcode.com/problems/one-edit-distance/discuss/50098/My-CLEAR-JAVA-solution-with-explanation