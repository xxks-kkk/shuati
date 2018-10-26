#include <stdlib.h>
#include <assert.h>
struct node {
    char c;
    struct node* home;
    struct node* next;
};

struct node* createList( int nodes );
void freeList( struct node* list );

struct node* createList( int nodes ) {
    int i = 0;
    const char* message = "congratulations, you've implemented fib correctly!";
    struct node* list = 
        ( struct node* ) malloc( sizeof( struct node ) * nodes );
    assert( list );
    for( i = nodes - 1; i >= 0; --i ) {
        list[ i ].c = ' ' + ( random() % ( '~' - ' ' ) );
        list[ i ].next = list + ( i - 1 );
        list[ i ].home = list;
    }
    list[ 0 ].next = NULL;

    int last = 0;
    int cur = 1;
    int messagePos = 0;
    struct node * ptr = NULL;
    if( nodes >= 2 ) {
        list[ nodes - 1].c = message[ 0 ];
        list[ nodes - 1].next->c = message[ 1 ];
        ptr = list[ nodes - 1].next;
        messagePos = 2;
    }
    while( cur < nodes ) {
        int target = last + cur;
        for( i = 0; i < target && ptr; i++ ) {
            ptr = ptr->next;
        }
        if( ptr ) {
            ptr->c = message[ messagePos++ ];
        }
        last = cur;
        cur = target;
    }
    return &list[ nodes - 1 ];
}

void freeList( struct node* list ) {
    free( list->home );
}
