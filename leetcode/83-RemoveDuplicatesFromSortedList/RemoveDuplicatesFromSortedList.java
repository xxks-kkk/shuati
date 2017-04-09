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
 * [Companies]
 */


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


// Below solution doesn't utilitze the information !!sorted!! linked list.
// It treats the problem like 1-TwoSum. This is not good enough.
public class Solution {
  public ListNode deleteDuplicates(ListNode head) {
    HashMap<Integer, Integer> dict = new HashMap<>();
    ListNode curr = head;
    ListNode prev = head;
    while(curr != null)
    {
      if(dict.containsKey(curr.val))
      {
        prev.next = curr.next;
        curr = curr.next;
      }
      else
      {
        dict.put(curr.val, 1);
        prev = curr;
        curr = curr.next;
      }
    }
    return head;
  }
}
