//    Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
//
//    Example 1:
//    Input: [1,2,3,4,5], k=4, x=3
//    Output: [1,2,3,4]
//
//    Example 2:
//    Input: [1,2,3,4,5], k=4, x=-1
//    Output: [1,2,3,4]
//
//    Note:
//    The value k is positive and will always be smaller than the length of the sorted array.
//    Length of the given array is positive and will not exceed 104
//    Absolute value of elements in the array and x will not exceed 104
//    UPDATE (2017/9/19):
//    The arr parameter had been changed to an array of integers (instead of a list of integers).
//    Please reload the code definition to get the latest changes.

#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (fabs(x - arr[mid]) <= fabs(arr[mid+k] - x))
            {
                cout << "[if]" << "mid: " << mid << " " << "mid+k: " << mid+k << " " << "arr[mid]: " << arr[mid] << " " <<
                     "arr[mid+k]: " << arr[mid+k] << " " << "left: " << left << " " << "right: " << right << endl;
                right = mid;
            }
            else
            {
                cout << "[else]" << "mid: " << mid << " " << "mid+k: " << mid+k << " " << "arr[mid]: " << arr[mid] << " " <<
                     "arr[mid+k]: " << arr[mid+k] << " " << "left: " << left << " " << "right: " << right << endl;
                left = mid + 1;
            }
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

using ptr2findClosestElements = vector<int>(Solution::*)(vector<int>&, int, int);

void test(ptr2findClosestElements pfcn)
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int k = 4;
    int x = 3;
    vector<int> ans = {1,2,3,4};
    assert(sol.findClosestElements(nums, k, x) == ans);
    nums = {5,4,3,2,1};
    ans = {5,4,3,2};
    assert(sol.findClosestElements(nums, k, x) == ans);
    k = 4;
    x = 2;
    ans = {4,3,2,1}; // leetcode seems have a bug in this case
    assert(sol.findClosestElements(nums, k, x) == ans);
}

int main()
{
    ptr2findClosestElements pfcn = &Solution::findClosestElements;
    test(pfcn);
}