//    Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//
//    You may assume no duplicates in the array.
//
//    Example 1:
//
//    Input: [1,3,5,6], 5
//    Output: 2
//    Example 2:
//
//    Input: [1,3,5,6], 2
//    Output: 1
//    Example 3:
//
//    Input: [1,3,5,6], 7
//    Output: 4
//    Example 4:
//
//    Input: [1,3,5,6], 0
//    Output: 0

#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    int
    searchInsert(vector<int> &nums, int target)
    {
        if (nums.empty())
        {
            return 0;
        }
        int left = 0;
        int right = nums.size();
        // invariant: x \in [left, right)
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }
        return left;
    }
};

using ptr2searchInsert = int (Solution::*)(vector<int> &, int);

void
test(ptr2searchInsert pfcn)
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    assert((sol.*pfcn)(nums, target) == 2);
    target = 2;
    assert((sol.*pfcn)(nums, target) == 1);
    target = 7;
    assert((sol.*pfcn)(nums, target) == 4);
    target = 0;
    assert((sol.*pfcn)(nums, target) == 0);
}

int
main()
{
    ptr2searchInsert pfcn = &Solution::searchInsert;
    test(pfcn);
}