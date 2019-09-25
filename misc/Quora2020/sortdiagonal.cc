#include <vector>
#include "cpputility.h"
#include <stdio.h>

using namespace std;

class Solution {
public:
  void sortDiagonal(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        vector<int> cand;
        vector<tuple<int, int>> idx;
        int i_tmp = i;
        int j_tmp = j;
        if ( i_tmp == 0  || j_tmp == 0) {
          while (i_tmp < m && j_tmp < n) {
            cand.push_back(matrix[i_tmp][j_tmp]);
            idx.push_back({i_tmp, j_tmp});
            i_tmp++;
            j_tmp++;
          }
          sort(cand.begin(), cand.end());
          for(int k = 0; k < cand.size(); ++k) {
            auto coord = idx[k];
            matrix[get<0>(coord)][get<1>(coord)] = cand[k];
          }
        }
      }
    }
  }
};


class Test {
public:
  void test_sortDiagonal() {
    Solution sol;
    struct testCase {
      vector<vector<int>> matrix;
      vector<vector<int>> expected;
    };
    vector<testCase> test_cases = {
      {{{1,4,7}, {7,3,2}, {5,2,2}}, {{1,2,7},{2,2,4},{5,7,3}}},
    };
    for(auto&& test_case: test_cases) {
      auto test_case_cpy = test_case.matrix;
      sol.sortDiagonal(test_case.matrix);
      if (test_case.matrix != test_case.expected) {
        printf("sortDiagonal(%s) = %s\n",
               CPPUtility::matrixStr<int>(test_case_cpy).c_str(),
               CPPUtility::matrixStr<int>(test_case.matrix).c_str());
      }
    }
  }
};

int main() {
  Test test;
  test.test_sortDiagonal();
}
