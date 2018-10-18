//    Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
//    Find the two elements that appear only once.
//
//    Example:
//
//    Input:  [1,2,1,3,2,5]
//    Output: [3,5]
//    Note:
//
//    The order of the result is not important. So in the above example, [5, 3] is also correct.
//    Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

#include <vector>
#include <numeric> // std::accumulate
#include <functional> // bit_xor
#include <cassert>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int>
    singleNumber(vector<int> &nums)
    {
        // C++: std::accumulate, bit_xor<int>
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // for the given example, since two same value number XOR together gives 0,
        // diff is calculated from 3 XOR 5. 3 XOR 5 = 6 (=0110). In XOR, the only time
        // we can get 1 is when two input bits are different. Then, we can pick any one of
        // the 1 bit to separate two numbers into two groups. In 0110, the 1st and 2nd bit are set to 1 (we count from right).
        // To pick one of those set bits, we can use the trick below, which gives 2 in our example (& is the bit-wise AND),
        // which we will use as a mask (2 = 010, when used in comination with &, we can detect whether the 1st bit is set for
        // any given number) to separate numbers into two groups: 1st bit is 0 group and 1st bit is 1 group. Since two target
        // numbers are different, they belong to separate groups. All the same value number belong to the same group and doing XOR
        // within each group will lead to the target numbers.
        // 3 XOR 5 = 6 (diff)
        // 6    => 0110
        // -6   => 1010
        // 6&-6 => 0010
        diff &= -diff;
        vector<int> res = {0,0};
        for(auto& num : nums)
        {
            if (diff&num) {
                res[0] ^= num;
            }
            else
            {
                res[1] ^= num;
            }
        }
        return res;
    }
};

using ptr2singleNumber = vector<int> (Solution::*)(vector<int> &);

void
test(ptr2singleNumber pfcn)
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    auto res = (sol.*pfcn)(nums);
    auto res_set = unordered_set<int>(res.begin(), res.end());
    auto ans_set = unordered_set<int>{3,5};
    assert(res_set == ans_set);

    nums = {-1,0};
    res = (sol.*pfcn)(nums);
    res_set = unordered_set<int>(res.begin(), res.end());
    ans_set = unordered_set<int>{-1,0};
    assert(res_set == ans_set);
}

int
main()
{
    ptr2singleNumber pfcn = &Solution::singleNumber;
    test(pfcn);
}