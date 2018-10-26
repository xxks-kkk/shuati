#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

extern int find( int *, int );

int main( int argc, char *argv[] ) {
   int o[4][5] = { { 4,6,7,8,9 },
                   { 4,5,7,8,9 },
                   { 4,5,6,8,9 },
                   { 4,5,6,7,9 } };

   int e[5][6] = { { 4,6,7,8,9,10 },
                   { 4,5,7,8,9,10 },
                   { 4,5,6,8,9,10 },
                   { 4,5,6,7,9,10 },
                   { 4,5,6,7,8,10 } };
   int i;
   for( i=0; i < 4; i++ )
      assert( find( o[ i ], 5 ) == i + 5 );
   for( i=0; i < 5; i++ )
      assert( find( e[ i ], 6 ) == i + 5 );

   printf ("I'm a winner\n");
    return 0;
}

