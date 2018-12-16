## Solution explanation

### Understand the problem

To see why given example has output `[3,4]`, consider x as an iterm instead of seeing x as clock strike (or coordinate on line):

```
[0][1][2][3][4][5][6]
```

Now, function `0` grabs 3 boxes (`[0]`,`[1]`,`[6]`) and function `1` grabs the rest of 4 boxes.

### Using stack

The idea of using stack can be seen through the code. Here, I give out two proofs about two invariants (i.e., `assert`
in the code) we use:

1. If `item.status` is `"end"`, `item.id` is the same as `st.top().id`

Suppose ids are different. Since `item.status` is `"end"` and the input logs will be sorted by timestamp, then
`item.id` must be some id already in the stack. Since two ids are different, then `item.id` must in the stack lower
than `st.top().id`. However, since we push item to stack when see `"start"` and pop stack when function call ends 
(e.g., seeing matching id with status `"end"`), then function `item.id` is the caller of function `st.top().id`. Then,
it is impossible that the caller exits without the finish execution of callee in a single-thread API. Then, the assumption
doesn't hold.

2. After pop of the stack, `st.top().status == "start"`

The only way that item stays in the stack is its corresponding `"end"` log hasn't shown up yet. We only push item with
`"start"` onto the stack. Thus, the claim holds.

## Reference

- https://leetcode.com/problems/exclusive-time-of-functions/discuss/105084/How-is-function-1-executing-4-units-of-time
- https://leetcode.com/problems/exclusive-time-of-functions/discuss/105103/C%2B%2B-O(n)-stack-with-explaination