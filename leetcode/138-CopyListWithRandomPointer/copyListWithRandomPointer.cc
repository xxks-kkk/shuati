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
  // TODO: See #167
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::copyRandomList)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }  
}
