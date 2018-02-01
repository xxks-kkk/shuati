## Solution explanation

The problem might be not very clear: the goal of the problem is to find the index of station
that allows the car to travel around the circular aligned $N$ stations once. If no such `start_idx`
exists, we should return `-1`.

### Algorithm

我们首先要知道能走完整个环的前提是`gas`的总量要大于`cost`的总量，这样才会有起点的存在。
假设开始设置起点`start_idx = 0`, 并从这里出发，如果当前的`gas`值大于`cost`值，就可以继续前进，
此时到下一个站点，剩余的`gas`加上当前的`gas`再减去`cost`，看是否大于`0`，若大于`0`，则继续前进。
当到达某一站点时，若这个值小于`0`了，则说明从起点到这个点中间的任何一个点都不能作为起点，则把起点设为下一个点，继续遍历。
当遍历完整个环时，当前保存的起点即为所求。

### Proof

There are two statements in this algorithm we need to prove:

1) If the total gas of all the stations is greater than or equal to the total cost, there is a 
`start_idx` that allows the car to traveral around the circular once.

There are two ways we can show this:

- We can proof by contradiction. Assume the total gas of all station is greater than or equal to the
total cost, there is no `start_idx` exists such that the car can traveral around the circular once.
The car cannot traveral around because the gas that car has at station $i$ is less than the $\text{cost}[i]$.
Without loss any generality, let's assume $i = N-1$. Here, we are at the last station and we have
all the gas. However, since we cannot finish the circular, then $\text{cost}[n-1]$ has to be greater than
the total gas we have at $N-1$. This implies that the total gas of all the stations is less than the total
cost, which is a contradiction.

- Let's prove by induction. we want to show if $\sum_{i=0}^{N-1} \text{gas}[i] \ge \sum_{i=0}^{N-1} \text{cost}[i]$,
then there is a path that goes through all stations. Base case: $N=1$, which is trivially true. Now,
suppose the induction hypothesis holds for $N=k$ and we want to show that the hypothesis also holds for $N=k+1$.
The difference between $N=k+1$ and $N = k$ is that we add $\text{gas}[k+1]$ and $\text{cost}[k+1]$. We want
to show that there is a path given $\sum_{i=0}^{(k+1)-1} \text{gas}[i] \ge \sum_{i=0}^{(k+1)-1} \text{cost}[i]$.
This holds because we have a path for $N=k$ and since the $\text{gas}[k+1] \ge \text{cost}[k+1]$,
the car can also goes from $k+1$ station to the first, which means there is a path.


2) Whenever the `total_gas` smaller than `0`, any station bewtween the `start_idx` and the current station
that makes `total_gas` become negative (inclusive) cannot be the `start_idx`.

To get an idea of why this is true, let's see an example.
Let `res[i] = gas[i] - cost[i]`. During the algorithm, we have 
`res[k] + res[k + 1] + res[k + 2]  + res[k + 3] + res[k + 4] < 0`, which means that when `start_idx = k`,
the first time that `res` smaller than `0` is when we at `k+4`. This implies that:

- `res[k] >= 0`
- `res[k] + res[k + 1]  >= 0`
- `res[k] + res[k + 1] + res[k + 2]  >= 0`
- `res[k] + res[k + 1] + res[k + 2]  + res[k + 3] >= 0`
- `res[k] + res[k + 1] + res[k + 2]  + res[k + 3] + res[k + 4] < 0` and `res[k + 4] < 0`

`k` cannnot be the start index, then why `k+1`, `k+2`, `k+3`, `k+4` be the start index? This is because
for any $k < m \le k+4$, `res[m] + ... + res[k + 4] <= res[k] + ... + res[k + 4]`, which means that
`res[m] + ... + res[k + 4] < 0` for $k < m \le k+4$. Thus, we can skip `k+1`, `k+2`, `k+3`, `k+4`
and start with `k+5`.

### Remarks

This problem looks a lot like the "Maximum subsequence sum" problem and the solution resembles the
algorithm 4 appeared in MAW p.29.

## Reference

- http://www.cnblogs.com/grandyang/p/4266812.html
- https://leetcode.com/problems/gas-station/discuss/42572