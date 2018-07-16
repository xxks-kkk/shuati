//    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
//    Example:
//
//    Input: [-2,1,-3,4,-1,2,1,-5,4],
//    Output: 6
//    Explanation: [4,-1,2,1] has the largest sum = 6.
//    Follow up:
//
//    If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Dynamic Programming Approach
    int
    maxSubArray( vector<int> &nums )
    {
        vector<int> dp( nums.size());
        dp[0] = nums[0];
        int max_sum = nums[0];
        for ( int i = 1; i < nums.size(); ++i )
        {
            // dp[i] = the max subarray containing nums[i]
            dp[i] = max( dp[i - 1] + nums[i], nums[i] );
            max_sum = max( max_sum, dp[i] );
        }
        return max_sum;
    }


    // Dynamic Programming Approach 2 (constant space; maw way)
    int
    maxSubArray2( vector<int> &nums )
    {
        int sum = 0;
        int max_sum = nums[0]; // Key: not set to 0
        for ( int i = 0; i < nums.size(); ++i )
        {
            sum += nums[i];
            max_sum = max( sum, max_sum );
            sum = max( sum, 0 );
        }
        return max_sum;
    }


    // Dynamic Programming Approach 3 (constant space; more intuitive; space optimization of approach 1)
    int
    maxSubArray3( vector<int> &nums )
    {
        int maxSoFar = nums[0], maxEndingHere = nums[0];
        for ( int i = 1; i < nums.size(); ++i )
        {
            maxEndingHere = max( maxEndingHere + nums[i], nums[i] );
            maxSoFar = max( maxSoFar, maxEndingHere );
        }
        return maxSoFar;
    }
};

using ptr2maxSubArray = int ( Solution::* )( vector<int> & );


void
test( ptr2maxSubArray pfcn )
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert((sol.*pfcn)( nums ) == 6 );
    nums = {-1, -2, -3};
    assert((sol.*pfcn)( nums ) == -1 );
    nums = {0};
    assert((sol.*pfcn)( nums ) == 0 );
}


int
main()
{
    ptr2maxSubArray pfcn = &Solution::maxSubArray;
    test( pfcn );
    pfcn = &Solution::maxSubArray2;
    test( pfcn );
    pfcn = &Solution::maxSubArray3;
    test( pfcn );
}