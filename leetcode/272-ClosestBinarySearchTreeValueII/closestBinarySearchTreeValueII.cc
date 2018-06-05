//    Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
//
//    Note:
//
//    Given target value is a floating point.
//    You may assume k is always valid, that is: k ≤ total nodes.
//    You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
//    Example:
//
//    Input: root = [4,2,5,1,3], target = 3.714286, and k = 2
//
//        4
//       / \
//      2   5
//     / \
//    1   3
//
//    Output: [4,3]
//    Follow up:
//    Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

#include "bst.h"
#include <queue>
#include <stack>
#include <cmath>
#include <chrono>
#include <iostream>
#include <set>

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
    // Method 1: Naive Approach
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        vector<int> res;
        dfs(root, pq, target, k);
        while(!pq.empty())
        {
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }

    // Method 2: Use BST assumption
    vector<int> closestKValues2(TreeNode* root, double target, int k) {
        vector<int> res;
        stack<int> pred, succ;
        inorder(root, target, true, pred);
        inorder(root, target, false, succ);
        while(k-- > 0)
        {
            if(pred.empty())
            {
                res.push_back(succ.top());
                succ.pop();
            }
            else if(succ.empty())
            {
                res.push_back(pred.top());
                pred.pop();
            }
            else if(fabs(succ.top() - target) > fabs(pred.top() - target))
            {
                res.push_back(pred.top());
                pred.pop();
            }
            else
            {
                res.push_back(succ.top());
                succ.pop();
            }
        }
        return res;
    }

    // Method 2.1: Another O(n) approach
    // One caveat: returns [3,4] instead of [4,3]. But pass all the tests on Leetcode
    vector<int> closestKValues3(TreeNode* root, double target, int k)
    {
        vector<int> res;
        inorder2(root, target, k, res);
        return res;
    }


    // Method 2.2: Another O(n) approach. Use binary search in preorder traversal
    // One caveat: returns [3,4] instead of [4,3]. But pass all the tests on Leetcode
    vector<int> closestKValues4(TreeNode* root, double target, int k)
    {
        vector<int> nums;
        inorder3(root, nums);
        vector<int> res = kClosestValue(nums, target, k);
        return res;
    }

    // Method 3: O(klogn) approach
    vector<int> closestKValues5(TreeNode* root, double target, int k)
    {
        vector<int> res;
        stack<TreeNode*> pred, succ;
        auto current = root;
        while(current != nullptr)
        {
            if (target <= current->val)
            {
                succ.push(current);
                current = current->left;
            }
            else
            {
                pred.push(current);
                current = current->right;
            }
        }
        while (k-- > 0)
        {
            if (pred.empty())
            {
                res.push_back(getSuccessor(succ));
            }
            else if (succ.empty())
            {
                res.push_back(getPredecessor(pred));
            }
            else if (fabs(target - pred.top()->val) < fabs(target - succ.top()->val))
            {
                res.push_back(getPredecessor(pred));
            }
            else
            {
                res.push_back(getSuccessor(succ));
            }
        }
        return res;
    }

private:
    void dfs(TreeNode* root, priority_queue<pair<double, int>>& pq, const double target, const int k) {
        if (root == nullptr)
        {
            return;
        }
        pq.push(make_pair(fabs(root->val - target), root->val));
        if(pq.size() > k)
        {
            pq.pop();
        }
        dfs(root->left, pq, target, k);
        dfs(root->right, pq, target, k);
    }

    void inorder(TreeNode* root, const double target, bool isPreorderTraversal, stack<int> & st)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(isPreorderTraversal ? root->left : root->right, target, isPreorderTraversal, st);
        if((isPreorderTraversal && root->val < target) || (!isPreorderTraversal && root->val >= target))
        {
            st.push(root->val);
        }
        else
        {
            // early terminate, no need to traverse the whole tree
            return;
        }
        inorder(isPreorderTraversal ? root->right : root->left, target, isPreorderTraversal, st);
    }

    void inorder2(TreeNode* root, double target, int k, vector<int> & res)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder2(root->left, target, k, res);
        if (res.size() < k)
        {
            res.push_back(root->val);
        }
        else if (fabs(root->val - target) < fabs(res[0] - target))
        {
            res.erase(res.begin());
            res.push_back(root->val);
        }
        else
        {
            return;
        }
        inorder2(root->right, target, k, res);
    }

    void inorder3(TreeNode* root, vector<int> & nums)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder3(root->left, nums);
        nums.push_back(root->val);
        inorder3(root->right, nums);
    }

    // A variant of binary search that finds the k closest values for the given target
    // variant: the index of the first number that is among the k closest values for the given target
    // is in [left, right]
    vector<int> kClosestValue(vector<int> & nums, double target, int k)
    {
        int left = 0;
        int right = nums.size() - k;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (fabs(nums[mid] - target) <= fabs(nums[mid+k] - target))
            {
                // nums[mid] is closer than nums[mid+k] but this doesn't guarantee that we already
                // at the first index of the k **closest** values. Thus, we adjust right
                right = mid;
            }
            else // fabs(nums[mid] - target) > fabs(nums[mid+k] - target)
            {
                // we see nums[mid+k] is more closer than nums[mid]. Thus, to make invariant holds (index of the first number),
                // we adjust left
                left = mid + 1;
            }
        }
        return vector<int>(nums.begin()+left, nums.begin()+left+k);
    }

    int getPredecessor(stack<TreeNode*> & st)
    {
        auto popped = st.top();
        st.pop();
        auto p = popped->left;
        while (p != nullptr)
        {
            st.push(p);
            p = p->right;
        }
        return popped->val;
    }

    int getSuccessor(stack<TreeNode*> & st)
    {
        auto popped = st.top();
        st.pop();
        auto p = popped->right;
        while (p != nullptr)
        {
            st.push(p);
            p = p->left;
        }
        return popped->val;
    }
};

using ptr2closestKValues = vector<int> (Solution::*) (TreeNode*, double, int);

void test(ptr2closestKValues pfcn)
{
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    BST bst;
    Solution sol;
    vector<int> nums = {4,2,5,1,3};
    auto root = bst.list2Tree(nums);
    double target = 3.714286;
    int k = 2;
    vector<int> ans = {4,3};
    vector<int> myans = (sol.*pfcn)(root, target, k);
    assert(set<int>(myans.begin(), myans.end()) == set<int>(ans.begin(), ans.end()));
    bst.freeTree(root);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    std::cout << "duration (ms): " << duration << std::endl;
}

int main()
{
    ptr2closestKValues pfcn = &Solution::closestKValues;
    test(pfcn);
    pfcn = &Solution::closestKValues2;
    test(pfcn);
    pfcn = &Solution::closestKValues3;
    test(pfcn);
    pfcn = &Solution::closestKValues4;
    test(pfcn);
    pfcn = &Solution::closestKValues5;
    test(pfcn);
}

