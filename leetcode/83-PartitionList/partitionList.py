# Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
#
# You should preserve the original relative order of the nodes in each of the two partitions.
#
# For example,
# Given 1->4->3->2->5->2 and x = 3,
# return 1->2->2->4->3->5.

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
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        list1 = curr1 = ListNode(0)
        list2 = curr2 = ListNode(0)
        curr = head
        while curr:
            if curr.val < x:
                curr1.next = curr
                curr1 = curr1.next
            else:
                curr2.next = curr
                curr2 = curr2.next
            curr = curr.next
        curr2.next = None
        curr1.next = list2.next
        return list1.next

if __name__ == "__main__":
    sol = Solution()
    l = LinkedList()
    head = l.list2list([1,4,3,2,5,2])
    l.printList(sol.partition(head, 3))