/*
 * [Source]
 * 
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 * [Problem Description]
 *
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 * [Comments]
 *
 * The solution correctness heavily relies on the given linked list is sorted.
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
deleteDuplicates(struct ListNode* head)
{
  struct ListNode *curr, *tmp;
  curr = head;
  while(curr != NULL && curr->next != NULL)
  {
    if(curr->val == curr->next->val)
    {
      tmp = curr->next;
      curr->next = curr->next->next;
      free(tmp);
    }
    else
      curr = curr->next;
  }
  return head;
}
