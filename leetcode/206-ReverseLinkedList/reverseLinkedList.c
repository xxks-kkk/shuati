/*
 * [Source]
 * 
 * https://leetcode.com/problems/reverse-linked-list/
 *
 * [Problem Description]
 *
 * Reverse a singly linked list
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

// Approach 1: recursive approach
struct ListNode* reverseList(struct ListNode* head)
{
  if(head == NULL || head->next == NULL)
    return head;
  struct ListNode* L = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return L;
}

// Approach 2: iterative approach
struct ListNode* reverseList(struct ListNode* head)
{
  struct ListNode* current = head;
  struct ListNode* prev = NULL;
  struct ListNode* next;
  while(current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}
