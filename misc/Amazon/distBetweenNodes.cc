#include "cpputility.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

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

TreeNode* findNode1(TreeNode* root, int node1) {
  if (root == nullptr) return nullptr;
  if (root->key == node1) return root;
  auto cand1 = findNode1(root->left, node1);
  if (cand1) return cand1;
  else return findNode1(root->right, node1);
}

void dfs(TreeNode* node,
         int dist,
         int target,
         unordered_map<TreeNode*, TreeNode*>& parent,
         unordered_set<TreeNode*>& visited,
         vector<int>& res) {
  // We use in-order traversal and assume node1 < node2 all the time
  if (visited.count(node)) return;
  visited.insert(node);
  if (node->key == target) {
    res.push_back(dist);
    return;
  }
  if (node->left) dfs(node->left, dist+1, target, parent, visited, res);
  if (node->right) dfs(node->right, dist+1, target, parent, visited, res);
  if (parent[node]) dfs(parent[node], dist+1, target, parent, visited, res);
}

void findParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
  if (!node) return;
  if (node->left) parent[node->left] = node;
  if (node->right) parent[node->right] = node;
  findParent(node->left, parent);
  findParent(node->right, parent);
}

int bstDistance(const vector<int>& values, int node1, int node2) {
  auto root = list2Tree(values);
  int dist = 0;
  if (root == nullptr) return dist;
  unordered_map<TreeNode*, TreeNode*> parent;
  unordered_set<TreeNode*> visited;
  vector<int> res;
  findParent(root, parent);
  TreeNode* node;
  if (node1 > node2) {
    node = findNode1(root, node2);
    dfs(node, dist, node1, parent, visited, res);
  } else if (node1 < node2) {
    node = findNode1(root, node1);
    dfs(node, dist, node2, parent, visited, res);
  } else {
    return 0;
  }
  return res[0];
}

using ptr2bstDistance = int (*) (const vector<int>&, int, int);

void test(ptr2bstDistance pfcn, const char* pfcn_name) {
  struct testCase {
    vector<int> values;
    int node1;
    int node2;
    int expected;
  };
  vector<testCase> test_cases = {
    {{5,6,3,1,2,4}, 2, 4, 3},
  };
  for(auto&& test_case: test_cases) {
    auto got = (*pfcn)(test_case.values, test_case.node1, test_case.node2);
    if (got != test_case.expected) {
      printf("%s(%s, %d, %d) = %d\n",
             pfcn_name,            
             CPPUtility::oneDVectorStr<int>(test_case.values).c_str(),
             test_case.node1,
             test_case.node2,
             got);
      assert(false);
    }
  }    
}
                                 
int main() {
  ptr2bstDistance pfcn = &bstDistance;
  test(pfcn, FUNC_DEF_NAME(&bstDistance));
}
