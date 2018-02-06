## Solution explanation

链表的插入排序实现原理很简单，就是一个元素一个元素的从原链表中取出来，然后按顺序插入到新链表中. When dealing with
linked list problem, one important technique is to create a separate list. The solution to this problem
is simply to reconstruct a list node by node, while deleting nodes from the original list.

- Time complexity: $O(n^2)$
- Space complexity: $O(1)$

## Reference

- https://leetcode.com/problems/insertion-sort-list/discuss/46420/An-easy-and-clear-way-to-sort-(-O(1)-space-)