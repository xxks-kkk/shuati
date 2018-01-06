## Solution explanation

Let's first try to have a better understanding of the problem. The problem is similar
to [189. Rotate Array](https://leetcode.com/problems/rotate-array/description/). Here are
some examples:

- Given `[0,1,2]`, rotate 1 steps to the right -> `[2,0,1]`.

- Given `[0,1,2]`, rotate 2 steps to the right -> `[1,2,0]`.

- Given `[0,1,2]`, rotate 3 steps to the right -> `[0,1,2]`.

- Given `[0,1,2]`, rotate 4 steps to the right -> `[2,0,1]`.

Here, `k` can be greater than the length of the linked list (i.e., `n`). One observation is that
no matter how big `k` is, the result is always the same as rotating `k % n` steps to the right.

We use the two pointers appraoch to solve this problem. The `fast` pointer moves `k` steps along
the list first. Then, both `slow` and `fast` moves togther until `fast` pointer reaches the end
of the list. Then, the next node of `slow` pointer is the new head of the list after rotation. 
The reason we have `fast` pointer first move `k` steps is that we want to have a `k` distance
between two pointers and when the `fast` reaches the end, we know exactly where is our new head of the list.

```
k = 2

1 -> 2 -> 3 -> 4 -> 5
          ^    ^    ^
          |    |    |  
          slow new  fast
               head
               
after rotation:
4 -> 5 -> 1 -> 2 -> 3
```

When use the following snippet to handle the case when `k` is greater than the length of the list:

```python
fast = head
k = k % list_len
```

Also, be careful with the case, say `[1,2]` and `k = 2`. The rotation result is still `[1,2]`. This case
is handled by:

```python
if fast == head:
    return head
```

We need this special case handling because both `slow` and `fast` will start to move from head and
the new head will be `None` when `fast` reaches the end because `slow` also reaches the end and
`slow.next` is `None`
 
Alternative solution exists, see [the 2nd link in the ref section](http://www.cnblogs.com/grandyang/p/4355505.html).
 
## Reference

- https://leetcode.com/problems/rotate-list/discuss/22735/
- http://www.cnblogs.com/grandyang/p/4355505.html