# Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
#
# For example,
# Given 1->2->3->3->4->4->5, return 1->2->5.
# Given 1->1->1->2->3, return 2->3.

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
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy, i = ListNode(0), head
        end = dummy
        dummy.next = head
        while i and i.next:
            if i.val == i.next.val:
                while i and i.next and i.val == i.next.val:
                    i = i.next
                i = i.next
                end.next = i
            else:
                end = end.next
                i = i.next
        return dummy.next

if __name__ == "__main__":
    sol = Solution()
    l = LinkedList()

    head = l.list2list([1,1])
    l.printList(sol.deleteDuplicates(head)) # []

    head = l.list2list([1,2,3,3,4,4,5])
    l.printList(sol.deleteDuplicates(head)) # [1,2,5]

    head = l.list2list([1,1,1,2,3])
    l.printList(sol.deleteDuplicates(head)) # [2,3]

