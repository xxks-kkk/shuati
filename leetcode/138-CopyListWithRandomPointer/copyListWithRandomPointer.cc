#include "linkedList_rand.h"
#include "cpputility.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
  // Brute force approach
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    unordered_map<Node*, Node*> m;
    // We first create the linked list
    auto res = new Node(head->val, nullptr, nullptr);
    m[head] = res;
    auto cur_o = head->next;
    auto cur_n = res;
    while (cur_o) {
      auto node  = new Node(cur_o->val, nullptr, nullptr);
      cur_n->next = node;
      m[cur_o] = node;
      cur_n = cur_n->next;
      cur_o = cur_o->next;
    }
    // Add the random pointers
    cur_o = head, cur_n = res;
    while(cur_o) {
      cur_n->random = m[cur_o->random];
      cur_o = cur_o->next;
      cur_n = cur_n->next;
    }
    return res;
  }
  // Optimized approach (EPI p.446)
  Node* copyRandomList2(Node* head) {
    if (head == nullptr) return nullptr;
    // Stage 1: Makes a copy of the original list without assigning the random
    //          field, and creates the mapping for each node in the original list
    //          to the copied list
    auto iter = head;
    while (iter) {
      auto new_node = new Node(iter->val, iter->next, nullptr);
      iter->next = new_node;
      iter = new_node->next;
    }

    // Stage 2: Assigns the random field in the copied list
    iter = head;
    while(iter) {
      if (iter->random) {
        iter->next->random = iter->random->next;
      }
      iter = iter->next->next;
    }

    // Stage 3: Reverts the original list, and assigns the next field of the copied list
    iter = head;
    auto new_list_head = iter->next;
    while(iter->next) {
      auto temp = iter->next;
      iter->next = temp->next;
      iter = temp;
    }
    return new_list_head;
  }  
};

using ptr2copyRandomList = Node* (Solution::*)(Node*);

struct testFuncsInfo {
  ptr2copyRandomList pfcn;
  const char* pfcn_name;
};

void test(ptr2copyRandomList pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    string input;
  };
  vector<testCase> test_cases = {
    {R"({"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1})"},
  };
  for(auto&& test_case: test_cases) {
    auto head = LinkedListRandom::list2list(test_case.input);
    auto new_head = (sol.*pfcn)(head);
    auto new_head_repr = LinkedListRandom::printList(new_head);
    if (new_head_repr != test_case.input) {
      printf("%s(%s) = %s\n",
             pfcn_name,
             test_case.input.c_str(),
             new_head_repr.c_str());
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::copyRandomList)
    FUNC_DEF(&Solution::copyRandomList2)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
