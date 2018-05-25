## Solution explanation

Both two methods (`rob` and `rob2`) are based on [House Robber](https://leetcode.com/problems/house-robber/) recursion:
we either pick the current house (`root`) and skip its children (`root->left` and `root->right`) or we skipp the current
house and pick its children.

`rob2` is better optimized than `rob` based on the observation that we perform redundant calculations in `rob`. For example,
part of calculation of `rob(root->left)` to form `res1` is done by `rob(root->left->left)` and `rob(root->left->right)`
again when we calculate `res2`. Specifically, `rob(root->left) = rob(root->left->left) + rob(root->left->right)` if we don't pick
`root->left` house. `rob2`'s optimization is based on this observation.


## Reference

- https://leetcode.com/problems/house-robber-iii/discuss/79333/Simple-C++-solution