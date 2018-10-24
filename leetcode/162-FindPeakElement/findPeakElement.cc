/*************************************************************************
  > File Name:       findPeakElement.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/24/18
  > Description:
    
    C++ Solution
 ************************************************************************/

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        // invariant: peak \in [left, right]
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid+1])
            {
                left++;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};

using ptr2findPeakElement = int (Solution::*)(vector<int>&);

void test(ptr2findPeakElement pfcn)
{
    Solution sol;
    assert((sol.*pfcn)(vector<int>()={1,2,3,1}) == 2);
    assert((sol.*pfcn)(vector<int>()={1}) == 0);
}

int main()
{
    ptr2findPeakElement pfcn = &Solution::findPeakElement;
    test(pfcn);
}