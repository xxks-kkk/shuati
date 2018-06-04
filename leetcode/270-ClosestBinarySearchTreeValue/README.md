## Solution explanation

### Method 1: Naive approach

The first method is a naive recursive solution. It traverse all the nodes and find the candidate value. The solution
doesn't leverage the BST assumption. Consider the question example, the difference between 4 and 3.7 is 0.3. We also
find the difference between 2 and 3.7 is 1.7, which is greater than 0.3, and we don't need to keep going left and visit 1
because BST definition guarantees that the gap between 1 and 3.7 will be even larger than the gap at 2.

### Method 2: Use BST assumption

Method 2 leverage the BST assumption. The advantage of Method 2 over Method 1 follows:

- No use stack to save space
- We don't visit all the nodes to save time
- We don't use `std::numeric_limits<double>::max()`, which may lead to code break if the gap between target and node's value
goes beyond this value

The key lines of code:

- `current = current->val > target ? current->left : current->right`, which is how we leverage BST assumption. If
`current->val > target`, then we certainly don't want to visit `current->right` to make the gap even larger. Thus, we visit
`current->left`. Similar situation when `current->val < target`.

## Reference

- https://leetcode.com/problems/closest-binary-search-tree-value/discuss/70331/Clean-and-concise-java-solution