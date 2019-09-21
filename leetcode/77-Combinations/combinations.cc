// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// Example:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cand;
        backtrack(res, cand, k, n, 1);
        return res;
    }
private:
    void backtrack(vector<vector<int>>& res, vector<int> cand, int k, int n, int lower_bound) {
        if (cand.size() == k) {
            res.push_back(cand);
            return;
        }
        for(int i = lower_bound; i <= n; ++i) {
            cand.push_back(i);
            backtrack(res, cand, k, n, i+1);
            cand.pop_back();
        }
    }
};

using ptr2combine = vector<vector<int>> (Solution::*) (int, int);

void test(ptr2combine pfcn)
{
  Solution sol;
  struct testCase {
    int n;
    int k;
    vector<vector<int>> expected;
  };
  vector<testCase> test_cases = {
    {4, 2, { {2,4}, {3,4}, {2,3}, {1,2}, {1,3}, {1,4}}},
  };
  for(auto && test_case: test_cases) {
    vector<vector<int>> got = (sol.*pfcn)(test_case.k, test_case.n);
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
  ptr2combine pfcn = &Solution::combine;
  test(pfcn);
}
