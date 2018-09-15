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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto ptr1 = l1;
        auto ptr2 = l2;
        int carry = 0;
        ListNode* header = new ListNode(0);
        auto curr = header;
        while(ptr1 || ptr2)
        {
            int val1 = (ptr1) ? ptr1->val : 0;
            int val2 = (ptr2) ? ptr2->val : 0;
            int sum = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            curr->next = new ListNode(sum);
            ptr1 = (ptr1) ? ptr1->next : nullptr;
            ptr2 = (ptr2) ? ptr2->next : nullptr;
            curr = curr->next;
        }
        if (carry > 0)
        {
            curr->next = new ListNode(carry);
        }
        return header->next;
    }
};

using ptr2addTwoNumbers = ListNode* (Solution::*)(ListNode*, ListNode*);

void test(ptr2addTwoNumbers pfcn)
{
    Solution sol;
    LinkedList l;
    std::vector<int> nums = {2,4,3};
    auto head1 = l.list2list(nums);
    std::vector<int> nums2 = {5,6,4};
    auto head2 = l.list2list(nums2);
    auto ans = sol.addTwoNumbers(head1, head2);
    std::vector<int> ans_list = l.printList(ans);
    std::vector<int> ref_list = {7,0,8};
    assert(ans_list == ref_list);
    l.freeList(head1);
    l.freeList(head2);
}

int main()
{
    ptr2addTwoNumbers pfcn = &Solution::addTwoNumbers;
    test(pfcn);
}