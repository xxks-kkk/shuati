#include <vector>
#include <queue>
#include "bt.h"
#include "cpputility.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if (root == nullptr) return res;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
        int size = q.size();
        vector<int> tmp;
        while(size) {
          auto node = q.front(); q.pop();
          tmp.emplace_back(node->val);
          if (node->left) q.push(node->left);
          if (node->right) q.push(node->right);
          size--;
        }
        res.emplace_back(tmp);
      }
      return res;
    }
};

using ptr2levelOrder = vector<vector<int>> (Solution::*)(TreeNode*);

void test(ptr2levelOrder pfcn) {
  Solution sol;
  BT bt;
  struct testCase {
    vector<int> nums;
    vector<vector<int>> expected;
  };
  vector<testCase> test_cases = {
    {{3,9,20,NULLPTR, NULLPTR, 15, 7}, {{3},{9,20},{15,7}}},
  };
  for(auto&& test_case: test_cases) {
    auto root = bt.list2Tree(test_case.nums);
    auto got = (sol.*pfcn)(root);
    if (got != test_case.expected) {
      printf("levelOrder(%s) = %s\n",
             CPPUtility::oneDVectorStr<int>(test_case.nums).c_str(),
             CPPUtility::twoDVectorStr<int>(got).c_str());
      assert(false);
    }
  }
}

int main() {
  ptr2levelOrder pfcn = &Solution::levelOrder;
  test(pfcn);
}
