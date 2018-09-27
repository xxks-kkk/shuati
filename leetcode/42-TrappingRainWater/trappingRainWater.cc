//    Given n non-negative integers representing an elevation map where the width of each bar is 1,
//    compute how much water it is able to trap after raining.
//
//    Example:
//
//    Input: [0,1,0,2,1,0,1,3,2,1,2,1]
//    Output: 6

#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    // Solution: Brute Force
    int
    trap( vector<int> &height )
    {
        int res = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            int left_max = 0;
            int right_max = 0;
            for(int j = i; j >= 0; --j)
            {
                left_max = max(left_max, height[j]);
            }
            for(int j = i; j < height.size(); ++j)
            {
                right_max = max(right_max, height[j]);
            }
            res += min(right_max, left_max) - height[i];
        }
        return res;
    }

    // Solution: DP
    int
    trap2( vector<int> &height )
    {
        int res = 0;
        int n = height.size();
        if (n == 0)
        {
            return res;
        }
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] = height[0];
        for(int i = 1; i < n; ++i)
        {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        right_max[n-1] = height[n-1];
        for(int j = n-2; j >= 0; --j)
        {
            right_max[j] = max(right_max[j+1],height[j]);
        }
        for(int i = 0; i < n; ++i)
        {
            res += (min(left_max[i], right_max[i]) - height[i]);
        }
        return res;
    }


    // Solution: use two pointers
    int
    trap3( vector<int> &height )
    {
        int left_ptr = 0;
        int right_ptr = height.size() - 1;
        int minHeight = 0;
        int res = 0;
        while(left_ptr < right_ptr)
        {
            while(left_ptr < right_ptr && height[left_ptr] <= minHeight)
            {
                res += (minHeight - height[left_ptr]);
                left_ptr++;
            }
            while(left_ptr < right_ptr && height[right_ptr] <= minHeight)
            {
                res += (minHeight - height[right_ptr]);
                right_ptr--;
            }
            minHeight = min(left_ptr, right_ptr);
        }
        return res;
    }
};

using ptr2trap = int ( Solution::* )( vector<int> & );


void
test( ptr2trap pfcn )
{
    Solution sol;
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    assert((sol.*pfcn)( input ) == 6 );
}


int
main()
{
    ptr2trap pfcn = &Solution::trap;
    test( pfcn );
    pfcn = &Solution::trap2;
    test( pfcn );
//    pfcn = &Solution::trap3;
//    test( pfcn );
}

