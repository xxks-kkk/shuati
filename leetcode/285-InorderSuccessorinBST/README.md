## Solution explanation

We need to formally define the inorder successor:

- It is the immediately bigger node than current node. 

    - If a node has right subtree, it is the smallest node found in the right subtree. Example:
    for a BST `[5,3,None,2,4]` and the inorder successor of `3` is `4`.
    - If the right subtree is null, it is the last node whose left subtree you are under. Example:
    for a BST `[5,3,None,2,4]` and the inorder successor of `4` is `5`.
    
The the algorithm works like follow:

On equality of the value whose inorder successor we are after, we go to the right subtree. 
As all elements in the right subtree are larger than the current node. 
From that point onward the algorithm will be drawn towards finding the smallest value in right subtree. 
As we keep traversing down smaller nodes, we modify value of successor.

## Follow-up

We can use similar idea to find the inorder predcessor. 

Let's formally define the inorder predcessor:

- It is the immediately smaller node than current node.

    - If the left subtree exist, predecessor is the largest node found in left subtree.
    Example: for a BST `[5,3,None,2,4]` and the inorder predecessor of `3` is `2`.
    - f the left subtree does not exist, predecssor is the last node whose right subtree the node is under.
    Example: for a BST `[5,3,None,2,4]` and the inorder predecessor of `4` is `3`.

## Reference

- https://leetcode.com/problems/inorder-successor-in-bst/discuss/72656/JavaPython-solution-O(h)-time-and-O(1)-space-iterative
- https://leetcode.com/problems/inorder-successor-in-bst/discuss/72671/C%2B%2B-O(h)-solution-in-one-pass