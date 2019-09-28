// You have k lists of sorted integers in ascending order. Find the smallest range that
// includes at least one number from each of the k lists.

// We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c

// Example 1:
// Input: [[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].

// Note:
//     The given list may contain duplicates, so ascending order means >= here.
//     1 <= k <= 3500
//     -105 <= value of elements <= 105.
                                                                          
#include <vector>
#include <limits>
#include <stdio.h>
#include "cpputility.h"
#include <cassert>

#define FUNC_DEF(func) { func, #func },

using namespace std;

class Solution {
public:
  // WARNING: BRUTE FORCE APPROACH TO ILLUSTRATE IDEA
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int minx = 0;
    int miny = std::numeric_limits<int>::max();
    for(int i = 0; i < nums.size(); ++i) {
      for(int j = 0; j < nums[i].size(); ++j) {
        for(int k = i; k < nums.size(); ++k) {
          for(int l = (k == i? j: 0); l < nums[k].size(); ++l) {
            int min = nums[i][j] > nums[k][l] ? nums[k][l] : nums[i][j];
            int max = nums[i][j] > nums[k][l] ? nums[i][j] : nums[k][l];
            int n, m;
            for(m = 0; m < nums.size(); ++m) {
              for(n = 0; n < nums[m].size(); ++n) {
                if (nums[m][n] >= min && nums[m][n] <= max) {
                  break;
                }
              }
              if (n == nums[m].size())
                break;
            }
            if (m == nums.size()) {
              if (miny - minx > max - min ||
                  (miny - minx == max -min && minx > min)) {
                miny = max;
                minx = min;
              }
            }
          }
        }
      }
    }
    return {minx, miny};
  }
};

using ptr2smallestRange = vector<int> (Solution::*)(vector<vector<int>>&);

struct testFuncsInfo {
  ptr2smallestRange pfcn;
  const char* pfcn_name;
};

void test(ptr2smallestRange pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    vector<vector<int>> nums;
    vector<int> expected;
  };
  vector<testCase> test_cases = {
    {{{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}}, {20,24}},
  };
  for(auto&& test_case: test_cases) {
    vector<int> get = (sol.*pfcn)(test_case.nums);
    if (get != test_case.expected) {
      printf("%s(%s) = %s\n", pfcn_name,
             CPPUtility::twoDVectorStr(test_case.nums).c_str(),
             CPPUtility::oneDVectorStr(get).c_str());
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::smallestRange)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
