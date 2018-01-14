## Solution explanation

We separate the list into 2 distinct lists and link them afterwards. The idea is similar to one
of the solutions to [reverseList](https://github.com/xxks-kkk/algo/blob/master/linkedList/generic/linkedList.c):
We basically go through the original list, and insert node we visit
at the very beginning of the new list. Then, we return the new list.

## Reference

- https://leetcode.com/problems/partition-list/discuss/29185