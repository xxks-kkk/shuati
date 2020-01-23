//    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
//    Example:
//
//    Input:
//    [
//    1->4->5,
//    1->3->4,
//    2->6
//    ]
//    Output: 1->1->2->3->4->4->5->6

#include "linkedList.h"
#include <cassert>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool heapCmp(ListNode *a, ListNode *b)
{
  return a->val > b->val;
}

class Solution
{
public:
  // Approach 1: priority_queue
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    // EPI p.167
    priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>>
        min_heap([](ListNode *a, ListNode *b) { return a->val > b->val; });
    for (auto &l : lists)
    {
      if (l)
      {
        min_heap.push(l);
      }
    }
    if (min_heap.empty())
    {
      return nullptr;
    }
    auto head = min_heap.top();
    min_heap.pop();
    if (head->next)
    {
      min_heap.push(head->next);
    }
    auto current = head;
    while (!min_heap.empty())
    {
      auto element = min_heap.top();
      min_heap.pop();
      current->next = element;
      if (element->next)
      {
        min_heap.push(element->next);
      }
      current = current->next;
    }
    return head;
  }

  // Approach 2: heap
  ListNode *mergeKLists2(vector<ListNode *> &lists)
  {
    auto head = new ListNode(0);
    auto current = head;
    vector<ListNode *> tmp;
    for (auto &l : lists)
    {
      if (l)
      {
        tmp.push_back(l);
      }
    }
    make_heap(tmp.begin(), tmp.end(), heapCmp);
    while (!tmp.empty())
    {
      current->next = tmp.front();
      // pop_heap doesn't remove element: it simply move the top element of the heap to the
      // end of vector, which we need to call pop_back
      pop_heap(tmp.begin(), tmp.end(), heapCmp);
      tmp.pop_back();
      current = current->next;
      if (current->next)
      {
        tmp.push_back(current->next);
        push_heap(tmp.begin(), tmp.end(), heapCmp);
      }
    }
    return head->next;
  }

  // Approach 3: Divide-and-conquer
  ListNode *mergeKLists3(vector<ListNode *> &lists)
  {
    if (lists.empty())
    {
      return nullptr;
    }
    while (lists.size() > 1)
    {
      lists.push_back(mergeTwoLists(lists[0], lists[1]));
      lists.erase(lists.begin());
      lists.erase(lists.begin());
    }
    return lists.front();
  }

private:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    if (l1 == nullptr)
    {
      return l2;
    }
    if (l2 == nullptr)
    {
      return l1;
    }
    if (l1->val <= l2->val)
    {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    }
    else
    {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};

using ptr2mergeKLists = ListNode *(Solution::*)(vector<ListNode *> &);

void test(ptr2mergeKLists pfcn)
{
  Solution sol;
  LinkedList l;
  vector<ListNode *> example;
  vector<int> nums = {1, 4, 5};
  example.push_back(l.list2list(nums));
  nums = {1, 3, 4};
  example.push_back(l.list2list(nums));
  nums = {2, 6};
  example.push_back(l.list2list(nums));
  vector<int> ans = {1, 1, 2, 3, 4, 4, 5, 6};
  auto head = (sol.*pfcn)(example);
  assert(l.printList(head) == ans);
  l.freeList(head);
}

int main()
{
  ptr2mergeKLists pfcn = &Solution::mergeKLists;
  test(pfcn);
  pfcn = &Solution::mergeKLists2;
  test(pfcn);
  pfcn = &Solution::mergeKLists3;
  test(pfcn);
}
