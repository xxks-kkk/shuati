#include <stdio.h>
#include <stdlib.h>
#include "list.h"
/**
 * Given a linked list of the structure:
   struct node {
      char c;
      struct node* next;
   };
   print out the fibonacci nodes e.g. the 1st, 2nd, 3rd, 5th, 8th... nodes
   up until the list ends. 
 */
#define NODES 10000000
int main( int argc, char** argv ) {

    struct node* list = createList( NODES );

    struct node* curr = list;
    int c = 1;
    int p = 1;
    while(curr)
    {
        printf("%c", curr->c);
//        fflush(stdout);
        int tmp = c;
        c = p + c;
        p = tmp;
        for(int i = tmp; i < c; ++i)
        {
            if (curr)
            {
                curr = curr->next;
            }
            else
            {
                break;
            }
        }
    }

    freeList(list);
}
