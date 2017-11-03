 # [Source] 
 #          
 # https://leetcode.com/problems/add-two-numbers-ii/
 #          
 # [Problem Description]
 #          
 # You are given two non-empty linked lists representing two non-negative
 # integers. The most significant digit comes first and each of their nodes
 # contain a single digit. Add the two numbers and return it as a linked list.
 # You may assume the two numbers do not contain any leading zero, except the
 # number 0 itself.
 # Follow up:
 # What if you cannot modify the input lists? In other words, reversing the lists
 # is not allowed.
 # Example:
 # Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 # Output: 7 -> 8 -> 0 -> 7
 #          
 # [Comments]
 #          
 # 1. Use "collections.deque()" to implement Queue on Leetcode. Leetcode doesn't support Queue()
 #    Here, I used it as stack. List can also be used as stack.
 #          
 # [Companies]
 # Bloomberg

import collections

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

    def num2List(self, x):
        head = ListNode(0)
        while x:
            quotient, remainder = x / 10, x % 10
            head.next, head.next.next = ListNode(remainder), head.next
            x = x / 10
        return head.next

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # The idea is to use a stack for each list then we can keep pop the stacks and do the addition and append the
        # result to the result list
        q1 = collections.deque()
        q2 = collections.deque()
        head = ListNode(0)
        while l1:
            q1.append(l1.val)
            l1 = l1.next
        while l2:
            q2.append(l2.val)
            l2 = l2.next
        carry = 0
        while (q1 or q2):
            x1 = 0 if not q1 else q1.pop()
            x2 = 0 if not q2 else q2.pop()
            res = x1 + x2 + carry
            carry, remainder = res/10, res % 10
            node = ListNode(remainder)
            node.next = head.next
            head.next = node
        if carry == 1:
            # Without this code, [5] + [5] = [0] instead of [1,0]
            node = ListNode(carry)
            node.next = head.next
            head.next = node
        return head.next

if __name__ == "__main__":
    x1 = 5
    x2 = 5
    l = LinkedList()
    l1 = l.num2List(x1)
    l2 = l.num2List(x2)
    l.printList(l1)
    l.printList(l2)
    l.printList(l.addTwoNumbers(l1, l2))