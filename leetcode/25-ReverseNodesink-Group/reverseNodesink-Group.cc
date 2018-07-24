//    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//    Example:
//
//    Given this linked list: 1->2->3->4->5
//
//    For k = 2, you should return: 2->1->4->3->5
//
//    For k = 3, you should return: 3->2->1->4->5
//
//    Note:
//
//    Only constant extra memory is allowed.
//    You may not alter the values in the list's nodes, only nodes itself may be changed.

#include "linkedList.h"
#include <cassert>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *
    reverseKGroup(ListNode *head, int k)
    {
        auto node = head;
        for(int i = 0; i < k; ++i)
        {
            if (node == nullptr)
            {
                return head;
            }
            node = node->next;
        }
        auto new_head = reverseLinkedList(head, node);
        head->next = reverseKGroup(node, k);
        return new_head;
    }
private:
    ListNode*
    reverseLinkedList(ListNode *head, ListNode* end)
    {
        auto current = head;
        ListNode* next;
        // This line is important. That is how we still hold
        // the rest of the list after reversing: k = 2, 1->2->3->4->5
        // we get 2->1->3->4->5
        auto prev = end;
        while (current != end)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

using ptr2reverseKGroup = ListNode * (Solution::*)(ListNode*, int);

void test(ptr2reverseKGroup pfcn)
{
    Solution sol;
    LinkedList l;
    std::vector<int> nums = {1,2,3,4,5};
    auto head = l.list2list(nums);
    std::vector<int> ans = {2,1,4,3,5};
    assert(l.printList((sol.*pfcn)(head, 2)) == ans);
    head = l.list2list(nums);
    ans = {3,2,1,4,5};
    assert(l.printList((sol.*pfcn)(head, 3)) == ans);
}

int main()
{
    ptr2reverseKGroup pfcn = &Solution::reverseKGroup;
    test(pfcn);
}
