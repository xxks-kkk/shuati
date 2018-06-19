#include "bt.h"
#include "vector"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* lowerBound = nullptr;
        TreeNode* upperBound = nullptr;
        return isValidBSTHelper(root, lowerBound, upperBound);
    }
private:
    bool isValidBSTHelper(TreeNode* root, TreeNode* lowerBound, TreeNode* upperBound)
    {
        if (root == nullptr)
        {
            return true;
        }
        if((lowerBound && root->val <= lowerBound->val) ||
            (upperBound && root->val >= upperBound->val))
        {
            return false;
        }
        return isValidBSTHelper(root->left, lowerBound, root) &&
            isValidBSTHelper(root->right, root, upperBound);
    }
};

using ptr2isValidBSTHelper = bool (Solution::*)(TreeNode*);

void test(ptr2isValidBSTHelper pfcn)
{
    Solution sol;
    BT bt;
    std::vector<int> nums = {5,1,4,NULLPTR,NULLPTR,3,6};
    auto root = bt.list2Tree(nums);
    assert(!sol.isValidBST(root));
    bt.freeTree(root);
}

int main()
{
    ptr2isValidBSTHelper pfcn = &Solution::isValidBST;
    test(pfcn);
}