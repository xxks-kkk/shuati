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

// The space complexity can be reduced to O(1) by considering
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

// Time  : O(n).
//         Let us denote n as the total number of nodes in the linked list.
//         To analyze its time complexity, we consider the following two cases separately.
//         - List has no cycle:
//           The fast pointer reaches the end first and
//           the run time depends on the list's length, which is O(n).
//         - List has a cycle:
//           We break down the movement of the slow pointer into two steps,
//           the non-cyclic part and the cyclic part:
//
//           1. The slow pointer takes "non-cyclic length" steps to enter the cycle.
//           At this point, the fast pointer has already reached the cycle.
//           Number of iterations=non-cyclic length=N
//
//           2. Both pointers are now in the cycle.
//           Consider two runners running in a cycle - the fast runner moves 2
//           steps while the slow runner moves 1 steps at a time.
//           Since the speed difference is 1, it takes
//           \frac{distance between the 2 runners|}{difference of speed} loops
//           for the fast runner to catch up with the slow runner.
//           As the distance is at most "cyclic length K" and the
//           speed difference is 1, we conclude that
//           Number of iterations=almost ‘‘cyclic length K".
// 
//         Therefore, the worst case time complexity is O(N+K), which is O(n).
//
// Space : O(1).
//         We only use two nodes (slow and fast) so the space complexity is O(1)
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

// 06/17/17: I like this version
bool hasCycle(struct ListNode *head) {
  if (head == NULL || head->next == NULL)
    return false;

  struct ListNode *tortoise;
  struct ListNode *hare;

  tortoise = hare = head;

  while(hare != NULL && hare->next != NULL)
  {
    hare = hare->next->next;
    tortoise = tortoise->next;
    if (hare == tortoise) return true;
  }
  return false;
}
