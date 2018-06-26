//    Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
//
//    You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//    The digits are stored such that the most significant digit is at the head of the list.
//
//    Example:
//    Input:
//    1->2->3
//
//    Output:
//    1->2->4

#include "linkedList.h"
#include <vector>
#include <cassert>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int next = 1;
        plusOneHelper(head, next);
        if (next == 1)
        {
            auto newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        else
        {
            return head;
        }
    }
private:
    void plusOneHelper(ListNode* head, int & next)
    {
        if(head == nullptr)
        {
            return;
        }
        plusOneHelper(head->next, next);
        head->val = (head->val + next) % 10;
        if (head->val > 0)
            next = 0;
    }
};

using ptr2plusOne = ListNode* (Solution::*)(ListNode*);

void test(ptr2plusOne pfcn)
{
    Solution sol;
    LinkedList l;
    std::vector<int> nums = {1,2,3};
    auto head = l.list2list(nums);
    auto new_head = (sol.*pfcn)(head);
    std::vector<int> ans = {1,2,4};
    assert(l.printList(new_head) == ans);
    l.freeList(new_head);
}

int main()
{
    ptr2plusOne pfcn = &Solution::plusOne;
    test(pfcn);
}