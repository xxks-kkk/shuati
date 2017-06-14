/*
 * [Source]
 * 
 * https://leetcode.com/problems/remove-linked-list-elements
 *
 * [Problem Description]
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 * [Comments]
 *
 * Be careful with corner case: [1], val = 1
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
struct ListNode* removeElements(struct ListNode* head, int val) {
  while(head && head->val == val)
    head = head->next;
  struct ListNode* curr;
  struct ListNode* prev;
  curr = prev = head;
  while(curr != NULL)
  {
    if(curr->val == val)
    {
      prev->next = curr->next;
      free(curr);
      curr = prev->next;
    }
    else
    {
      prev = curr;
      curr = curr->next;
    }
  }
  return head;
}
