## Solution explanation

The idea is to remove `'('` and `')'` based on the sign right before `'('` (i.e., 拆括号). 

- Example: `7 - ( 6 - 5 - ( 4 - 3 ) - 2 ) - ( 1 )`
- Result: `+ 7 - 6 + 5 + 4 - 3 + 2 - 1`

In the result, `+`, `-` are the signs just before `'('` (i.e., `last_sign` in the code).
Whenever we see `+` or `-` in the string, that means we can perform `+` or `-` based on
the current sign and the sign right before `'('` (recorded by `last_sign`) (比如说负负得正). 
We need to push `last_sign` onto the stack whenever we see `'('` because we may need to handle the situation
`+9` for `1-(4+(5-6)+9)` (i.e., `+9` depends on the sign right before outer parentheses not the sign 
right before inner parentheses; we need to use a stack to keep track of signs before each pair of 
parentheses).

## Reference

- https://leetcode.com/problems/basic-calculator/discuss/62449/Simple-c++-in-24-ms/64084
