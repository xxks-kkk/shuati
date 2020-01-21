/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "cpputility.h"
#include "linkedList.h"
#include <vector>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* sentinel = new ListNode(0);
      auto ptr = sentinel;
      auto cur1 = l1, cur2 = l2;
      while(cur1 && cur2) {
        if (cur1->val < cur2->val) {
          ListNode* tmp = cur1->next;
          ptr->next = cur1;
          cur1->next = nullptr;
          ptr = cur1;
          cur1 = tmp;
        } else if (cur1->val == cur2->val) {
          ListNode* tmp1 = cur1->next;
          ListNode* tmp2 = cur2->next;
          ptr->next = cur1;
          ptr = cur1;
          ptr->next = cur2;
          ptr = cur2;
          cur1 = tmp1;
          cur2 = tmp2;
        } else {
          ListNode* tmp = cur2->next;
          ptr->next = cur2;
          cur2->next = nullptr;
          ptr = cur2;
          cur2 = tmp;
        }
      }
      if (cur1) {
        ptr->next = cur1;
      } else if (cur2) {
        ptr->next = cur2;
      }
      return sentinel->next;
    }
};

using ptr2mergeTwoLists = ListNode* (Solution::*)(ListNode*, ListNode*);

void test(ptr2mergeTwoLists pfcn) {
  Solution sol;
  LinkedList l;
  struct testCase {
    vector<int> l1;
    vector<int> l2;
    vector<int> expected;
  };
  vector<testCase> test_cases = {
    {{1,2,4}, {1,3,4}, {1,1,2,3,4,4}},
  };
  for(auto&& test_case: test_cases) {
    auto l1 = l.list2list(test_case.l1);
    auto l2 = l.list2list(test_case.l2);
    auto l_expected = l.list2list(test_case.expected);
    auto got = (sol.*pfcn)(l1, l2);
    if (!l.cmpTwoList(got, l_expected)) {
      printf("%s(%s,%s) = %s\n",
             "mergeTwoLists",
             CPPUtility::oneDVectorStr(test_case.l1).c_str(),
             CPPUtility::oneDVectorStr(test_case.l2).c_str(),
             CPPUtility::oneDVectorStr(l.printList(got)).c_str());
      assert(false);
    }
  }
}

int main() {
  ptr2mergeTwoLists pfcn = &Solution::mergeTwoLists;
  test(pfcn);
}
