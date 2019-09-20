// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

//     All numbers (including target) will be positive integers.
//     The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]

// Example 2:

// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]


#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        backtrack(res, candidates, target, sol, 0);
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& sol, int lower_bound) {
        int total = accumulate(sol.begin(), sol.end(), 0);
        if (total > target) {
            return;
        }
        if (total == target) {
            res.push_back(sol);
            return;
        }
        for(int i = lower_bound; i < candidates.size(); ++i) {
            sol.push_back(candidates[i]);
            backtrack(res, candidates, target, sol, i);
            sol.pop_back();
        }
    }
};

using ptr2combinationSum = vector<vector<int>> (Solution::*) (vector<int>&, int);

void test(ptr2combinationSum pfcn)
{
  Solution sol;
  struct testCase {
    vector<int> candidates;
    int target;
    vector<vector<int>> expected;
  };
  vector<testCase> test_cases = {
    {{2,3,6,7}, 7, { {7}, {2,2,3}} },
    {{2,3,5}, 8, { {2,2,2,2}, {2,3,3}, {3,5}}}
  };
  for(auto && test_case: test_cases) {
    vector<vector<int>> got = (sol.*pfcn)(test_case.candidates, test_case.target);
    for(auto&& item: got) {
      if (find(test_case.expected.begin(), test_case.expected.end(), item) == test_case.expected.end())
      {
        assert(false);
      }
    }
  }
}

int main()
{
  ptr2combinationSum pfcn = &Solution::combinationSum;
  test(pfcn);
}
