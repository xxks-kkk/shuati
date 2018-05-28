//    Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
//
//    You may assume each number in the sequence is unique.
//
//    Consider the following binary search tree:
//
//         5
//        / \
//       2   6
//      / \
//     1   3
//    Example 1:
//
//    Input: [5,2,6,1,3]
//    Output: false
//    Example 2:
//
//    Input: [5,2,1,3,6]
//    Output: true
//    Follow up:
//    Could you do it using only constant space complexity?

#include "bst.h"
#include <stack>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int lower_bound = INT_MIN;
        for(int i = 0; i < preorder.size(); ++i)
        {
            if (stk.empty() || preorder[i] < preorder[i-1])
            {
                if (preorder[i] <= lower_bound)
                {
                    return false;
                }
            }
            else
            {
                while (!stk.empty() && stk.top() < preorder[i])
                {
                    lower_bound = stk.top();
                    stk.pop();
                }
            }
            stk.push(preorder[i]);
        }
        return true;
    }

    bool verifyPreorder2(vector<int>& preorder) {
        int lower_bound = INT_MIN, i = -1;
        for(auto p: preorder)
        {
            if (p < lower_bound)
            {
                return false;
            }
            while (i >= 0 && p > preorder[i])
            {
                lower_bound = preorder[i--];
            }
            preorder[++i] = p;
        }
        return true;
    }
};

using ptr2verifyPreorder = bool (Solution::*)(vector<int>&);

void test(ptr2verifyPreorder pfcn)
{
    Solution sol;
    vector<int> preorder = {5,2,6,1,3};
    assert(!(sol.*pfcn)(preorder));
    preorder = {5,2,1,3,6};
    assert((sol.*pfcn)(preorder));
    preorder = {1,3,2};
    assert((sol.*pfcn)(preorder));
    preorder = {2,3,1};
    assert(!(sol.*pfcn)(preorder));
}

int main()
{
    ptr2verifyPreorder pfcn = &Solution::verifyPreorder;
    test(pfcn);
    pfcn = &Solution::verifyPreorder2;
    test(pfcn);
}