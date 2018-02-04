# Given a singly linked list L: L0->L1-> ... ->Ln-1->Ln,
# reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2-> ...
#
# You must do this in-place without altering the nodes' values.
#
# For example,
# Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        def reverseList(head):
            if not head:
                return head
            curr = head
            prev = None
            while curr:
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next
            return prev

        if not head or not head.next:
            return

        # find the middle point (pointed by tortoise) of the list
        hare = head.next
        tortoise = head
        while hare and hare.next:
            hare = hare.next.next
            tortoise = tortoise.next
        L = tortoise.next
        tortoise.next = None

        # reverse the list starting with the node pointed by tortoise until the end of the list
        # 1->2->3(tortoise),(L)4->5->6 to 1->2->3(tortoise),(L)6->5->4
        L = reverseList(L)

        # Start reorder one by one  (head)1->2->3(tortoise),(L)6->5->4 to (head)1->6->2->5->3->4
        curr_1 = head
        curr_2 = L
        while curr_1 and curr_2:
            next_1 = curr_1.next
            next_2 = curr_2.next
            curr_1.next = curr_2
            curr_2.next = next_1
            curr_1 = next_1
            curr_2 = next_2

if __name__ == "__main__":
    sol = Solution()
    l = LinkedList()
    head = l.list2list([1,2,3,4])
    sol.reorderList(head)
    l.printList(head)
    head = l.list2list([1,2])
    sol.reorderList(head)
    l.printList(head)
    head = l.list2list([1,2,3,4,5,6,7])
    sol.reorderList(head)
    l.printList(head)