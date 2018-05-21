## Solution Explanation

The intuition for solving this problem is that BST gives a sorted increasing sequence of values for in-order traversal.
For example, for example 1, in-order traversal gives `3,2,1` for the swapped BST and we can see that two nodes that
are swapped are `3` and `1`. Thus, the idea of the solution is to visit the tree with in-order traversal and
search for two swapped nodes and then swap them back. However, how do we identify those two nodes in program is the tricky part.

### Solution 1: Three pointers

The problem states that there are two nodes swapped and that indicates that one node that is supposed to have small
value now gets a big value (let's called it node A) and a node that is supposed to have a big value now has a small value
(let's called it node B). This further implies that node A appears before node B. Thus, our job is to identify node A and node B.

To identify node A, we know that it is the first swapped node and it has a bigger value than the node comes after it in the
in-order traversal. For example, for example 2 given by question, in-order traversal gives `1,3,2,4` for swapped BST
and node A is `3`, which is bigger than `2` the node immediately after node A. We use `TreeNode *first;` to indicate
whether we have seen a swapped node before and we use `TreeNode *pre;` pointing to the node we have visited immediately before.
Thus, for node A, once we see the current node we are visiting (pointed by `root`) has smaller value than the previous
node (pointed by `pre`) and we haven't seen any swapped nodes before, we know that we find node A, which is pointed by
`pre`.

To identify node B, we know that it has a smaller value than the node comes immediately before and we have already identified
one swapped node previously (`first != nullptr`). Thus, we can use the same logic as identifying node A to identify node B.

Once we identified node A and node B, we can swap their value and solve the problem.

- Time complexity: $O(n)$
- Space complexity: $O(h)$

### Solution 2: Morris Traversal

We use Morris Traversal to reduce the space complexity to constant.

Morris traversal is based on the threaded tree:

    if a node has a `nullptr` left child, we make its left child link to its inorder predecessor, and
    if a node has a `nullptr` right child, we make its right child link to its inorder successor.
    The extra links are called threads.

Then we perform the traversal on the threaded tree is called Morris traversal.

Implementation-wise, before we visiting the left subtree of a root, we will build a link between rightmost node in
left subtree and the root. So we can go back to the root node after we are done with the left subtree.
Then we locate the rightmost node in left subtree again, cut the link, recover the tree structure and
start visit right subtree. The detection of two incorrect TreeNodes is similar to iterative/recursive in-order traversal.


- Time complexity: $O(n)$
- Space complexity: $O(1)$ (there is no stack)

## Remarks

- When solving this problem, I can think of using the in-order traversal to identify which two nodes are swapped but
I cannot think of how we can hold two pointers pointing to those two nodes and performing the swap.

- For solution 1, we want to set `pre`, `first`, `second` to `nullptr` every time we call `recoverTree` (we don't want
to intialize them in the class because otherwise those variable may hold non-nullptr address from the previous call
to `recoverTree`.

## Reference

- https://leetcode.com/problems/recover-binary-search-tree/discuss/32562/Share-my-solutions-and-detailed-explanation-with-recursiveiterative-in-order-traversal-and-Morris-traversal
- https://leetcode.com/problems/recover-binary-search-tree/discuss/32535/No-Fancy-Algorithm-just-Simple-and-Powerful-In-Order-Traversal
- https://en.wikipedia.org/wiki/Threaded_binary_tree