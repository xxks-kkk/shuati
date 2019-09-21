// Find all possible combinations of k numbers that add up to a number n,
// given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:

//     All numbers will be positive integers.
//     The solution set must not contain duplicate combinations.

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]

// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

#include<vector>
#include<numeric>
#include<assert.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cand;
        backtrack(res, cand, k, n, 1);
        return res;
    }   
private:
    void backtrack(vector<vector<int>> &res, vector<int> cand, int k, int n, int lower_bound) {
        if (k*9 < n) {
            // solution doesn't exist
            return;
        }
        int total = accumulate(cand.begin(), cand.end(), 0);
        if (cand.size() == k && total != n) {
            return;
        } 
        if (cand.size() == k && total == n) {
            res.push_back(cand);
            return;
        }
        int upper_bound = (n>9) ? 9: n; // upper_bound of the number we can choose from
        for (int i = lower_bound; i <= upper_bound; i++) {
            cand.push_back(i);
            backtrack(res, cand, k, n, i+1);
            cand.pop_back();
        }
    }
};

using ptr2combinationSum3 = vector<vector<int>> (Solution::*)(int, int);

void test(ptr2combinationSum3 pfcn)
{
  Solution sol;
  struct testCase {
    int k;
    int n;
    vector<vector<int>> expected;
  };
  vector<testCase> test_cases = {
    {3, 7, { {1,2,4}}},
    {3, 9, { {1,2,6}, {1,3,5}, {2,3,4}}}
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
  ptr2combinationSum3 pfcn = &Solution::combinationSum3;
  test(pfcn);
}
