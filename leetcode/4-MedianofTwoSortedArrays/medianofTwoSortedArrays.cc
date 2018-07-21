//    There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
//    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
//    Example 1:
//    nums1 = [1, 3]
//    nums2 = [2]
//
//    The median is 2.0
//    Example 2:
//    nums1 = [1, 2]
//    nums2 = [3, 4]
//
//    The median is (2 + 3)/2 = 2.5

#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution
{
public:
    double
    findMedianSortedArrays( vector<int> &nums1, vector<int> &nums2 )
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 < n2)
        {
            // we want to make sure `nums2` is always the shorter array
            return this->findMedianSortedArrays(nums2, nums1);
        }
        // We search for C2
        int left = 0;
        int right = n2 * 2;
        while (left <= right)
        {
            // invariant: C2 \in [Left, right]
            int mid2 = (left + right) / 2;
            int mid1 = n1 + n2 - mid2;

            double l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
            double r1 = (mid1 == n1*2) ? INT_MAX : nums1[mid1/2];
            double l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
            double r2 = (mid2 == n2*2) ? INT_MAX : nums2[mid2/2];

            // we want to keep: l1 <= r2 && l2 <= r1
            if(l1 > r2)
            {
                // we want to move C1 to left, which means move C2 to right
                left = mid2 + 1;
            }
            else if (l2 > r1)
            {
                // we want to move C2 to left
                right = mid2 - 1;
            }
            else
            {
                // we find the right C2 and thus, the right C1
                return (max(l1,l2) + min(r1,r2))/2;
            }
        }
        return -1;
    }
};

using ptr2findMedianSortedArrays = double (Solution::*)(vector<int>&, vector<int>&);

void test(ptr2findMedianSortedArrays pfcn)
{
    Solution sol;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    assert((sol.*pfcn)(nums1,nums2) == 2.0);
    nums1 = {1,2};
    nums2 = {3,4};
    assert((sol.*pfcn)(nums1,nums2) == 2.5);
}

int main()
{
    ptr2findMedianSortedArrays pfcn = &Solution::findMedianSortedArrays;
    test(pfcn);
}