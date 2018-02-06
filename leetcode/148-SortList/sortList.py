# Sort a linked list in O(n log n) time using constant space complexity.

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
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def merge(L1, L2):
            dummy = ListNode(0)
            curr = dummy
            curr1 = L1
            curr2 = L2
            while curr1 and curr2:
                if curr1.val < curr2.val:
                    curr.next = curr1
                    curr1 = curr1.next
                    curr = curr.next
                else:
                    curr.next = curr2
                    curr2 = curr2.next
                    curr = curr.next
            if curr1:
                curr.next = curr1
            if curr2:
                curr.next = curr2
            return dummy.next
        if not head or not head.next:
            return head

        # step 1. cut the list to two halves
        tortoise = head
        hare = head.next
        while hare and hare.next:
            hare = hare.next.next
            tortoise = tortoise.next
        L = tortoise.next
        tortoise.next = None

        # step 2. sort each half
        L1 = self.sortList(head)
        L2 = self.sortList(L)

        # step 3. merge l1 and l2
        return merge(L1,L2)

if __name__ == "__main__":
    sol = Solution()
    l = LinkedList()
    head = l.list2list([1,7,3,5,4])
    head_sorted = sol.sortList(head)
    l.printList(head_sorted)
    head = l.list2list([2,1])
    head_sorted = sol.sortList(head)
    l.printList(head_sorted)