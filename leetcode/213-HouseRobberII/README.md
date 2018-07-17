## Solution explanation

this problem can simply be decomposed into two House Robber problems.

Suppose there are `n` houses, since house `0` and `n - 1` are now neighbors, we cannot rob them together and
thus the solution is now the maximum of

- Rob houses `0` to `n - 2`
- Rob houses `1` to `n - 1`

**NOTE:** We can write `robHelper` as the following, which is similar to [CS Dojo's DP video](https://youtu.be/vYquumk4nWw)'s
way of constructing the DP table. But, as you can see, we need to do more boundary checking to handle the case like
`[0,0]`.

```cpp
int
robHelper( vector<int> &nums, int begin, int end )
{
    if (begin == end)
    {
        return nums[begin];
    }
    int last = nums[begin];
    int now = max(nums[begin], nums[begin+1]);
    for ( int i = begin + 2; i < end + 1; ++i )
    {
        int tmp = max( last + nums[i], now );
        last = now;
        now = tmp;
    }
    return now;
}
```

## Reference

- https://leetcode.com/problems/house-robber-ii/discuss/59921/9-lines-0ms-O(1)-Space-C++-solution