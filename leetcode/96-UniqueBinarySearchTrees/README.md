## Solution explanation

### Recursion approach [Time Limit Exceeded]

The idea of the solution is that for a list of numbers $1 \dots n$, we can pick a
number $i \in [1,n]$ as the root. Then, we pick a number $j \in [1,i-1]$ as the
root of the left subtree and $k \in [i+1, n]$ as the root of the right subtree. Then,
we form our BST by connecting both left and right subtrees with the root. There are
$n$ possible roots of BST and thus, we have `for i in range(1,n+1)`. Once we fix our
root (i.e. $i$), there are $i-1$ candidates to be the root of the left subtree and
$n-i$ possible candidates to be the root of the right subtree. Thus, we 
have `num_left_subtrees = self.numTrees2(i-1)` and `num_right_subtrees = self.numTrees2(n-i)`.
Another way to understand these two lines of code is from the question description: we want
to find how many structurally unique BST's that store values $1 \dots i-1$ and
how many structurally unique BST's that store values $i+1 \dots n$. 
  
Once we find the number of structurally unique BST's that store values $1 \dots i-1$, we 
have the number of structurally unique left subtree. Similarly, the number of 
structurally unique BST's that store values $i+1 \dots n$ is the same as the number
of structurally unique right subtree. Thus, the total number of structurally unique BST equals
to the number of possible left subtrees times the number of possible right subtrees. 
Remember, we find the total number of structurally unqiue BST given the root $i$ and we
need to do this for all possible root values.

### DP approach [Accept]

The problems with recursion approach utilizing stack are always: 1) the stack space used by the algorithm 2)
a fair amount of repeated calculation. Thus, in order to fix those two problems, we use
the DP approach. We declare $DP[i] = \text{the number of unique BST that store values} 1 \dots i$.
Then our goal is to find $DP[n]$. Note that $i$ here is defined differently than $i$ in recursion approach:
$i$ here is denoted as the length of a sequence of values while $i$ is denoted as the value of root node
(or position of root node in a sequence of values) previously. 

For each given length $i$, we can calculate the number of structurally unique BST's using the recursion
idea by mutliply the number of structurally unqiue left subtree with the number of structurally unique
right subtree given a root node value $j \in [1,i]$. The number of structurally unique left subtree is
the same as finding the number of structurally unique BST's that store values $1 \dot j-1$, which
is $DP[j-1]$. Similarly, the number of structurally unique right subtree is $DP[i-j]$. Again,
the product of $DP[j-1]$ and $DP[i-j]$ is the number of structurally unique BST's for the root value $j$
and we need to consider all possible root value $j$ in order to get $DP[i]$. Then we can return $DP[n]$
as our final answer.

## Remark

The problem actually calculate the [Catalan Number](https://en.wikipedia.org/wiki/Catalan_number) and 
there are [several problems](https://www.geeksforgeeks.org/program-nth-catalan-number/) with Catalan number as their solution background.

## Reference

- https://leetcode.com/problems/unique-binary-search-trees/discuss/31666
- http://www.cnblogs.com/grandyang/p/4299608.html
- https://www.youtube.com/watch?v=UfA_v0VmiDg