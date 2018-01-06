# Given a list, rotate the list to the right by k places, where k is non-negative.
#
#
# Example:
#
# Given 1->2->3->4->5->NULL and k = 2,
#
# return 4->5->1->2->3->NULL.

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class LinkedList(object):
    def __init__(self, head=None):
        self.head = head

    def printList(self, head):
        elts = []
        while head:
            elts.append(head.val)
            head = head.next
        print elts

    def list2list(selfs, nums):
        """
        :param nums: list of numbers
        :return:  a linked list representation of the given list of numbers
        """
        nums.reverse()
        head = ListNode(0)
        for num in nums:
            head.next, head.next.next = ListNode(num), head.next
        return head.next

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not k or not head or not head.next:
            return head
        fast, slow = head, head
        list_len = 1
        while k > 0:
            k -= 1
            if fast.next:
                fast = fast.next
                list_len += 1
            else:
                fast = head
                k = k % list_len
        if fast == head:
            return head
        while fast.next:
            fast = fast.next
            slow = slow.next
        newHead = slow.next
        fast.next = head
        slow.next = None
        return newHead

if __name__ == "__main__":
    l = LinkedList()
    sol = Solution()

    head = l.list2list([1,2,3,4,5])
    l.printList(head)
    l.printList(sol.rotateRight(head, 2))

    head = l.list2list([1,2])
    l.printList(head)
    l.printList(sol.rotateRight(head, 2))
    l.printList(sol.rotateRight(head, 3))