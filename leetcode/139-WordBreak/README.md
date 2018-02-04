## Solution explanation

### Solution 1: DP [Accepted]

The first approach is based on the brute-force approach via backtracking. The time saving happens 
at `dp[start] != -1`, where we know the result of substring start with `start` (i.e., whether 
can be segmented into a space-separated sequence of one or more dictionary words). Then, we can
return the result immediately without further calculation. 

Implementation-wise, be careful with the index of `for end in range(start+1, len(s) + 1)`, where
start with `start` and end with `len(s)+1`, which are due to the substring `s[start:end]` (i.e.
excluding the char at `end`).

- Time complexity: $O(n^2)$
- Space complexity: $O(n)$

The solution is implemented in `wordBreak`.
Code structure is very similar to "131 - Palindrome Partitioning".

### Solution 2: BFS [Accepted]

We start with the index `0` of the string. Each node is the index of the string. 
Edge connecting from the node in the previous layer and the current layer represent a word
contained in the dictionary. For example, given a string `'CatsandDog'`
and a dictionary `['Cat', 'Cats', 'Sand', 'And', 'Dog']`, we start with `'C'` (i.e. index 0)
and all the subtrings starting with `'C'` and are in the dictionary are `'Cats'` and `'Cat'`.
Thus, we have the following graph:

```
    0 (C)
   / \
 3(s) 4(A)
       \
        7(D)
         \
          10 (end of string)
```

Note that the string formed from the above graph is `s[0:3]`, which is `'Cat'` and `s[0:4]`, which
is `'Cats'` (i.e. `4` is not included for substring). Thus, our task becomes finding a path from
beginning index `0` to the end of string (i.e. `10` in this example). To find all possible substring
starting with certain index appeared in the dictionary naturally leads to BFS.

- Time complexity : $O(n^2)$ For every starting index, 
the search can continue till the end of the given string.
- Space complexity : $O(n)$. Queue of atmost $n$ size is needed.

The solution is implemented in `wordBreak1`.

### Solution 3: DP [Accepted]

The intuition behind this approach is that the given problem ($s$) 
can be divided into subproblems $s1$ and $s2$. 
If these subproblems individually satisfy the required conditions, the complete problem, 
$s$ also satisfies the same. e.g. "catsanddog" can be split into two substrings "catsand", "dog". 
The subproblem "catsand" can be further divided into "cats","and", which individually are a part of 
the dictionary making "catsand" satisfy the condition. 
Going further backwards, "catsand", "dog" also satisfy the required criteria individually 
leading to the complete string "catsanddog" also to satisfy the criteria.

Now, we'll move onto the process of $\text{dp}$ array formation. 
We make use of $\text{dp}$ array of size $n+1$, where $n$ is the length of the given string. 
We also use two index pointers $i$ and $j$, where $i$ refers to the length of the substring ($s'$) 
considered currently starting from the beginning, and $j$ refers to the index partitioning the current substring 
($s'$) into smaller substrings $s'(0,j)$ and $s'(j+1,i)$. 
To fill in the $\text{dp}$ array, we initialize the element $\text{dp}[0]$ as $\text{true}$, 
since the null string is always present in the dictionary, and the rest of the elements of $\text{dp}$ as 
$\text{false}$. We consider substrings of all possible lengths starting from the
beginning by making use of index $i$. For every such substring, we partition the string into two further substrings $s1'$
​and $s2'$ in all possible ways using the index $j$ (Note that the $i$ now refers to the ending index of $s2'$).
Now, to fill in the entry $\text{dp}[i]$, we check if the $\text{dp}[j]$ contains $\text{true}$, i.e. if the substring $s1'$
​fulfills the required criteria. If so, we further check if $s2'$ is present in the dictionary. 
If both the strings fulfill the criteria, we make $\text{dp}[i]$ as $\text{true}$, 
otherwise as $\text{false}$.

- Time complexity : $O(n^2)$ Two loops are their to fill \text{dp}dp array.
- Space complexity : $O(n)$. Length of pp array is $n+1$.

The solution is implemented in `wordBreak2`.

## Reference

- https://leetcode.com/problems/word-break/solution/
- https://leetcode.com/problems/word-break/discuss/43797/A-solution-using-BFS