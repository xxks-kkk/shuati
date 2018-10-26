#ifndef LIST_H
#define LIST_H

struct node{
  int val;
  struct node* next;
};

void listAppend( struct node** listP, int val );

void listPrint( struct node* list );

void listSprint( struct node* list, char* buf );

int listLen( struct node* list );

#endif
