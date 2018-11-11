//    Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//    Example:
//
//    Input:  [1,2,3,4]
//    Output: [24,12,8,6]
//    Note: Please solve it without division and in O(n).
//
//    Follow up:
//    Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<int>
    productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n,1);
        int fromBegin = 1;
        int fromLast = 1;

        for(int i = 0; i < n; ++i)
        {
            res[i] *= fromBegin;
            fromBegin *= nums[i];
            res[n-1-i] *= fromLast;
            fromLast *= nums[n-1-i];
        }
        return res;
    }
};

using ptr2productExceptSelf = vector<int> (Solution::*)(vector<int> &);

void
test(ptr2productExceptSelf pfcn)
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> ans = {24, 12, 8, 6};
    assert((sol.*pfcn)(nums) == ans);
}

int
main()
{
    ptr2productExceptSelf pfcn = &Solution::productExceptSelf;
    test(pfcn);
}