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

// To detect if a list is cyclic, we can check whether a node
// had been visited before. A natural way is to use a hash table.
//
// We go through each node one by one and record
// each node's reference (or memory address) in a hash table.
// If the current node is null, we have reached the end of the list
// and it must not be cyclic.
// If current node’s reference is in the hash table, then return true.
//
//
// Time : O(n)
//        We visit each of the n elements in the list at most once.
//        Adding a node to the hash table costs only O(1) time.
//
// Space : O(n)
//         The space depends on the number of elements added to the hash table,
//         which contains at most nnn elements.
public boolean hasCycle(ListNode head)
{
  Set<ListNode> nodesSeen = new HashSet<>();
  while (head != null)
  {
    if (nodesSeen.contains(head))
    {
      return true;
    }
    else
    {
      nodesSeen.add(head);
    }
    head = head.next;
  }
  return false;
}
