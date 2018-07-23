//    Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
//
//
//    Example 1:
//
//    Input: nums = [-1,0,3,5,9,12], target = 9
//    Output: 4
//    Explanation: 9 exists in nums and its index is 4
//
//    Example 2:
//
//    Input: nums = [-1,0,3,5,9,12], target = 2
//    Output: -1
//    Explanation: 2 does not exist in nums so return -1
//
//
//    Note:
//
//    You may assume that all elements in nums are unique.
//    n will be in the range [1, 10000].
//    The value of each element in nums will be in the range [-9999, 9999].

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            // invariant: index \in [left, right]
            int mid = left + (right - left) / 2;
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

using ptr2search  = int (Solution::*)(vector<int>&, int);

void test(ptr2search pfcn)
{
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    assert((sol.*pfcn)(nums,9) == 4);
    nums = {-1,0,3,5,9,12};
    target = 2;
    assert((sol.*pfcn)(nums,2) == -1);
}

int main()
{
    ptr2search pfcn = &Solution::search;
    test(pfcn);
}