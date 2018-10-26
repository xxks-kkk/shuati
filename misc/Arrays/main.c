#include <assert.h>
#include <stdio.h>
#include "arrays.h"

void insert( int* val, int* array, int index ) {
   printf( "\tInserting %d\n", *val );
   array[ index ] = (*val)++;
}

void verify( int* val, int* array, int index ) {
   printf( "\tVerifying %d\n", *val );
   assert( array[ index ] == (*val)++ );
}

void applyToArray( int* val, void* array, int dims, int* dimArr,
                    void (* func )( int* val, int* array, int index) ) {
   if( dims > 1 ) {
      int** arr = array;
      for( int i = 0; i < dimArr[0]; i++ ) {
         applyToArray( val, arr[ i ], dims - 1, dimArr + 1, func );
      }
   } else {
      for( int i = 0; i < dimArr[ 0 ]; i++ ) {
         func( val, (int*)array, i );
      }
   }
}

void testNdArray( void* array, int dims, int* dimArr ) {
   int startingVal = 0;
   applyToArray( &startingVal, array, dims, dimArr, insert );
   startingVal = 0;
   applyToArray( &startingVal, array, dims, dimArr, verify );
}

int main( int argc, char** argv ){
    int dims1[] = { 5 };
    int* arr1 = getNdArray( 1, dims1 );
    printf( "Testing { 5 }\n" );
    testNdArray( arr1, 1, dims1 );

    int dims2[] = { 1, 3 };
    int ** arr2 = getNdArray( 2, dims2 );
    printf( "Testing { 1, 3 }\n" );
    testNdArray( arr2, 2, dims2 );

    int dims3[] = { 1, 1, 1 };
    int ** arr3 = getNdArray( 3, dims3 );
    printf( "Testing { 1, 1, 1 }\n" );
    testNdArray( arr3, 3, dims3 );

    int dims4[] = { 2, 3, 4, 5 };
    printf( "Testing { 2, 3, 4, 5 }\n" );
    int **** arr4 = getNdArray( 4, dims4 );
    testNdArray( arr4, 4, dims4 );

    printf( "freeing arrays...\n" );
    freeNdArray( arr1, 1, dims1 );
    printf( "freed arr1\n" );
    freeNdArray( arr2, 2, dims2 );
    printf( "freed arr2\n" );
    freeNdArray( arr3, 3, dims3 );
    printf( "freed arr3\n" );
    freeNdArray( arr4, 4, dims4 );
    printf( "freed arr4\n" );

    printf( "WOOHOO :)\n" );
    return 0;
}
