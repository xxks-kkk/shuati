/*
 * [Source]
 * 
 * https://leetcode.com/problems/linked-list-cycle
 *
 * [Problem Description]
 *
 * Given a linked list, determine if it has a cycle in it. 
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

// The space complexity can be reduced to O(1)O(1)O(1) by considering
// two pointers at different speed - a slow pointer and a fast pointer.
// The slow pointer moves one step at a time while the fast pointer moves
// two steps at a time.
//
// If there is no cycle in the list, the fast pointer will eventually
// reach the end and we can return false in this case.
//
// Now consider a cyclic list and imagine the slow and fast pointers are
// two runners racing around a circle track.
// The fast runner will eventually meet the slow runner. Why?
// Consider this case (we name it case A) -
// The fast runner is just one step behind the slow runner.
// In the next iteration, they both increment one and two steps
// respectively and meet each other.
//
// How about other cases? For example,
// we have not considered cases where the fast runner is
// two or three steps behind the slow runner yet.
// This is simple, because in the next or next's next iteration,
// this case will be reduced to case A mentioned above.
bool hasCycle(struct ListNode *head)
{
  if(head == NULL || head->next == NULL)
    return false;
  struct ListNode* slow = head;
  struct ListNode* fast = head->next; // need b/c the while condition
  while(fast != slow)
  {
    if(fast == NULL || fast->next == NULL)
      return false;
    fast = fast->next->next;
    slow = slow->next;
  }
  return true;  
}

// My initial solution: work
bool hasCycle(struct ListNode *head)
{
  struct ListNode* player1 = head;
  struct ListNode* player2 = head;
  while(player1 != NULL && player2 != NULL)
  {
    player1 = player1->next;
    if(player2->next != NULL)
    {
      player2 = player2->next->next;
    }
    else
    {
      break;
    }
    if (player1 == player2)
    {
      return true;
      break;
    }
  }
  return false;
}
