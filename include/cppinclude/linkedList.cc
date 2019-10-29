#include "linkedList.h"

// Use "Pointer to implementation" or "Pimpl" design pattern: https://en.cppreference.com/w/cpp/language/pimpl

class LinkedList::Impl
{
public:
    Impl() = default;

    ListNode *
    list2list(const std::vector<int> &nums)
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
    printList(ListNode* &head)
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
    freeList(ListNode *&head)
    {
        if (head == nullptr)
        {
            return;
        }
        freeList(head->next);
        delete (head);
    }
};

LinkedList::LinkedList(): pImpl{new Impl}{};

LinkedList::~LinkedList() = default;

ListNode *
LinkedList::list2list(const std::vector<int> &nums)
{
    return pImpl->list2list(nums);
}

std::vector<int>
LinkedList::printList(ListNode *head)
{
    return pImpl->printList(head);
}

void
LinkedList::freeList(ListNode *&head)
{
    pImpl->freeList(head);
}















