## Solution explanation

Use `p` and `q` iterate two list repectively. When one of `p`,`q` reach the None, assign the head of another list to that pointer.
Work in all three senarios:

- 1. Two list with same length and have intersection:

```
1->3->5->6->None->1->2->5->6->None
1->2->5->6->None->1->3->5->6->None
```
p and q will reach 5, 6 elements at the same time, then return p.

- 2. Two list with different length and have intersection:

```
1->3->5->6->None->2->5->6->None
2->5->6->None->1->3->5->6->None
```
p and q will reach 5, 6 elements at the same time, then return p.

- 3. Two list have no itersection:

```
1->3->5->None->2->None
2->None->1->3->5->None
```

p and q will reach the None in the end at the same time, then return None, which means they have no interaction.

## Reference

- https://leetcode.com/problems/intersection-of-two-linked-lists/solution/
- https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/144750/My-accepted-easy-understanding-python-code
- https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49789/My-accepted-simple-and-shortest-C++-code-with-comments-explaining-the-algorithm.-Any-comments-or-improvements