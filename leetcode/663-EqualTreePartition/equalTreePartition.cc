// Given a binary tree with n nodes, your task is to check if it's possible to 
// partition the tree to two trees which have the equal sum of values after 
// removing exactly one edge on the original tree.

// Example 1:
// Input:     
//     5
//    / \
//   10 10
//     /  \
//    2   3

// Output: True
// Explanation: 
//     5
//    / 
//   10

// Sum: 15

//    10
//   /  \
//  2    3

// Sum: 15
// Example 2:
// Input:     
//     1
//    / \
//   2  10
//     /  \
//    2   20

// Output: False
// Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
//   Note:
//   The range of tree node value is in the range of [-100000, 100000].
// 1 <= n <= 10000

#include "bt.h"
#include <stack>
#include <vector>
#include <cassert>

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
  bool checkEqualTree(TreeNode* root) {
    std::stack<int> s;
    int totalSum = checkEqualTreeHelper(root, s);
    s.pop(); // we exclude the sum of the whole tree from following consideration.
    if (totalSum % 2 == 0)
    {
      while(!s.empty())
      {
        if(s.top() == totalSum / 2)
        {
          return true;
        }
        s.pop();
      }
    }
    return false;
  }
private:
  int checkEqualTreeHelper(TreeNode* & root, std::stack<int> & s)
  {
    if(root == nullptr)
    {
      return 0;
    }
    int left_sum = checkEqualTreeHelper(root->left, s);
    int right_sum = checkEqualTreeHelper(root->right, s);
    s.push(root->val + left_sum + right_sum);
    return s.top();
  }
};

using ptr2checkEqualTree = bool (Solution::*)(TreeNode*);

void test(ptr2checkEqualTree pfcn)
{
  Solution sol;
  BT bt;
  std::vector<int> nums = {-1,0,1};
  auto root = bt.list2Tree(nums);
  assert(!(sol.*pfcn)(root));
  bt.freeTree(root);
}

int main()
{
  ptr2checkEqualTree pfcn = &Solution::checkEqualTree;
  test(pfcn);
}
