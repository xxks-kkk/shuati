#include "shared_headers.h"

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct Result
{
    int* array;
    int len;
};

// Given an array, convert it into the linked list
struct ListNode* list2list(int* array, int len);

// transform a linked list to an array
struct Result printList(struct ListNode* head);

// free the list
void freeList(struct ListNode* head);


