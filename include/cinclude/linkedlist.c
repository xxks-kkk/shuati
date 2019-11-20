#include "linkedlist.h"

// Given an array, convert it into the linked list
struct ListNode *
list2list(int *array, int len)
{
    struct ListNode* head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* current = head;
    for(int i = 0; i < len; ++i)
    {
        current->next = malloc(sizeof(struct ListNode));
        current->next->val = array[i];
        current->next->next = NULL;
        current = current->next;
    }
    // we return dummy header to prevent memory loss
    return head;
}

// transform a linked list to an array
struct Result
printList(struct ListNode *head)
{
    int arrayLen = 0;
    // We assume head is the dummy header
    struct ListNode* current = head->next;
    while(current)
    {
        arrayLen++;
        current = current->next;
    }
    int array[arrayLen];
    int i = 0;
    current = head->next;
    while(current)
    {
        array[i] = current->val;
        current = current->next;
        i++;
    }
    struct Result res;
    res.array = array;
    res.len = arrayLen;
    return res;
}

/**
 * Helper function to free the list
 * @param L
 */
void deleteList(struct ListNode* L)
{
    struct ListNode* h1;
    struct ListNode* h2;
    h1 = L->next;
    L->next = NULL;
    while(h1)
    {
        h2 = h1->next;
        free(h1);
        h1 = h2;
    }
}

// free the list
void freeList(struct ListNode* head)
{
    deleteList(head);
    free(head);
}
