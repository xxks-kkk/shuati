#include <stdio.h>
#include <stdlib.h>

//
// find( ... )
//
// find takes and array of sorted consecutive positive ints where 
//  one number is missing and returns the missing number
// find should return 0 on all error conditions
//
// [ 1, 2, 3, 4, 6, 7, 8, 9 ] -> return 5
// [ 11, 12, 13, 15, 16, 17 ] -> return 14
//

int find( int* a, int len )
{
    // invariant: missing number \in [left, right)
    int left = 0;
    int right = len;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == mid + a[0])
        {
            left = mid + 1;
        }
        else if (a[mid] > mid + a[0])
        {
            right = mid;
        }
    }
    return left + a[0];
}
