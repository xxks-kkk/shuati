//    Given two arrays, write a function to compute their intersection.
//
//    Example 1:
//
//    Input: nums1 = [1,2,2,1], nums2 = [2,2]
//    Output: [2,2]
//    Example 2:
//
//    Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//    Output: [4,9]
//    Note:
//
//    Each element in the result should appear as many times as it shows in both arrays.
//    The result can be in any order.
//    Follow up:
//
//    What if the given array is already sorted? How would you optimize your algorithm?
//    What if nums1's size is small compared to nums2's size? Which algorithm is better?
//    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
//    > Ans:
//          If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, read chunks of array that fit into the memory,
//          and record the intersections.
//          If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort),
//          then read 2 elements from each array at a time in memory, record intersections.

#include <vector>
#include <set>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // My solution: O(mlogn)
    vector<int>
    intersect( vector<int> &nums1, vector<int> &nums2 )
    {
        vector<int> res;
        multiset<int> s( nums1.begin(), nums1.end());
        for ( auto &num : nums2 )
        {
            // Note that here we only remove one element from multiset
            // erase(num) will erase all duplicates in the multiset. We don't want this.
            auto iter = s.find( num );
            if ( iter != s.end())
            {
                s.erase( iter );
                res.push_back( num );
            }
        }
        return res;
    }


    // Solution using hashmap
    vector<int>
    intersect2( vector<int> &nums1, vector<int> &nums2 )
    {
        unordered_map<int, int> table;
        vector<int> res;
        for ( auto &num : nums1 )
        {
            table[num] += 1;
        }
        for ( auto &num: nums2 )
        {
            if ( table[num] > 0 )
            {
                table[num]--;
                res.push_back( num );
            }
        }
        return res;
    }


    // Solution when the two arrays are sorted
    vector<int>
    intersect3( vector<int> &nums1, vector<int> &nums2 )
    {
        vector<int> res;
        sort( nums1.begin(), nums1.end());
        sort( nums2.begin(), nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        while ( i < n1 && j < n2 )
        {
            if ( nums1[i] == nums2[j] )
            {
                res.push_back( nums1[i] );
                i++;
                j++;
            }
            else if ( nums1[i] < nums2[j] )
            {
                i++;
            }
            else if ( nums1[i] > nums2[j] )
            {
                j++;
            }
        }
        return res;
    }
};

using ptr2intersect = vector<int> ( Solution::* )( vector<int> &, vector<int> & );


void
test( ptr2intersect pfcn )
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ans = {2, 2};
    auto res = (sol.*pfcn)( nums1, nums2 );
    assert( ans == res );

    nums1 = {4, 9, 5};
    nums2 = {9, 4, 9, 8, 4};
    ans = {4, 9};
    res = (sol.*pfcn)( nums1, nums2 );
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
    ptr2intersect pfcn = &Solution::intersect;
    test( pfcn );
    pfcn = &Solution::intersect2;
    test( pfcn );
    pfcn = &Solution::intersect3;
    test( pfcn );
}