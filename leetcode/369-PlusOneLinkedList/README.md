## Solution explanation

The idea is inspired by [Recursive Solution to 234. Palindrome Linked List](https://github.com/xxks-kkk/shuati/blob/master/leetcode/234-PalindromeLinkedList/palindromeLinkedList.cc).
We use the recursion call to reach the last node of the list and then we add 1 (e.g. `next`) to its value. If
the value is greater than 0, we set `next` to 0 and pop the call stack until the end. We are done. If the value
is 0, we keep `next` as 1. Now `next` works as a carry.  When the call stack is poped, we are at the second last
node of the list, we add carry to its value. We recursively do this until we reach the first node. If our `next` is
still 1, that means we need to create a new node (e.g. add 1 to `[9]` will result in `[1,0]`).