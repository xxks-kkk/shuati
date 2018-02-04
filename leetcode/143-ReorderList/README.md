## Solution explanation

This problem is good combination of recurring techniques:

- reverse a linked list
- find the middle point of the linked list using two pointers

The idea to solve the problem is to first find the middle point of the linked list and then
reverse the rest of linked list starting from the first element after the middle point. Finally,
we fix the order of the list to the desired result.

There are a couple of places need to be extra careful. Linked list problems are easy(?) to think but
hard to code right with one pass:

- When we talk about the middle point, we mean the following given whether the number of elements in 
the linked list is even or odd. In the code, the middle point is pointed by `tortoise`:

```
1 -----> 2 -----> 3 -> 4  (n = 4)
     (tortoise)
1->2->3----->4------>5->6->7 (n = 7)
         (tortoise)
```

For the even number of elements, there is no element that falls exactly at the middle point (i.e.,
for the example above, the middle point is between `2` and `3`). Thus, we need to define our way
for the middle point. In this case, we use `2` as our middle point. The way we implement our middle 
point finding solution is through two pointers. For the odd case, `tortoise` exactly points to the
element falls on the middle point (i.e., $(7+1)/2 = 4$).

- Finding middle point using two pointers is a very common technique. We need to remember the template
of the snippet. Notice the fast pointer (`hare`) is initialized to `head.next` and slow pointer
`tortoise` is initialized to `head`. Pay attent to loop condition and we update `hare` with
`hare.next.next` **NOT** ~~`hare.next`~~.

```python
hare = head.next
tortoise = head
while hare and hare.next:
    hare = hare.next.next
    tortoise = tortoise.next
```

- For this problem, we want to reverse the list starting from the first element after the middle point.
This leads to `L = tortoise.next`

- For this problem, remember to set `tortoise.next` to `None`. This will break up the linked list into
two. We do this because when we reorder the list, we want to know when we should stop.

## Reference

- https://leetcode.com/problems/reorder-list/discuss/44992/Java-solution-with-3-steps