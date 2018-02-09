## Solution explanation

The trick is to use `pre`, which is initialized as `lower - 1` and have `upper+1` append to the end
of the `nums`. For example, `lower = 0` and `upper = 99`. Then, use `pre` with `lower - 1` handles
the case `【1, ...]` where `0` is missing. Similarly, `upper+1` appending to the end of the list
handles the case `...,98,100]` where `99` is missing. This problem doesn't really have nice structure
way to solve other than pattern discovery.

## Reference

- https://leetcode.com/problems/missing-ranges/discuss/50631/Ten-line-python-solution
- https://leetcode.com/problems/missing-ranges/discuss/50474/Concise-Python-Solution-with-Explanation