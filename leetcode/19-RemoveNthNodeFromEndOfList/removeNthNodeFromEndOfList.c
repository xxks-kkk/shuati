/*
 * [Source]
 * 
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * [Problem Description]
 *
 * Given a linked list, remove the nth node from the end of list and 
 * return its head.
 *
 * Ex:
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 *
 * Given n will always be valid.
 * Try to do this in one pass. 
 *
 * [Comments]
 *
 * 1. Two pass routine is trivial. We first walk through the list to find out
 *    its lenght. Then, we start from the beginning and count towards the nth
 *    node from the end of list and remove it.
 *
 * 2. One pass routine is easy to think but hard to code right. We could use 
 *    two pointers. The first pointer advances the list by n+1 steps from 
 *    the beginning, while the second pointer starts from the beginning 
 *    of the list. Now, both pointers are exactly separated by n nodes apart. 
 *    We maintain this constant gap by advancing both pointers together until 
 *    the first pointer arrives past the last node. 
 *    The second pointer will be pointing at the nth node counting from the last. 
 *    We relink the next pointer of the node referenced by 
 *    the second pointer to point to the node's next next node.
 *
 *    Several programming details need to pay attention: 
 *    1. dummy is necessary. It is used to handle list: [1] n: 1 case.
 *    2. n+1 apart is necessary Not n. This is because if n apart, once the first
 *       pointer reaches NULL at end of the list, the second pointer will at the
 *       {n-1}th node from the end of list NOT nth.
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

struct ListNode*
removeNthFromEnd(struct ListNode* head,
                 int n)
{
  struct ListNode *first, *second, *dummy, *tmp;
  dummy = malloc(sizeof(struct ListNode));
  dummy->next = head;
  first = second = dummy;
  int i;
  for(i = 0; i <= n; i++)
    first = first->next;
  while(first != NULL)
  {
    first = first->next;
    second = second->next;
  }
  tmp = second->next;
  second->next = second->next->next;
  free(tmp);
  return dummy->next;
}
