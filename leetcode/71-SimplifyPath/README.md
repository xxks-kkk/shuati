## Solution explanation

Nothing surprising if we can observe that `..` links to the pop operation, which naturally leads to the
stack data structure. One thing to note is the corner cases. ` return "/" + "/".join(stack)` deals
the corner case `"/"` and `"/../"`.