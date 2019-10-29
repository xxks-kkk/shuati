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
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }  
}
