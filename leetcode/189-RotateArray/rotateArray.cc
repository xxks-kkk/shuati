//    Given an array, rotate the array to the right by k steps, where k is non-negative.
//
//    Example 1:
//
//    Input: [1,2,3,4,5,6,7] and k = 3
//    Output: [5,6,7,1,2,3,4]
//    Explanation:
//    rotate 1 steps to the right: [7,1,2,3,4,5,6]
//    rotate 2 steps to the right: [6,7,1,2,3,4,5]
//    rotate 3 steps to the right: [5,6,7,1,2,3,4]
//    Example 2:
//
//    Input: [-1,-100,3,99] and k = 2
//    Output: [3,99,-1,-100]
//    Explanation:
//    rotate 1 steps to the right: [99,-1,-100,3]
//    rotate 2 steps to the right: [3,99,-1,-100]

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // Use reverse
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
private:
    void reverse(vector<int>& nums, int start, int end)
    {
        int left = start;
        int right = end;
        while (left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
};

using ptr2rotate = void (Solution::*)(vector<int>&, int);

void test(ptr2rotate pfcn)
{
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    (sol.*pfcn)(nums, k);
    vector<int> ans = {5,6,7,1,2,3,4};
    assert(nums == ans);
    nums = {-1,-100,3,99};
    k = 2;
    ans = {3,99,-1,-100};
    (sol.*pfcn)(nums, k);
    assert(nums == ans);
}

int main()
{
    ptr2rotate pfcn = &Solution::rotate;
    test(pfcn);
}