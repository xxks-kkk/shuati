## Solution Explanation

If the problem does not require to use the constant space, then our solution
can be the following, which is similar how we reverse the linked list:

```python
def swapPairs(self, head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    if not head or not head.next:
        return head
    n = head.next
    head.next = self.swapPairs(head.next.next)
    n.next = head
    return n
```

In this solution, we use $O(n)$ space on stack. For a list `1->2->3->4`, we
have `head` equals to `1` and `n` equals to `2`. Then, the solution is 
straightforward to understand.

To meet the problem requirement, we use the solution in .py:

Here, `pre` is the previous node. Since the head doesn’t have a previous node, 
I just use `self` instead. Again, `a` is the current node and `b` is the next node.

To go from `pre -> a -> b -> b.next` to `pre -> b -> a -> b.next`, we need to 
change those three references. Instead of thinking about in what order I change them, 
I just change all three at once.

In the implementation, we use `self` to initialize `pre`, which is the same as
using a dummy ListNode object to initialize `pre`. In oter words, `self` is 
equivalent with a dummy ListNode object. In addition, we set `pre = self` and
`pre.next = head`, which is equivalent to `self.next = head` as `pre` and `self`
pointing to the same memory address. Even though `pre` points to different
memory addresses throughout the execution but `self` still points to the same
memory address as it is first intialized. Thus, we
can do `return self.next`.

## Reference

- https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11019