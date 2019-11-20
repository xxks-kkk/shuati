/*
 * [Source]
 * 
 * https://leetcode.com/problems/merge-two-sorted-lists
 *
 * [Problem Description]
 *
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * [Companies]
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "linkedlist.h"

struct ListNode *
mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

struct ListNode *
mergeTwoLists2(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *h1 = l1;
    struct ListNode *h2 = l2;
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *curr = head;
    while (h1 && h2)
    {
        int val1 = h1->val;
        int val2 = h2->val;
        if (val1 < val2)
        {
            curr->next = h1;
            h1 = h1->next;
        }
        else
        {
            curr->next = h2;
            h2 = h2->next;
        }
        curr = curr->next;
    }
    while (h1)
    {
        curr->next = h1;
        h1 = h1->next;
        curr = curr->next;
    }
    while (h2)
    {
        curr->next = h2;
        h2 = h2->next;
        curr = curr->next;
    }
    return head->next;
}

typedef struct ListNode* (*ptr2mergeTwoLists2)(struct ListNode*, struct ListNode*);

void test(ptr2mergeTwoLists2 pfcn)
{
    // FIXME: Memory leak can happen. Being sloppy here.
    int a[] = {1,2,4};
    int b[] = {1,3,4};
    struct ListNode* l1 = list2list(a, 3);
    struct ListNode* l2 = list2list(b, 3);
    struct ListNode* head = (*pfcn)(l1->next,l2->next);
    struct ListNode* header = malloc(sizeof(struct ListNode));
    header->next = head;
    struct Result res = printList(header);
    int ans[] = {1,1,2,3,4,4};
    for(int i = 0; i < res.len; ++i)
    {
        assert(ans[i] == res.array[i]);
    }
}

int main()
{
    ptr2mergeTwoLists2 pfcn = &mergeTwoLists;
    test(pfcn);
    pfcn = &mergeTwoLists2;
    test(pfcn);
}
