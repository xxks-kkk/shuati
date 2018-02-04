## Solution explanation

Usually, to the linked list problem, we create a dummy node that links to the head node such that if there
is any change to the head node, we can still reference the new head of the linked list via `dummy.next`.

To this problem, if we are to reverse `2->3->4` in the given example (i.e., `1->2->3->4->5`)
to `4->3->2`, one way to do this is to find the node before the sublist to be reversed (i.e. `1`)
(`prev` in code) and and the node at the beginning of the sublist to be reversed (i.e. `2`) (`curr` in code)
and then we walk through the sublist and insert the following nodes after `prev`. We use `cur` because
the node at the beginning of the sublist to be reversed will be the last node of the sublist after
reversed and its next node should always connect the nodes after the sublist (i.e. `2` should link to the
nodes after the sublist, which in this case is `5`). `cur.next = next.next` performs exactly this step.
Note that `next` always points to the element that is to be inserted after `prev.next`.
Thus, we have `cur.next = next.next`.

```
1->2->3->4->5
p  c  n

1->3->2->4->5 (insert 3 between 1 and 2)
p     c  n

1->4->3->2->5 (insert 4 between 1 and 3)
p        c  n
```

## Reference

- http://www.cnblogs.com/grandyang/p/4306611.html
- https://leetcode.com/problems/reverse-linked-list-ii/discuss/30666
