#include "bt.h"
#include <vector>
#include <stack>

class Solution {
public:
    // Recursive solution
    bool isValidBST(TreeNode* root) {
        TreeNode* lowerBound = nullptr;
        TreeNode* upperBound = nullptr;
        return isValidBSTHelper(root, lowerBound, upperBound);
    }
    // Iterative solution (very similar to iterative in-order traversal of tree)
    bool isValidBST2(TreeNode* root) {
        TreeNode* prev = nullptr;
        std::stack<TreeNode *> st;
        while(!st.empty() || root != nullptr)
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (prev && root->val <= prev->val)
            {
                return false;
            }
            prev = root;
            root = root->right;
        }
        return true;
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
    assert(!(sol.*pfcn)(root));
    bt.freeTree(root);

    nums = {2,1,3};
    root = bt.list2Tree(nums);
    assert((sol.*pfcn)(root));
    bt.freeTree(root);
}

int main()
{
    ptr2isValidBSTHelper pfcn = &Solution::isValidBST;
    test(pfcn);
    pfcn = &Solution::isValidBST2;
    test(pfcn);
}