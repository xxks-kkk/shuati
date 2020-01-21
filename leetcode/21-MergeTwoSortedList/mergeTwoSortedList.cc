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
#include <memory>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* sentinel = new ListNode(0);
      auto tail = sentinel;
      while(l1 && l2) {
        appendNode(l1->val < l2->val ? &l1 : &l2, &tail);
      }
      tail->next = (l1 ? l1 : l2);
      return sentinel->next;
    }
private:
  void appendNode(ListNode** node, ListNode** tail) {
    (*tail)->next = *node;
    *tail = *node;
    *node = (*node)->next;
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
