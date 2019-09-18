//    Given a set of distinct integers, nums, return all possible subsets (the power set).
//
//    Note: The solution set must not contain duplicate subsets.
//
//    Example:
//
//    Input: nums = [1,2,3]
//    Output:
//    [
//    [3],
//    [1],
//    [2],
//    [1,2,3],
//    [1,3],
//    [2,3],
//    [1,2],
//    []
//    ]

#include <vector>
#include <unordered_set>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> selections;
        backtrack(nums, res, selections);
        return res;
    }
private:
    // Follow the "Algorithm Design Manual (2nd edition)" Backtracking template (section 7.1)
  void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<bool>& selections) {
        if (selections.size() == nums.size()) {
            vector<int> tmp;
            for(int i = 0; i < selections.size(); ++i) {
                if (selections[i]) tmp.push_back(nums[i]);
            }
            res.push_back(tmp);
        }
        else {
            // For each num in nums, we have two choice: pick ('true') or not pick ('false')
            vector<bool> cand = {true, false};
            for(auto &&item: cand) {
                selections.push_back(item);
                backtrack(nums, res, selections);
                selections.pop_back();
            }
        }
    }
};

using ptr2subsets = vector<vector<int>> (Solution::*)(vector<int>&);

void test(ptr2subsets pfcn)
{
    Solution sol;
    vector<int> nums = {1,2,3};
    auto subsets = (sol.*pfcn)(nums);
    vector<vector<int>> ans = {
        {3}, {1}, {2}, {1,2,3}, {1,3}, {2,3}, {1,2}, {}
    };
    assert(ans.size() == subsets.size());
    for(auto&& subset: subsets)
    {
        if(find(ans.begin(), ans.end(), subset) == ans.end()) {
            assert(false);
        }
    }
}

int main()
{
    ptr2subsets pfcn = &Solution::subsets;
    test(pfcn);
}
