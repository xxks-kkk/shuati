//    You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//    Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
//    Example 1:
//
//    Input: [2,3,2]
//    Output: 3
//    Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//    because they are adjacent houses.
//    Example 2:
//
//    Input: [1,2,3,1]
//    Output: 4
//    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//    Total amount you can rob = 1 + 3 = 4.

#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    int
    rob( vector<int> &nums )
    {
        int n = nums.size();
        if ( n < 2 )
        {
            return n ? nums[0] : 0;
        }
        return max( robHelper( nums, 0, n - 2 ), robHelper( nums, 1, n - 1 ));
    }


private:
    int
    robHelper( vector<int> &nums, int begin, int end )
    {
        // same as House Rob I solution
        int last = 0;
        int now = 0;
        for ( int i = begin; i < end + 1; ++i )
        {
            int tmp = max( last + nums[i], now );
            last = now;
            now = tmp;
        }
        return now;
    }
};

using ptr2rob = int ( Solution::* )( vector<int> & );


void
test( ptr2rob pfcn )
{
    Solution sol;
    vector<int> nums = {2, 3, 2};
    assert((sol.*pfcn)( nums ) == 3 );
    nums = {1, 2, 3, 1};
    assert((sol.*pfcn)( nums ) == 4 );
    nums = {};
    assert((sol.*pfcn)( nums ) == 0 );
    nums = {0,0};
    assert((sol.*pfcn)(nums) == 0);
}


int
main()
{
    ptr2rob pfcn = &Solution::rob;
    test( pfcn );
}