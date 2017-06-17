/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/linked-list-cycle-ii/#/description
 *          
 * [Problem Description]
 *          
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Note: Do not modify the linked list.
 * Follow up:
 * Can you solve it without using extra space?
 *          
 * [Comments]
 *          
 * The algorithm used is called [Floyd's Tortoise and Hare](https://en.wikipedia.org/wiki/Cycle_detection#Floyd.27s_Tortoise_and_Hare)
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
struct ListNode *detectCycle(struct ListNode *head) {
  if(head == NULL || head->next == NULL)
    return NULL;

  struct ListNode *tortoise;
  struct ListNode *hare;
  struct ListNode *curr;

  tortoise = hare = curr = head;

  while(hare != NULL && hare->next != NULL)
  {
    hare = hare->next->next;
    tortoise = tortoise->next;
    if (hare == tortoise)  // there is a cycle
    {
      while(curr != tortoise)
      {
        curr = curr->next;
        tortoise = tortoise->next;
      }
      return curr;  // find the entry location
    }
  }
  return NULL; // there is no cycle
}

