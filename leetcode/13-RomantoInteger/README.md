## Solution explanation

Let's work through one example to see the pattern:

```
MCMXCVI = 1996
```

We can break the roman numeral like 

```
M    CM  XC VI
1000 900 90  6
```

The key to conversion is that we run through the roman numerals and we compare the current
roman numeral with the next one. If the current one is larger, we are safe to add the corresponding
integer of current numeral to the final result. If not, we need to subtract the current one from 
the next one and add the subtraction result to the final result.

## Reference

- https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/