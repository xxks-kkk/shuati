/*
 * [Source]
 * 
 * https://leetcode.com/problems/delete-node-in-a-linked-list/
 *
 * [Problem Description]
 *
 * Write a function to delete a node (except the tail) 
 * in a singly linked list, given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and 
 * you are given the third node with value 3, 
 * the linked list should become 1 -> 2 -> 4 after calling your function. 
 *
 * [Companies]
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// The usual way of deleting a node node from a linked list is
// to modify the next pointer of the node before it, to point to the node after it.
//
// Since we do not have access to the node before the one we want to delete,
// we cannot modify the next pointer of that node in any way.
// Instead, we have to replace the value of the node we want to delete with
// the value in the node after it, and then delete the node after it.
//
// Because we know that the node we want to delete is not the tail of the list,
// we can guarantee that this approach is possible.
void
deleteNode(struct ListNode *node)
{
    struct ListNode *ptr = node->next;
    node->val = ptr->val;
    node->next = ptr->next;
    free(ptr);
}

// We can't really delete the node, but we can kinda achieve the same effect by
// instead removing the next node after copying its data into the node that we were asked to delete.
// https://leetcode.com/problems/delete-node-in-a-linked-list/discuss/65455/1-3-lines-C%2B%2BJavaPythonCCJavaScriptRuby
void
deleteNode(struct ListNode *node)
{
    // node->next is the pointer to the next node
    // *node->next (i.e. *(node->next)) access the content of that node.
    // *node = *node->next: copy the content of the next node to the current node
    *node = *node->next;
}

// My initial solution: work but ugly
void
deleteNode(struct ListNode *node)
{
    struct ListNode *ptr = node;
    struct ListNode *tmp;
    while (ptr->next != NULL)
    {
        ptr->val = ptr->next->val;
        if (ptr->next->next == NULL)
        {
            tmp = ptr->next;
            ptr->next = NULL;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    free(tmp);
}
