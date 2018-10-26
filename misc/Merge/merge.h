#ifndef __MERGE_H__
#define __MERGE_H__

typedef struct node {
  int val;
  struct node *next;
} node;

node *merge( node *, node *);

#endif // __MERGE_H__
