//    Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
//
//    The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
//
//    Example 1:
//    Input:
//
//                1
//              /   \
//            3     2
//           / \     \
//          5   3     9
//
//    Output: 4
//    Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
//    Example 2:
//    Input:
//
//             1
//            /
//           3
//          / \
//         5   3
//
//    Output: 2
//    Explanation: The maximum width existing in the third level with the length 2 (5,3).
//    Example 3:
//    Input:
//
//              1
//             / \
//            3   2
//           /
//          5
//
//    Output: 2
//    Explanation: The maximum width existing in the second level with the length 2 (3,2).
//    Example 4:
//    Input:
//
//              1
//             / \
//            3   2
//           /     \
//          5       9
//         /         \
//        6           7
//    Output: 8
//    Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
//
//
//    Note: Answer will in the range of 32-bit signed integer.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "cppinclude/bt.h"
#include <queue>
#include <vector>
#include <cassert>
#include <algorithm> // std::max

using namespace std;

class Solution
{
public:
    // BFS
    int
    widthOfBinaryTree(TreeNode *root)
    {
        // pair<node, the numbering of the node>
        queue<pair<TreeNode *, int>> q;
        // C++: another way of creating a pair
        q.push(pair<TreeNode *, int>(root, 1));
        int maxVal = 0;
        while (!q.empty())
        {
            int len = q.size();
            // the leftmost numbering for the current level
            int leftmost = q.front().second;
            // the rightmost numbering for the current level
            int rightmost = leftmost;
            for (int i = 0; i < len; ++i)
            {
                auto node = q.front().first;
                int numbering = q.front().second;
                q.pop();
                if (node->left)
                {
                    q.push({node->left, numbering * 2});
                }
                if (node->right)
                {
                    q.push({node->right, numbering * 2 + 1});
                }
                rightmost = numbering;
            }
            maxVal = max(maxVal, rightmost - leftmost + 1);
        }
        return maxVal;
    }

    // DFS
    int
    widthOfBinaryTree2(TreeNode *root)
    {
        // C++: how we can initialize an empty vector directly as argument to the function call.
        return widthOfBinaryTree2Helper(root, 0, 1, vector<pair<int, int>>() = {});
    }
private:
    int
    widthOfBinaryTree2Helper(TreeNode *root, int level, int numbering, vector<pair<int, int>> &vec)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (vec.size() == level)
        {
            // pair<leftmost numbering for the current level, rightmost numbering for the current level>
            // since DFS, we hit this branch when we visit all the nodes in the leftmost path
            vec.push_back({numbering, numbering});
        }
        else
        {
            // We hit this branch when we backtrack during the recursion
            // and happens only when we visit paths other than leftmost path
            vec[level].second = numbering;
        }
        // C++: interesting way to acqure the max among three elements
        return max({vec[level].second - vec[level].first + 1,
                   widthOfBinaryTree2Helper(root->left, level + 1, numbering * 2, vec),
                   widthOfBinaryTree2Helper(root->right, level + 1, numbering * 2 + 1, vec)});
    }
};

using ptr2widthOfBinaryTree = int (Solution::*)(TreeNode *);

void
test(ptr2widthOfBinaryTree pfcn)
{
    Solution sol;
    BT bt;
    vector<int> nodes = {1, 3, 2, 5, 3, NULLPTR, 9};
    auto root = bt.list2Tree(nodes);
    assert((sol.*pfcn)(root) == 4);
    bt.freeTree(root);

    nodes = {1, 3, NULLPTR, 5, 3};
    root = bt.list2Tree(nodes);
    assert((sol.*pfcn)(root) == 2);
    bt.freeTree(root);
}

int
main()
{
    ptr2widthOfBinaryTree pfcn = &Solution::widthOfBinaryTree;
    test(pfcn);

    pfcn = &Solution::widthOfBinaryTree2;
    test(pfcn);
}