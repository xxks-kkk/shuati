//    Given an array nums and a value val, remove all instances of that value in-place and return the new length.
//
//    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
//    The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
//    Example 1:
//
//    Given nums = [3,2,2,3], val = 3,
//
//    Your function should return length = 2, with the first two elements of nums being 2.
//
//    It doesn't matter what you leave beyond the returned length.
//    Example 2:
//
//    Given nums = [0,1,2,2,3,0,4,2], val = 2,
//
//    Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.
//
//    Note that the order of those five elements can be arbitrary.
//
//    It doesn't matter what values are set beyond the returned length.
//    Clarification:
//
//    Confused why the returned value is an integer but your answer is an array?
//
//    Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//
//    Internally you can think of this:
//
//    // nums is passed in by reference. (i.e., without making a copy)
//    int len = removeElement(nums, val);
//
//    // any modification to nums in your function would be known by the caller.
//    // using the length returned by your function, it prints the first len elements.
//    for (int i = 0; i < len; i++) {
//        print(nums[i]);
//    }

#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // Approach 1: two pointers
    int
    removeElement( vector<int> &nums, int val )
    {
        int i = 0;
        for ( int j = 0; j < nums.size(); ++j )
        {
            if ( nums[j] != val )
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }


    // Approach 2: two pointers - when elements to remove are rare
    int
    removeElement2( vector<int> &nums, int val )
    {
        int i = 0;
        int n = nums.size();
        while ( i < n )
        {
            if ( nums[i] == val )
            {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            }
            else
            {
                i++;
            }
        }
        return n;
    }
};

using ptr2removeElement = int ( Solution::* )( vector<int> &, int );


void
test( ptr2removeElement pfcn )
{
    Solution sol;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    assert((sol.*pfcn)( nums, val ) == 2 );
    unordered_set<int> nums_set( nums.begin(), nums.begin() + 2 );
    unordered_set<int> ans = {2, 2};
    assert( nums_set == ans );

    nums = {0, 1, 2, 2, 3, 0, 4, 2};
    val = 2;
    assert((sol.*pfcn)( nums, val ) == 5 );
    unordered_set<int> nums_set2( nums.begin(), nums.begin() + 5 );
    unordered_set<int> ans2 = {0, 1, 3, 0, 4};
    assert( nums_set2 == ans2 );

}


int
main()
{
    ptr2removeElement pfcn = &Solution::removeElement;
    test( pfcn );
    pfcn = &Solution::removeElement2;
    test( pfcn );
}