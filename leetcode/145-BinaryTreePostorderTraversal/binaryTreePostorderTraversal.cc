//    Given a binary tree, return the postorder traversal of its nodes' values.
//
//    Example:
//
//    Input: [1,null,2,3]
//        1
//        \
//         2
//       /
//      3
//
//    Output: [3,2,1]
//    Follow up: Recursive solution is trivial, could you do it iteratively?

#include "bt.h"
#include <stack>
#include <list>

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
    // recursive solution
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversalHelper(root, res);
        return res;
    }

    // iterative solution + stack
    vector<int> postorderTraversal2(TreeNode* root) {
        if (root == nullptr)
        {
            return std::vector<int>{};
        }
        std::list<int> res;
        std::stack<TreeNode *> s;
        s.push(root);
        while(!s.empty())
        {
            auto current = s.top();
            s.pop();
            // Following line makes us to use list instead of vector directly: insertion (at the beginning of) vector is expensive
            res.insert(res.begin(),current->val);
            if(current->right)
            {
                s.push(current->right);
            }
            if(current->left)
            {
                s.push(current->left);
            }
        }
        // We transform list into vector. since we don't really need list, we use std::make_move_iterator to move
        // values from list to vector (https://stackoverflow.com/questions/5218713/one-liner-to-convert-from-listt-to-vectort/5218738)
        return std::vector<int>{std::make_move_iterator(res.begin()), std::make_move_iterator(res.end())};
    }
private:
    void postorderTraversalHelper(TreeNode* root, vector<int> & res)
    {
        if(root == nullptr)
        {
            return;
        }
        postorderTraversalHelper(root->left, res);
        postorderTraversalHelper(root->right, res);
        res.push_back(root->val);
    }
};

// use type alias defining a function pointer to a non-static member function
using ptr2postorderTraversal = vector<int>(Solution::*)(TreeNode*);

void test(ptr2postorderTraversal pfcn)
{
    BT bt;
    Solution sol;
    const vector<int> nums = {1, NULLPTR, 2, 3};
    auto root = bt.list2Tree(nums);
    vector<int> ans = {3,2,1};
    assert((sol.*pfcn)(root) == ans);
}


int main()
{
    ptr2postorderTraversal pfcn = &Solution::postorderTraversal;
    test(pfcn);
    pfcn = &Solution::postorderTraversal2;
    test(pfcn);
}