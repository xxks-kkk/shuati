## Solution Explanation

This question is a very good DP problem. Be careful to study. 

### Naming

We call a position in the array a "good index" if starting at that position, we can reach the last index. 
Otherwise, that index is called a "bad index". 
The problem then reduces to whether or not index `0` is a "good index".

### Solution

This is a dynamic programming question. Usually, solving and fully understanding a dynamic programming problem is a 4 step process:

- Start with the recursive backtracking solution
- Optimize by using a memoization table (top-down dynamic programming)
- Remove the need for recursion (bottom-up dynamic programming)
- Apply final tricks to reduce the time / memory complexity

All solutions presented below produce the correct result, but they differ in run time and memory requirements.

#### Approach #1 (Backtracking) [Stack Overflow]

This is the inefficient solution where we try every single jump pattern that takes us from the first position to the last. 
We start from the first position and jump to every index that is reachable. 
We repeat the process until last index is reached. When stuck, backtrack.

```python
def canJump(self, nums):
    def canJumpFromPosition(pos, nums):
        if pos == len(nums) - 1:
            return True
        furthestJump = min(pos + nums[pos], len(nums)-1)
        for nextPos in range(pos+1, furthestJump + 1, 1):
            if canJumpFromPosition(nextPos, nums):
                return True
        return False
    return canJumpFromPosition(0, nums)
```

One quick optimization we can do for the code above is to check the `nextPos` from right to left. 
The theoretical worst case performance is the same, but in practice, for silly examples, the code might run faster. 
Intuitively, this means we always try to make the biggest jump such that we reach the end as soon as possible.
The code change is

```python
# Old
for nextPos in range(pos+1, furthestJump + 1, 1):
# New
for nextPos in range(furthestJump, pos, -1):
```

For instance, in the example below, 
if we start from index `0`, jump as far as possible and reach `1`, 
jump as far as possible and reach `6`. By doing so, we determine that `0` is a GOOD index in 3 steps.

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|-------|---|---|---|---|---|---|---|
| nums  | 1 | 5 | 2 | 1 | 0 | 2 | 0 |

To illustrate the worst case, where this optimization has no effect, take the example below. 
Index `6` cannot be reached from any position, but all combinations will be tried.

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|-------|---|---|---|---|---|---|---|
| nums  | 5 | 4 | 3 | 2 | 1 | 0 | 0 |


**Complexity Analysis**

- Time complexity : $O(2^n)$ There are $2^n$ (upper bound) ways of jumping from the first position to the 
last, where $n$ is the length of array `nums`. 

- Space complexity : $O(n)$. Recursion requires additional memory for the stack frames.

There are $2^n$ (upper bound) ways of jumping from the first position to the last, where $n$ is the length of array nums. 
We get this recursively. Let $T(x)$ be the number of possible ways of jumping from position $x$ to position $n$. 
$T(n) = 1$ trivially. $T(x) = \sum_{i = x + 1}^{n} T(i)$ because from position $x$ we can potentially 
jump to all following positions $i$ and then from there there are $T(i)$ ways of continuing. Notice this is an upper bound.

- $T(x) = \sum_{i=x+1}^n T(i)$
- $T(x) = T(x+1) + \sum_{i=x+2}^n T(i)$
- $T(x) = T(x+1) + T(x+1)$
- $T(x) = 2\times T(x+1)$

Now by induction, assume $T(x) = 2^{n - x - 1}$ and prove $T(x - 1) = 2^{n - (x - 1) - 1}$
​​ 
- $T(x-1) = 2 \times T(x)$
- $T(x-1) = 2 \times 2^{n-x-1}$
- $T(x-1) = 2^{n-x-1+1}$
- $T(x-1) = 2^{n-(x-1)-1}$

Therefore, since we start from position 1, $T(1) = 2^{n - 2}$. Final complexity $O(2^{n - 2}) = O(2^n)$

#### Approach #2 (Dynamic Programming Top-down) [Stack Overflow]

Top-down Dynamic Programming can be thought of as optimized backtracking. 
It relies on the observation that once we determine that a certain index is good / bad, 
this result will never change. This means that we can store the result and not need to recompute it every time.

Therefore, for each position in the array, we remember whether the index is good or bad. 
Let's call this array `memo` and let its values be either one of: GOOD, BAD, UNKNOWN. 
This technique is called "memoization".

An example of a memoization table for input array 
`nums = [2, 4, 2, 1, 0, 2, 0]` can be seen in the diagram below. 
We write G for a GOOD position and B for a BAD one. 
We can see that we cannot start from indices `2`, `3` or `4` and eventually reach last index (`6`), 
but we can do that from indices `0`, `1`, `5` and (trivially) `6`.

| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|-------|---|---|---|---|---|---|---|
| nums  | 2 | 4 | 2 | 1 | 0 | 2 | 0 |
| memo  | G | G | B | B | B | G | G |

**Steps**

- Initially, all elements of the `memo` table are UNKNOWN, except for the last one, which is (trivially) GOOD (it can reach itself)
- Modify the backtracking algorithm such that the recursive step first checks if the index is known (GOOD / BAD)
    - If it is known then return True / False
    - Otherwise perform the backtracking steps as before
- Once we determine the value of the current index, we store it in the `memo` table.

```python
def canJump(self, nums):
    # 1: Good, 0: Unknown, -1: bad
    def canJumpFromPosition(pos, nums):
        if memo[pos] != 0:
            return True if memo[pos] == 1 else False
        furthestJump = min(pos + nums[pos], len(nums)-1)
        for nextPos in range(pos+1, furthestJump+1, 1):
            if canJumpFromPosition(nextPos, nums):
                memo[pos] = 1
                return True
        memo[pos] = -1
        return False
    memo = [0] * len(nums)
    memo[len(nums) - 1] = 1
    return canJumpFromPosition(0, nums)
```

- Time complexity : $O(n^2)$. For every element in the array, say `i`, we are looking at the next 
`nums[i]` elements to its right aiming to find a GOOD index. `nums[i]` can be at most `n`, 
where `n` is the length of array `nums`.

- Space complexity : $O(2n) = O(n)$. First `n` originates from recursion. 
Second `n` comes from the usage of the `memo` table.

#### Approach #3 (Dynamic Programming Bottom-up) [Time limit exceeded]  

Top-down to bottom-up conversion is done by eliminating recursion. In practice, this achieves better performance as 
we no longer have the method stack overhead and might even benefit from some caching. More importantly, this step opens up possibilities for future optimization. 
The recursion is usually eliminated by trying to reverse the order of the steps from the top-down approach.

The observation to make here is that we only ever jump to the right. This means that if we start from the right of the array, 
every time we will query a position to our right, that position has already be determined as being GOOD or BAD. 
This means we don't need to recurse anymore, as we will always hit the `memo` table.

```python
def canJump(self, nums):
    memo = [0] * len(nums)
    memo[len(nums) - 1] = 1
    for i in range(len(nums)-2, -1, -1):
        furthestJump = min(i + nums[i], len(nums)-1)
        for j in range(i+1, furthestJump+1, 1):
            if memo[j] == 1:
                memo[i] = 1
                break
    return memo[0] == 1
```

- Time complexity : $O(n^2)$. For every element in the array, say `i`, we are looking at the next `nums[i]` elements 
to its right aiming to find a GOOD index. `nums[i]` can be at most `n`, where `n` is the length of array nums.

- Space complexity : $O(n)$. This comes from the usage of the `memo` table.

#### Approach #4 (Greedy) [Accepted]

Once we have our code in the bottom-up state, we can make one final, important observation. 
From a given position, when we try to see if we can jump to a GOOD position, 
we only ever use one - the first one (see the `break` statement). In other words, the left-most one. 
If we keep track of this left-most GOOD position as a separate variable, we can avoid searching for it in the array. 
Not only that, but we can stop using the array altogether.

Iterating right-to-left, for each position we check if there is a potential jump that reaches a GOOD index (
`currPosition + nums[currPosition] >= leftmostGoodIndex`). If we can reach a GOOD index, then our position is itself GOOD. 
Also, this new GOOD position will be the new leftmost GOOD index. 
Iteration continues until the beginning of the array. 
If first position is a GOOD index then we can reach the last index from the first position.

To illustrate this scenario, we will use the diagram below, 
for input array `nums = [9, 4, 2, 1, 0, 2, 0]`. We write G for GOOD, B for BAD and U for UNKNOWN. 
Let's assume we have iterated all the way to position `0` and we need to decide if index `0` is GOOD. 
Since index `1` was determined to be GOOD, it is enough to jump there and then be sure we can eventually reach index `6`. 
It does not matter that `nums[0]` is big enough to jump all the way to the last index. All we need is one way.


| Index | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|-------|---|---|---|---|---|---|---|
| nums  | 9 | 4 | 2 | 1 | 0 | 2 | 0 |
| memo  | U | G | B | B | B | G | G |

- Time complexity : $O(n)$. We are doing a single pass through the `nums` array, hence `n` steps, 
where `n` is the length of array `nums`.

- Space complexity : $O(1)$. We are not using any extra memory.

## Reference

- https://leetcode.com/problems/jump-game/solution/
- https://en.wikipedia.org/wiki/Top-down_and_bottom-up_design
- https://en.wikipedia.org/wiki/Memoization
- https://en.wikipedia.org/wiki/Dynamic_programming

## Remarks

The question left unanswered is how should one approach such a question in an interview scenario. 
I would say "it depends". The perfect solution is cleaner and shorter than all the other versions, 
but it might not be so straightforward to figure out.

The (recursive) backtracking is the easiest to figure out, so it is worth mentioning it verbally while warming 
up for the tougher challenge. It might be that your interviewer actually wants to see that solution, 
but if not, mention that there might be a dynamic programming solution and try to think how could you use a memoization table. 
If you figure it out and the interviewer wants you to go for the top-down approach, 
it will not generally be time to think of the bottom-up version, 
but I would always mention the advantages of this technique as a final thought in the interview.

Most people are stuck when converting from top-down Dynamic Programming (expressed naturally in recursion) to bottom-up. 
Practicing similar problems will help bridge this gap.