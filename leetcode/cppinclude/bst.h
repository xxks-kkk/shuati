#include "bt.h"

class BST: public BT
{
public:
    TreeNode* list2Tree(const std::vector<int> & nums) override;
    void insert(TreeNode* & root, int val);
    TreeNode* find(TreeNode* root, int val) override;
};