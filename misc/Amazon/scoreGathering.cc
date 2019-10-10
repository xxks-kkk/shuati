#include "cpputility.h"
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int key;
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : key(x), val(1), left(nullptr), right(nullptr) {}
};

void insert(TreeNode* & root, int key) {
  if (root == nullptr) {
    root = new TreeNode(key);
  } else if (key == root->key) {
    root->val++;
  } else if (key > root->key) {
    insert(root->right, key);
  } else if (key < root->key) {
    insert(root->left, key);
  }
}

TreeNode* list2Tree(const std::vector<int> & nums) {
  TreeNode* root = nullptr;
  for (auto&& x: nums)
  {
    insert(root, x);
  }
  return root;    
}

// NOTE: the output format & structure may be different
// (e.g., output "4:2,2:1,..." instead of `vector<pair<int,int>>`
vector<pair<int,int>> scoreGathering(vector<int>& array) {
  auto root = list2Tree(array);
  // BFS
  vector<pair<int,int>> res;
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()) {
    auto node = q.front(); q.pop();
    res.push_back({node->key, node->val});
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }
  return res;
}

using ptr2scoreGathering = vector<pair<int,int>> (*)(vector<int>&);

void test(ptr2scoreGathering pfcn , const char* pfcn_name) {
  struct testCase {
    vector<int> array;
    vector<pair<int,int>> expected;
  };
  vector<testCase> test_cases = {
    {{{4, 2, 5, 5, 6, 1, 4},
      {{4,2},{2,1},{5,2},{1,1},{6,1}}}},
  };
  for(auto&& test_case: test_cases) {
    auto got = (*pfcn)(test_case.array);
    if (got != test_case.expected) {
      printf("%s(%s) = %s\n",
             pfcn_name,
             CPPUtility::oneDVectorStr<int>(test_case.array).c_str(),
             CPPUtility::oneDVectorPairStr<int,int>(got).c_str());
      assert(false);
    }
  }  
}

int main() {
  ptr2scoreGathering pfcn = &scoreGathering;
  test(pfcn, FUNC_DEF_NAME(&scoreGathering));  
}
