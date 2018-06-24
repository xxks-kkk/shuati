//    Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//    Note:
//    You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//    Example 1:
//
//    Input: root = [3,1,4,null,2], k = 1
//       3
//      / \
//     1   4
//      \
//       2
//    Output: 1
//    Example 2:
//
//    Input: root = [5,3,6,2,4,null,null,1], k = 3
//           5
//          / \
//         3   6
//        / \
//       2   4
//      /
//     1
//    Output: 3
//    Follow up:
//    What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
//    How would you optimize the kthSmallest routine?

#include <bt.h>
#include <vector>

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        kthSmallestHelper(root, res);
        return res[k-1];
    }

    int kthSmallest2(TreeNode* root, int k) {
        vector<int> res;
        kthSmallestHelper2(root, res, k);
        return res[k-1];
    }
private:
    // here, we do the early stop
    void kthSmallestHelper2(TreeNode* & root, vector<int> & res, int & k)
    {
        if(root == nullptr)
        {
            return;
        }
        kthSmallestHelper2(root->left, res, k);
        if (res.size() == k)
            return;
        res.push_back(root->val);
        if (res.size() == k)
            return;
        kthSmallestHelper2(root->right, res, k);
        if (res.size() == k)
            return;
    }

    void kthSmallestHelper(TreeNode* & root, vector<int> & res)
    {
        if(root == nullptr)
        {
            return;
        }
        kthSmallestHelper(root->left, res);
        res.push_back(root->val);
        kthSmallestHelper(root->right, res);
    }
};

using ptr2kthSmallest = int (Solution::*)(TreeNode*, int);

void test(ptr2kthSmallest pfcn)
{
    BT bt;
    Solution sol;
    vector<int> nums = {3,1,4,NULLPTR,2};
    auto root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root, 1) == 1);
    bt.freeTree(root);
    nums = {5,3,6,2,4,NULLPTR,NULLPTR,1};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root, 3) == 3);
    bt.freeTree(root);
}

int main()
{
    ptr2kthSmallest pfcn = &Solution::kthSmallest;
    test(pfcn);
    pfcn = &Solution::kthSmallest2;
    test(pfcn);
}