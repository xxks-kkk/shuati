## Solution explanation

The solution using typical backtracking approach. The idea of the solution 
is very similar to "39-Combination Sum". Be careful with the problem description
that "root-to-leaf paths". When we get a path that sums to the target sum, we need
to check whether it is a "root-to-leaf" path. Test case "[1,2], 1" specifically tests
out this situation.