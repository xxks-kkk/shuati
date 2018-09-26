//    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//    Example:
//
//    Input: [0,1,0,3,12]
//    Output: [1,3,12,0,0]
//    Note:
//
//    You must do this in-place without making a copy of the array.
//    Minimize the total number of operations.

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        for(; j < nums.size(); ++j)
        {
            nums[j] = 0;
        }
    }
};

using ptr2moveZeroes = void (Solution::*)(vector<int>&);

void test(ptr2moveZeroes pfcn)
{
    Solution sol;
    vector<int> nums = {0,1,0,3,12};
    vector<int> ans = {1,3,12,0,0};
    (sol.*pfcn)(nums);
    assert(nums == ans);
}

int main()
{
    ptr2moveZeroes pfcn = &Solution::moveZeroes;
    test(pfcn);
}
