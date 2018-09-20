//    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
//
//    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
//
//    You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
//
//    Example:
//
//    Given n = 5, and version = 4 is the first bad version.
//
//    call isBadVersion(3) -> false
//    call isBadVersion(5) -> true
//    call isBadVersion(4) -> true
//
//    Then 4 is the first bad version.

#include <cassert>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
    int badVersion = 4; // prefixed bad version
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n;
        while(left < right)
        {
            // invariant: badVersion \in [left, right)
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid))
            {
                /* This element is at least as large as the element, so anything after it can't
                * be the first element that's at least as large.*/
                right = mid;
            }
            else
            {
                /* This index, and everything below it, must not be the first element
                 * greater than what we're looking for (i.e. badVersion) because this element is no greater
                 * than the element.*/
                left = mid + 1;
            }
        }
        return left;
    }
};

using ptr2fistBadVersion = int (Solution::*)(int);

void test(ptr2fistBadVersion pfcn)
{
    Solution sol;
    int version = 4;
    int n = 5;
    assert((sol.*pfcn)(n) == 4);
}

int main()
{
    ptr2fistBadVersion pfcn = &Solution::firstBadVersion;
    test(pfcn);
}