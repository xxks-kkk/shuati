# Reverse a linked list from position m to n. Do it in-place and in one-pass.
#
# For example:
# Given 1->2->3->4->5->NULL, m = 2 and n = 4,
#
# return 1->4->3->2->5->NULL.
#
# Note:
# Given m, n satisfy the following condition:
# 1 <= m <= n <= length of list.


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
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if not head: return head
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        for _ in range(m-1): prev = prev.next
        curr = prev.next
        next = curr.next
        for _ in range(n-m):
            curr.next = next.next
            next.next = prev.next
            prev.next = next
            next = curr.next
        return dummy.next


if __name__ == "__main__":
    sol = Solution()
    l = LinkedList()
    head = l.list2list([1,2,3,4,5])
    l.printList(head)
    l.printList(sol.reverseBetween(head,2,4))