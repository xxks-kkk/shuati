#include "stdio.h"
#include "stdlib.h"
#include "list.h"
#include "assert.h"

void listAppend( struct node** listP, int val ){
  // if the user passed in NULL, panic
  assert( listP );

  struct node* node = malloc( sizeof( struct node ) );
  assert( node );
  node->val = val;
  node->next = NULL;

  // if the user passed in a pointer to NULL, create the head of the list
  if( !*listP) {
    *listP = node;
  } else {
    struct node* list = *listP;
    while( list->next ){
      list = list->next;
    }
    list->next = node;
  }
}

void listPrint( struct node* list ){
  while( list ){
    printf( "%d", list->val);
    if( (list = list->next) ) {
      printf( "->" );
    }
  }
  printf( "\n" );
}

void listSprint( struct node* list, char* buf ){
  while( list ){
    buf += sprintf( buf, "%d", list->val);
    if( (list = list->next) ) {
      buf += sprintf( buf, "->" );
    }
  }
}

int listLen( struct node* list ){
  int i = 0;
  while ( list ) {
    i++;
    list = list->next;
  }
  return i;
}
