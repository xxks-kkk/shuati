/* Arista Network
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int a[] = { 4,5,7,8,9 };
int b[] = { 4,5,6,8,9,10};
int c[] = { 4,6,7,8,9,10};
int d[] = { 4,5,6,7,9,10};
int e[] = { 4,5,6,7,8,9};

// basic O(N) solution
int findMissing( int* a, int len ) {
  int p1 = 0;
  int p2 = 1;
  while(p2 < len)
  {
    if(a[p2] - a[p1] > 1)
    {
      return a[p1] + 1;
    }
    p1++;
    p2++;
  }
  return a[p1] + 1;
}

// O(logN) solution using binary search
int findMissing2( int* a, int len ) {
  // invariant: missing number \in [left, right)
  int left = 0;
  int right = len;
  while(left < right)
  {
    int mid = left + (right - left)/2;
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

// O(logN) solution using binary search
int findMissing3( int* a, int len ) {
  // invariant: missing number \in [left, right]
  int left = 0;
  int right = len - 1;
  while(left <= right)
  {
    int mid = left + (right - left)/2;
    if (a[mid] > mid + a[0])
    {
      right = mid-1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return left + a[0];
}


int
main() {

   assert( findMissing( a, 5 ) == 6 );
   assert( findMissing( b, 6 ) == 7 );
   assert( findMissing( c, 6 ) == 5 );
   assert( findMissing( d, 6 ) == 8 );
   assert( findMissing( e, 6 ) == 10 );

   assert( findMissing2( a, 5 ) == 6 );
   assert( findMissing2( b, 6 ) == 7 );
   assert( findMissing2( c, 6 ) == 5 );
   assert( findMissing2( d, 6 ) == 8 );
   assert( findMissing2( e, 6 ) == 10 );

   assert( findMissing3( a, 5 ) == 6 );
   assert( findMissing3( b, 6 ) == 7 );
   assert( findMissing3( c, 6 ) == 5 );
   assert( findMissing3( d, 6 ) == 8 );
   assert( findMissing3( e, 6 ) == 10 );   
}
