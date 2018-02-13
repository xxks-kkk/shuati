## Solution explanation

### Solution 1: Sorting via Custom Comparator [Accepted]

To construct the largest number, we want to ensure that the most significant digits are occupied by the largest digits.
First, we convert each integer to a string. Then, we sort the array of strings.

While it might be tempting to simply sort the numbers in descending order, this causes problems for sets of numbers 
with the same leading digit. For example, sorting the problem example in descending order would produce the number 
$9534303$, while the correct answer can be achieved by transposing the $3$ and the $30$. 
Therefore, for each pairwise comparison during the sort, we compare the numbers achieved by 
concatenating the pair in both orders. 

We can prove that this sorts into the proper order as follows:

Assume that (without loss of generality), for some pair of integers $a$ and $b$, 
our comparator dictates that $a$ should precede $b$ in sorted order. This means that 
$a\frown b > b\frown a$ (where $\frown$ represents concatenation). 
For the sort to produce an incorrect ordering, there must be some $c$ for which 
$b$ precedes $c$ and $c$ precedes $a$. This is a contradiction 
because $a\frown b > b\frown a$ and $b\frown c > c\frown b$ implies 
$a\frown c > c\frown a$
(because if we add these two conditions, we have $a\frown b \frown c > c\frown b \frown a$ and the result follows). 
In other words, our custom comparator preserves transitivity, so the sort is correct.

## Reference

- https://leetcode.com/problems/largest-number/solution/