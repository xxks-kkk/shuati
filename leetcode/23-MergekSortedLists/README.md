## Solution explanation

### Approach 1: priority queue

We construct the priority queue using the first element of each linked list and find the node with min value. We set
that node as the first node of our final result. We then push the next node of the min node to the queue. We repeat
the same process: pop the min node out of queue, append the node to the result, and push the next node of the poped node
to the queue.

- Time complexity: $O(N \log k)$ (insertion into the queue takes $O(\log k)$ and we do this for all N nodes)
- Space complexity: $O(N)$

### Approach 2: heap

The same idea as the approach 1 but use heap instead.

- Time: $O(k + (N-k)\log k)$ (Build the initial heap takes $O(k)$. Each insertion into heap takes $O(\log k)$ and there are
$N-k$ elements)
- Space: $O(N)$

### Approach 3: Divide-and-Conquer

The idea is from merge sort: we do pair-wise linked ist merge until we get the final result. The process shown below:

![Divide-and-Conquer image from offical solution](23_divide_and_conquer_new.png)

- Time: $O(N \log k)$ ( $O(\sum_{i=1}^{\log_2 k} N)$. We assume each linked list has $N$ elements, which overestimate
the number of elements in each list)
- Space: $O(N)$

## Remarks

Sample demo on how to create min-heap using priority queue and heap in C++. In addition, demonstrate custom comparator
in two ways: function object (used in priority queue) and comparison function (used in heap). Additional material:

- http://fusharblog.com/3-ways-to-define-comparison-functions-in-cpp/
- https://stackoverflow.com/questions/2786398/is-there-an-easy-way-to-make-a-min-heap-in-c

## Reference

- https://leetcode.com/problems/merge-k-sorted-lists/solution/
- https://leetcode.com/problems/merge-k-sorted-lists/discuss/10527/Difference-between-Priority-Queue-and-Heap-and-C++-implementation