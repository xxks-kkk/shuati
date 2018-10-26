#include "merge.h"
#include <stdlib.h>

// Given two sorted linked lists, return one sorted linked list
// composed of all the nodes of the input lists. The input lists
// are sorted in ascending order (lowest first)

// Example
// a: 1->3
// b: 2->4->6
// out: 1->2->3->4->6

node *
merge(node *a, node *b)
{
    node *a1 = a;
    node *b1 = b;
    node *head = malloc(sizeof(struct node));
    node *curr = head;
    while(a1 && b1)
    {
        if (a1->val < b1->val)
        {
            curr->next = a1;
            a1 = a1->next;
        }
        else
        {
            curr->next = b1;
            b1 = b1->next;
        }
        curr = curr->next;
    }
    while(a1)
    {
        curr->next = a1;
        a1 = a1->next;
        curr = curr->next;
    }
    while(b1)
    {
        curr->next = b1;
        b1 = b1->next;
        curr = curr->next;
    }
    return head->next;
}
