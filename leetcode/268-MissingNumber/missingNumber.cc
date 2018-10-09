//    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//    
//    Example 1:
//    
//    Input: [3,0,1]
//    Output: 2
//    Example 2:
//    
//    Input: [9,6,4,2,3,5,7,0,1]
//    Output: 8
//    Note:
//    Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto & num: nums)
        {
            sum += num;
        }
        return (0 + nums.size()) * (nums.size()+1) / 2 - sum;
    }
};

using ptr2missingNumber = int (Solution::*)(vector<int>&);

void test(ptr2missingNumber pfcn)
{
    Solution sol;
    vector<int> input = {3,0,1};
    assert((sol.*pfcn)(input) == 2);
    
    input = {9,6,4,2,3,5,7,0,1};
    assert((sol.*pfcn)(input) == 8);
}

int main()
{
    ptr2missingNumber pfcn = &Solution::missingNumber;
    test(pfcn);
}