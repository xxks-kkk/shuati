## Solution explanation

### Approach 1: "Permutation" method [Time Limit Exceeded]

One idea is to use the same method as the "permutation" by generating all the permutations and 
return the `k`th one. The code looks below:

```python
def getPermutation(self, n, k):
    def dfs(nums, visited, path, res):
        if len(path) == n:
            res.append(path)
            return
        for i,num in enumerate(nums):
            if visited[i] == 0:
                visited[i] = 1
                dfs(nums, visited, path + str(num), res)
                visited[i] = 0
    res = []
    nums = range(1, n+1)
    visited = [0] * n
    dfs(nums, visited, "", res)
    return res[k-1]
```

### Approach 2: Pattern discovery [Accepted]

We are asked to find the `k`th permutation. We don't need to find all permutations and return `k`th one (as
Approach 1 does). Instead, we can directly get the `k`th permutation. The key is to find the pattern of
the appearances of permutations. Let's use an example when `n = 4` and `k = 9`. $k=9$ is counted based on
1-index and in 0-index, $k=8$:

```
1234
1243
1324
1342
1423
1432

2134
2143
2314  <- k = 9 (1-index)
2341
2413
2431

3124
3142
3214
3241
3412
3421

4123
4132
4213
4231
4312
4321
```

The key observation is that: for permutations of $n$, the first $(n-1)!$ permutations start with 1, 
next $(n-1)!$ ones start with 2, ... and so on. 
In each group of $(n-1)!$ permutations, the first $(n-2)!$ permutations start with 
the smallest remaining number, ...

For this example, we'll count the digit place from left to right starting with 1:

- The 1st digit can be selected from ${1,2,3,4}$, with each number appears $(n-1)! = (4-1)! = 6$ times.
Thus, for $k=8$th permutation, the 1st digit is from $k/(n-1)! = 8/6 = 1$ position of ${1,2,3,4}$, which
is $2$. Note that by observing examples, all the permutations are listed in ascending order (i.e., 
`4123` and `4132`: `3` in `4132` comes after `2` in `4123`) and thus we use ${1,2,3,4}$ instead of ${4,3,2,1}$.

- Now, for all $6$ permutations with 1st digit being $2$, $k=8$th permutation is the $k' = k%(n-1)! = 8%6 = 2$rd
one. For the 2nd digit, we can select from ${1,3,4}$ and by key observation, each number appears
$(n-2)! = (4-2)! = 2$ times. Thus, the 2nd digit is from $k'/(n-2)! = 2/2 = 1$, which is $3$.

```
2134
2143
2314  <- k = 9
2341
2413
2431
```

- Now, there are only 2 permutations starting with $23$, $k=8$th permutation is the $k'' = k'%(n-2)! = 2%2 = 0$st
one. For the 3rd digit, we can select from ${1,4}$ and by key observation, each number appears 
$(n-3)! = (4-3)! = 1$ times. Thus, the 3rd digit is from $k''/(n-3)! = 0/1 = 0$, which is $1$.

```
2314  <- k = 9
2341
```

- The last digit is $k''' = k''%(n-4)! = 0%0! = 0$. For the last digit, we can select from ${4}$ and by
key observation, each number appears $(n-4)! = (4-4)! = 1$ times. Thus, the last digit is from
$k'''/(n-4)! = 0/1 = 0$, which is $4$.

Thus, the example can be summarized as:

```
9 - 1 = 8
8 / 3! = 1 ... 2 ( {1,2,3,4}[1] = 2 )
2 / 2! = 1 ... 0 ( {1,3,4}[1] = 3 )
0 / 1! = 0 ... 0 ( {1,4}[0] = 1 )
0 / 0! = 0 ... 9 ( {4}[0] = 4 )
```

Thus, our pattern can be formulated as:

```
k = k - 1
k  / (n-1)! = index .... k'  (nums[index] = 1st digit)
k' / (n-2)! = index .... k'' (nums[index] = 2nd digit)
....
```

The implementation is the direct translation of the pattern we observe above. `factorial` is a 
list of factorial starting with $(n-1)!$ and ending with $0!$.

## Reference

- https://leetcode.com/problems/permutation-sequence/discuss/22512
- http://www.cnblogs.com/grandyang/p/4358678.html
- http://bangbingsyb.blogspot.com/2014/11/leetcode-permutation-sequence.html