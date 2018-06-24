#include "linkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

// Difference between "->" and ".":
// "->" for accessing object member variables and methods via pointer to object
// "." for accessing object member variables and methods via object instance
// https://stackoverflow.com/questions/11902791/what-is-the-difference-between-and-in-c
ListNode *
LinkedList::
list2list(std::vector<int> nums)
{
    ListNode head = ListNode(0);
    for (auto riter = nums.rbegin(); riter != nums.rend(); ++riter)
    {
        auto tmp = new ListNode(*riter);
        tmp->next = head.next;
        head.next = tmp;
    }
    return head.next;
}

std::vector<int>
LinkedList::
printList(ListNode *head)
{
    std::vector<int> elts;
    while (head)
    {
        elts.push_back(head->val);
        head = head->next;
    }
    return elts;
}

void
::LinkedList::freeList(ListNode *&head)
{
    if (head == nullptr)
    {
        return;
    }
    freeList(head->next);
    delete (head);
}