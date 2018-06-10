## Solution explanation

### Method 1: Naive approach

The naive approach is that we traverse all the nodes in the tree and calculate the absolute value difference between
the node's value and target value. Then, we keep k smallest of them as the final result.

One thought is to keep the difference of each node and sort them and take smallest k of them as the final result. This
will lead to $O(n \log n)$. A better way to do is to maintain a max heap and keep only k smallest value difference
(`if(pq.size() > k)` ..., which pop out the largest value and keeps the smaller values in the heap). Since the insertion
of the k-size heap takes $O(\log k)$ and we visit all nodes, the time complexity will be $O(n \log k)$.

- Time complexity: $O(n \log k)$

### Method 2: Use BST assumption

As you can see from Method 1, we use a heap to help us get the k smallest values. Can we do better? Yes. Since we are given
BST, we know that the preorder traversal of the tree will give sorted predecessors (i.e., the nodes values in ascending order).
Let's use given question example as an example. The preorder traversal gives `1,2,3,4,5`. The idea is to split this
list into two parts around given target value 3.714286 and we perform merge sort on the resulting two splited list to form
our solution. In specific, if we split `1,2,3,4,5` around 3.714286, we get `1,2,3` and `4,5`. Then, we form our final result
by comparing the value difference of each head of the list. In this case, we want to compare `3` and `4` with target value
as they are closest to the target value and build the final result until its size is k.

In other words, we can compare the predecessors and successors of the closest node to the target and
we use two stacks to track the predecessors and successors, then like what we do in merge sort,
we compare and pick the closest one to the target and put it to the result list. As we know,
inorder traversal gives us sorted predecessors, whereas reverse-inorder traversal gives us sorted successors. Since
we split `1,2,3,4,5` into `1,2,3` and `4,5`. Sorted predecessors give `1,2,3,4,5` and sorted successors give
`5,4,3,2,1`. Thus, we only need part of sorted predecessors and part of sorted successors to form the final result.
This suggests that we can terminate early when we traverse the tree.

- Time complexity: $O(n)$ (we traverse nodes using $O(n)$ and merge the result using $O(k)$)

**NOTE:**

The source code contains other nice $O(n)$ approaches. Those are much cleaner than the above one. Please check them out.

### Method 3: $O(k \log n)$ approach

We can construct the predecessor and successor stack in a better way. The idea is to first construct the predecessor
and successor stack using part of tree (`while(current != nullptr)` ... ) and then we update the predecessor & sucessor
stack as we need using the rest part of the tree (`getPredecessor` and `getSuccessor`).

## Reference

- https://leetcode.com/problems/closest-binary-search-tree-value-ii/discuss/70488/Simple-C++-solution-with-priority-queue
- https://leetcode.com/problems/closest-binary-search-tree-value-ii/discuss/70511/AC-clean-Java-solution-using-two-stacks