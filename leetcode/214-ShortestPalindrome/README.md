## Solution explanation

### Method 2: Two pointers + recursion

The basic idea is that Take the string 
`"abcbabcab"`. Here, the largest palindrome segment 
from beginning is `"abcba"`, and the remaining segment is 
`"bcab"`. Hence the required string is reverse of `"bcab"`( = `"bacb"`) + 
original string(=`"abcbabcab"`) = `"bacbabcbabcab"`.

The idea is to find the largest palindrome that is start from the beginning
and we use two pointers `i` and `j`. Our invariant is the largest palindrome
that starts from the beginning is in the interval `[0, i)`. 

 Let us consider 2 pointers `i` and `j`. 
 Initialize `i = 0`. Iterate over `j` from `n-1` to `0`, 
 incrementing `i` each time `s[i]==s[j]`. 
 Now, we just need to search in range `[0,i)`. 
 This way, we have reduced the size of string to search for the 
 largest palindrome substring from the beginning. The range `[0,i)` 
 must always contain the largest palindrome substring. 
 The invariant will always hold because: Say the string was a perfect palindrome, `i` 
 would be incremented `n` times. Had there been other characters at the end, 
 `i` would still be incremented by the size of the palindrome. 
 Hence, even though there is a chance that the range `[0,i)` is not 
 always tight, it is ensured that it will always contain the 
 longest palindrome from the beginning.



## Reference

- https://leetcode.com/problems/shortest-palindrome/solution/