#include "iostream"
#include "vector"
#include "assert.h"

// Primer: (p.785)
// namespace provde a mechanism for preventing name collisions.
using namespace std;

// Primer: The only difference between using "class" and using "struct"
// to define a class is the default access level ("class": default private;
// "struct": default public (p.269)
struct ListNode {
    int val;
    ListNode *next;

    // Primer: constructor initializer list (p.265)
    // specifies initial values for one or more data members of the object being created.
    // The constructor initializer is a list of member names, each of which is followed by that member's
    // initial value in parentheses. Multiple member initializations are separated by commas.
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedList {
private:
    ListNode *head;
public:
    LinkedList() {
      head = nullptr;
    }

    // Difference between "->" and ".":
    // "->" for accessing object member variables and methods via pointer to object
    // "." for accessing object member variables and methods via object instance
    // https://stackoverflow.com/questions/11902791/what-is-the-difference-between-and-in-c
    ListNode *list2list(vector<int> *nums) {
      reverse(nums->begin(), nums->end());
      ListNode head = ListNode(0);
      for (int i = 0; i < nums->size(); i++) {
        ListNode *tmp = new ListNode((*nums)[i]);
        tmp->next = head.next;
        head.next = tmp;
      }
      return head.next;
    }

    vector<int> printList(ListNode *head) {
      vector<int> elts;
      while (head) {
        elts.push_back((*head).val);
        head = head->next;
      }
      return elts;
    }
};

class Solution {
public:
    ListNode *tmp;
    bool isPalindrome(ListNode *head) {
      tmp = head;
      return check(tmp);
    }

    bool check(ListNode *p){
      if (p == NULL) return true;
      bool isPal = check(p->next) & (tmp->val == p->val);
      if (!isPal) return false;
      tmp = tmp->next;
      return isPal;
    }

    bool isPalindrome2(ListNode *head){
      if (!head || !head->next)
        return true;
      ListNode *slow = head;
      ListNode *fast = head;
      // Two pointers way to "split" the list in half
      while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
      }
      slow->next = reverseList(slow->next);
      slow = slow->next;
      while(slow){
        if (head->val != slow->val)
          return false;
        head = head->next;
        slow = slow->next;
      }
      return true;
    }

    ListNode* reverseList(ListNode* head){
      ListNode* pre = NULL;
      ListNode* next = NULL;
      while(head){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
      }
      return pre;
    }
};

int main() {
  Solution sol;
  vector<int> nums = {1,2,3};
  LinkedList l = LinkedList();
  ListNode *head = l.list2list(&nums);
  for(auto i: l.printList(head)){
    cout << i << " ";
  }
  cout << endl;
  assert(sol.isPalindrome(head) == 0);
  assert(sol.isPalindrome2(head) == 0);
}