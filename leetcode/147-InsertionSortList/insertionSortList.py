# Sort a linked list using insertion sort.

# Definition for singly-linked list.
class ListNode(object):
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

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        dummy = ListNode(0)
        curr = head
        prev = dummy
        next = None
        while curr:
            next = curr.next
            if not prev or not prev.next or prev.next.val >= curr.val:
                prev = dummy
            while prev.next and prev.next.val < curr.val:
                prev = prev.next
            curr.next = prev.next
            prev.next = curr
            curr = next
        return dummy.next

if __name__ == "__main__":
    sol = Solution()
    l = LinkedList()
    head = l.list2list([1,7,3,5,4])
    head_sorted = sol.insertionSortList(head)
    l.printList(head_sorted)
    head = l.list2list([2,1])
    head_sorted = sol.insertionSortList(head)
    l.printList(head_sorted)