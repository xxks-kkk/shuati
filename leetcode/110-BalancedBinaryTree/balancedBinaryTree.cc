//    Given a binary tree, determine if it is height-balanced.
//
//    For this problem, a height-balanced binary tree is defined as:
//
//    a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//    Example 1:
//
//    Given the following tree [3,9,20,null,null,15,7]:
//
//        3
//       / \
//      9  20
//        /  \
//       15   7
//    Return true.
//
//    Example 2:
//
//    Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
//    Return false.

#include "bt.h"
#include "cpputility.h"

using namespace std;

struct BalancedStatusWithHeight
{
    bool balanced;
    int height;
};

class Solution
{
public:
    bool
    isBalanced(TreeNode *root)
    {
        return checkBalanced(root).balanced;
    }
private:
    BalancedStatusWithHeight
    checkBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {true, -1};
        }
        auto left_result = checkBalanced(root->left);
        if (!left_result.balanced)
        {
            return {false, 0};
        }
        auto right_result = checkBalanced(root->right);
        if (!right_result.balanced)
        {
            return {false, 0};
        }
        bool is_balanced = abs(left_result.height - right_result.height) <= 1;
        int height = std::max(left_result.height, right_result.height) + 1;
        return {is_balanced, height};
    }
};

using ptr2isBalanced = bool (Solution::*)(TreeNode*);

void test(ptr2isBalanced pfcn) {
  Solution sol;
  BT bt;
  struct testCase {
    vector<int> tree;
    bool expected;
  };
  vector<testCase> test_cases = {
    { {3,9,20,NULLPTR,NULLPTR,15,7}, true},
    {{1,2,2,3,3,NULLPTR,NULLPTR,4,4}, false}
  };
  for (auto&& test_case: test_cases) {
    auto root = bt.list2Tree(test_case.tree);
    auto got = (sol.*pfcn)(root);
    bt.freeTree(root);
    if (got != test_case.expected) {
      printf("%s returns %s\n",
             CPPUtility::oneDVectorStr(test_case.tree).c_str(),
             got == true ? "true" : "false");
      assert(false);
    }
  }
}

int main()
{
  ptr2isBalanced pfcn = &Solution::isBalanced;
  test(pfcn);
}
