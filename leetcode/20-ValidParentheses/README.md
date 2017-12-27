## Solution Explanation

To validate the parentheses, we need to match each closing parenthesis with its opening counterpart. 
A Last-In-First-Out (LIFO) data structure such as stack is the perfect fit.

As we see an opening parenthesis, we push it onto the stack. On the other hand, when we encounter a closing parenthesis, 
we pop the last inserted opening parenthesis from the stack and check if the pair is a valid match.
It would be wise to avoid writing multiple if statements when matching parentheses, 
as your interviewer may think that you are writing sloppy code. You could use a map, which is more maintainable.

A couple of implementation notice:

-  Use `len(stack) == 0 or dictionary[stack.pop()] != c` instead of 
`len(stack) != 0 and dictionary[stack.pop()] != c` for the case `']'`

-  Use `retrun len(stack) == 0` instead of `return True` for the case 
`'['`