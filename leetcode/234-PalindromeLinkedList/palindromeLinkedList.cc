#include <cassert>
#include "linkedList.h"

// Primer: (p.785)
// namespace provde a mechanism for preventing name collisions.
using namespace std;

class Solution
{
public:
    bool
    isPalindrome(ListNode *head)
    {
        auto head_pointer = head;
        auto tail_pointer = head;
        return check(head_pointer, tail_pointer);
    }

    bool
    isPalindrome2(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        // Two pointers way to "split" the list in half
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow)
        {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }

private:
    bool
    check(ListNode *&head_pointer, ListNode *&tail_pointer)
    {
        if (head_pointer == nullptr || tail_pointer == nullptr)
        {
            return true;
        }
        bool isPal = check(head_pointer, tail_pointer->next) & (head_pointer->val == tail_pointer->val);
        if (!isPal)
        {
            return false;
        }
        head_pointer = head_pointer->next;
        return isPal;
    }

    ListNode *
    reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while (head)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

using ptr2isPalindrome = bool (Solution::*)(ListNode *);

void
test(ptr2isPalindrome pfcn)
{
    Solution sol;
    LinkedList l;
    vector<int> nums = {1, 2, 3};
    auto head = l.list2list(nums);
    for (auto i: l.printList(head))
    {
        cout << i << " ";
    }
    cout << endl;
    assert(!(sol.*pfcn)(head));
    l.freeList(head);
}

int
main()
{
    ptr2isPalindrome pfcn = &Solution::isPalindrome;
    test(pfcn);
    pfcn = &Solution::isPalindrome2;
    test(pfcn);
}