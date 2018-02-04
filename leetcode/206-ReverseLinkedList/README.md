## Solution explanation

Reverse linked list is no hard but it is hard to code correctly with one pass.
The following points out several place that mistakes can happen:

- In "Approach 2", remember to initialize `current = head` and `prev = NULL` **NOT** ~~`current = head->next`~~
and ~~`prev = head`~~.