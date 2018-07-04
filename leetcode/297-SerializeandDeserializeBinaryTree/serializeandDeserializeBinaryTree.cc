//    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//
//    Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//
//    Example:
//
//    You may serialize the following tree:
//
//        1
//       / \
//      2   3
//         / \
//        4   5
//
//    as "[1,2,3,null,null,4,5]"
//    Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//
//    Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "bt.h"
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <iostream>
#include "cpputility.h"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "[";
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node)
            {
                result.append(to_string(node->val));
                result.append(",");
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                result.append("null,");
            }
        }
        result.append("]");
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data.erase(0,1); // remove "["
        data.erase(data.size()-1, 1); // remove "]"
        vector<string> tokens = CPPUtility::split(data, ",");
        deque<TreeNode*> q;
        // We push all the nodes in the order of the vector to the deque
        for(auto & token : tokens)
        {
            TreeNode* node;
            if (token != "null")
            {
                node = new TreeNode(stoi(token));
            }
            else
            {
                node = nullptr;
            }
            q.push_back(node);
        }
        // We use another deque to do the level-order traversal
        deque<TreeNode*> levelq;
        auto root = q.front();
        q.pop_front();
        levelq.push_back(root);
        while(!levelq.empty())
        {
            auto node = levelq.front();
            levelq.pop_front();
            if (node != nullptr)
            {
                node->left = q.front();
                q.pop_front();
                levelq.push_back(node->left);
                node->right = q.front();
                q.pop_front();
                levelq.push_back(node->right);
            }
        }
        return root;
    }
};

void test()
{
    Codec codec;
    BT bt;
    vector<int> nums = {1,2,3,NULLPTR,NULLPTR,4,5,NULLPTR,NULLPTR,NULLPTR,NULLPTR};
    auto root = bt.list2Tree(nums);
    auto serialized_tree = codec.serialize(root);
    cout << serialized_tree << endl;
    auto node2 = codec.deserialize(serialized_tree);
    assert(bt.tree2List(node2) == nums);
}

int main()
{
    test();
}