//    Given two arrays, write a function to compute their intersection.
//
//    Example 1:
//
//    Input: nums1 = [1,2,2,1], nums2 = [2,2]
//    Output: [2]
//    Example 2:
//
//    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//    Output: [9,4]
//    Note:
//
//    Each element in the result must be unique.
//    The result can be in any order.

// Indeed On-Campus 09/25/2018

#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int>
    intersection( vector<int> &nums1, vector<int> &nums2 )
    {
        vector<int> res;
        unordered_set<int> set( nums1.begin(), nums1.end());
        for ( auto num: nums2 )
        {
            if(set.erase(num)) // return 1 if num exists in the set and 0 otherwise
            {
                res.emplace_back(num);
            }
        }
        return res;
    }
};

using ptr2intersection = vector<int> ( Solution::* )( vector<int> &, vector<int> & );


void
test( ptr2intersection pfcn )
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ans = {2};
    assert((sol.*pfcn)( nums1, nums2 ) == ans );

    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    ans = {9, 4};
    auto res = (sol.*pfcn)( nums1, nums2 );
    int count = 0;
    for ( auto &i: res )
    {
        if ( find( ans.begin(), ans.end(), i ) != ans.end())
        {
            count++;
        }
    }
    assert( count == ans.size());
}


int
main()
{
    ptr2intersection pfcn = &Solution::intersection;
    test( pfcn );
}