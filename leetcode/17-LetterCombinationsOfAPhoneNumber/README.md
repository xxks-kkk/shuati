## Solution explanation

Running time is $O(c^n)$, where c is the max number of characters corresponding
to the digits. In this case, c is 4. 

To cacluate the running time, the formula we get is 
$c + c^2 + c^3 + ... + c^n$. For example, the running time for `'23'` is 
$3 + 3^2$. The formula is a geometric series and we have $O(c^n)$ as the result. 