#include<vector>
#include "cpputility.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if (matrix.empty() || matrix[0].empty()) return false;
      int num_rows = matrix.size();
      int num_cols = matrix[0].size();
      for(int i = num_rows - 1; i >= 0;) {
        for(int j = 0; j < num_cols;) {
          int element = matrix[i][j];
          if (element == target) {
            return true;
          } else if (element > target) {
            i--;
          } else if (element < target) {
            j++;
          }
          if (i < 0 || j == num_cols) goto ret;
        }
      }
    ret:
      return false;
    }
};

using ptr2searchMatrix = bool (Solution::*)(vector<vector<int>>&, int);

struct testFuncsInfo {
  ptr2searchMatrix pfcn;
  const char* pfcn_name;
};

void test(ptr2searchMatrix pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    vector<vector<int>> matrix;
    int target;
    bool expected;
  };
  vector<testCase> test_cases = {
    {{{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}}, 5, true},
    {{{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}}, 20, false},
    {{{}}, 10, false},
  };
  for(auto&& test_case: test_cases) {
    bool got = (sol.*pfcn)(test_case.matrix, test_case.target);
    if (got != test_case.expected) {
      printf("%s(%s,%d) = %s\n",
             pfcn_name,
             CPPUtility::twoDVectorStr<int>(test_case.matrix).c_str(),
             test_case.target,
             got == true ? "true": "false");
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::searchMatrix)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }  
}
  
