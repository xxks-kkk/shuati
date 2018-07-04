#include "shared_headers.h"

// We define NULLPTR as a way to allow us quickly test
// the code's correctness. It's a hack.
#define NULLPTR (-999)

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BT
{
public:
    virtual TreeNode* list2Tree(const std::vector<int> & nums);
    std::vector<std::vector<int>> printTree(TreeNode *root);
    void freeTree(TreeNode *root);
    // find one node containing the target value
    virtual TreeNode* find(TreeNode* root, int val);
    // find all the nodes containing the target value
    std::vector<TreeNode*> findAll(TreeNode* root, int val);
    std::vector<int> tree2List(TreeNode* root);
};