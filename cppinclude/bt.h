#include <stdlib.h>  /* abs */
#include <algorithm> /* max */
#include <vector>
#include <queue>
#include <assert.h>

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
    TreeNode* list2Tree(std::vector<int> & nums);
    std::vector<std::vector<int>> printTree(TreeNode *root);
    void freeTree(TreeNode *root);
};