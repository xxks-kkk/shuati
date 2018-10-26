#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "merge.h"

node *makeList( const char *l ) {
   node *head = 0;
   node **cur = &head;
   char *dup = strdup( l );
   char *num = strtok( dup, " " );

   while( num ) {
      *cur = malloc( sizeof( node ) );
      (*cur)->val = atoi( num );
      (*cur)->next = 0;
      cur = &(*cur)->next;
      num = strtok( 0, " " );
   }

   free( dup );
   return head;
}

void printList( node *l ) {
   while( l ) {
      printf( "%d ", l->val );
      l = l->next;
   }
   printf( "\n" );
}

int listEqual( node *a, node *b ) {
   if( !a ) {
      return b == 0;
   }
   if( !b ) {
      return a == 0;
   }
   return a->val == b->val && listEqual( a->next, b->next );
}

void testCase( char *a, char *b, char *e ) {
   node *expected = makeList( e );
   node *forward = merge( makeList( a ), makeList( b ) );
   node *reverse = merge( makeList( b ), makeList( a ) );
   assert( listEqual( expected, forward ) );
   assert( listEqual( expected, reverse ) );
   printf( ". " );
}

int main( int argc, char **argv ) {
   printf( "Testing." );
   testCase( "1 3 5 7", "2 4 6 8", "1 2 3 4 5 6 7 8" );
   testCase( "1 2 4", "0", "0 1 2 4" );
   testCase( "1 2 3 5", "4 6 7", "1 2 3 4 5 6 7" );
   testCase( "1 5", "2 3", "1 2 3 5" );
   testCase( "", "1 2 3", "1 2 3" );
   testCase( "", "", "" );
   printf( "COMPLETE\n" );
   return 0;
}
