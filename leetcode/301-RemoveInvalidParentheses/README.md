## Solution explanation

The idea is straightforward, with the input string `s`, we generate all possible states by removing one `(` or `)`,
check if they are valid, if found valid ones on the current level, put them to the final result list and we are done,
otherwise, add them to a queue and carry on to the next level.

The good thing of using BFS is that we can guarantee the number of parentheses that need to be removed is minimal,
also no recursion call is needed in BFS.

Time complexity:

In BFS we handle the states level by level, in the worst case, we need to handle all the levels,
we can analyze the time complexity level by level and add them up to get the final complexity.

On the first level, there's only one string which is the input string `s`,
let's say the length of it is $n$, to check whether it's valid, we need `O(n)` time.
On the second level, we remove one `(` or `)` from the first level, so there are $\binom{n}{n-1}$ new strings,
each of them has `n-1` characters, and for each string, we need to check whether it's valid or not,
thus the total time complexity on this level is $(n-1) \times \binom{n}{n-1}$. Come to the third level,
total time complexity is $(n-2) \times \binom{n}{n-2}$, so on and so forth...

$$
T(n) = n \times \binom{n}{n} + (n-1) \times \binom{n}{n-1} + \dots + 1 \times \binom{n}{1} = n \times 2^{n-1}
$$

## Reference

- https://leetcode.com/problems/remove-invalid-parentheses/discuss/75032/Share-my-Java-BFS-solution