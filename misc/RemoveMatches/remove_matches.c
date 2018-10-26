#include "remove_matches.h"
#include "stdlib.h"
#include "list.h"


/** COPIED FROM LIST.H FOR REFERENCE
 *
 * struct node{
 *  int val;
 *  struct node* next;
 *};
 */

/** remove_matches:
 * removes all list entries that match the supplied value
 * for example calling remove_matches on a list with {1, 3, 3, 4, 2, 5}
 * and a value of 3 should yield { 1, 4, 2, 5 }.
 *
 * remove_matches should have a void return type
 *
 * note that when an element is added to a list, the node to store it is created
 * on the heap
 *
 * please place any applicable function prototypes in remove_matches.h
 *
 * once you've implemented remove_matches, please go to main.c and insert a call to
 * your function in the proper place
 **/

// Ref: https://www.geeksforgeeks.org/delete-occurrences-given-key-linked-list/
void remove_matches(struct node** head, int target)
{
    // store the head node
    struct node* current = *head;
    struct node* prev;

    // If head node itself holds the key or multiple occurrences of key
    while(current != NULL && current->val == target)
    {
        *head = current->next;
        free(current);
        current = *head;
    }

    while(current)
    {
        // search for the key to be deleted, keep track of the previous node
        while  (current != NULL && current->val != target)
        {
            prev = current;
            current = current->next;
        }

        // If key was not present in the linked list
        if (current == NULL)
        {
            return;
        }

        prev->next = current->next;

        free(current);

        current = prev->next;
    }
}