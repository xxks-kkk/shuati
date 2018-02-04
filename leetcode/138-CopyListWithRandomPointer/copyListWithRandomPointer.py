# A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
#
# Return a deep copy of the list.

# Definition for singly-linked list with a random pointer.
class RandomListNode(object):
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head:
            return None
        dict = {}
        res = RandomListNode(head.label)
        dict[head] = res
        node = res
        curr = head.next
        while curr:
            tmp = RandomListNode(curr.label)
            node.next = tmp
            dict[curr] = tmp
            curr = curr.next
            node = node.next
        curr = head
        node = res
        while curr:
            node.random = dict[curr.random] if curr.random else None
            curr = curr.next
            node = node.next
        return res

    def copyRandomList2(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        curr = next = head
        while curr:
            next = curr.next
            tmp = RandomListNode(curr.label)
            curr.next = tmp
            tmp.next = next
            curr = next
        curr = head
        while curr:
            if curr.random:
                curr.next.random = curr.random.next
            curr = curr.next.next
        dummy = RandomListNode(0)
        curr = head
        dummy_curr = dummy
        while curr:
            tmp = curr.next
            dummy_curr.next = tmp
            dummy_curr = dummy_curr.next
            curr.next = curr.next.next
            curr = curr.next
        return dummy.next