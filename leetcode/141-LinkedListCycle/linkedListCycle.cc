/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "linkedList.h"

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head)
        {
            return false;
        }
        auto slow = head;
        auto fast = head->next;
        while(slow && fast && fast->next)
        {
            if (slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

using ptr2hasCycle = bool (Solution::*)(ListNode*);

void test(ptr2hasCycle pfcn)
{
    Solution sol;
    //TODO: add method in linkedList.h to construct circluar linked list
}

int main()
{
    ptr2hasCycle pfcn = &Solution::hasCycle;
    test(pfcn);
}