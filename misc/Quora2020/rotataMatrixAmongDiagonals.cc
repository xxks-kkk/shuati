#include <vector>
#include "cpputility.h"
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
  vector<vector<int>> rotateMatrixAmongDiagonals(vector<vector<int>>& matrix, int k) {
    int rotated_times = k % 4;
    int n = matrix.size();
    vector<vector<int>> res(n, vector<int>(n));    
    if (rotated_times == 0) {
      return matrix;
    }
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if (i == j || j == n-1-i) {
          res[i][j] = matrix[i][j];
        } else {
          if ((n % 2 == 1 && 0 < j  && j < n-1 && i >= 0 && i < n / 2) ||
              (n % 2 == 0 && 0 < j  && j < n-1 && i >= 0 && i < (n-1)/2)) {
              switch (rotated_times) {
              case 1:
                res[i][j] = matrix[j][i];
                break;
              case 2:
                res [i][j] = matrix[n-i-1][j];
                break;
              case 3:
                res[i][j] = matrix[j][n-i-1];
                break;
              }
          } else if ((n % 2 == 1 && i > 0 && i < n-1 && j > n/2 && j <= n-1) ||
                     (n % 2 == 0 && i > 0 && i < n-1 && j > n/2 && j <= n-1)){
              switch (rotated_times) {
              case 1:
                res[i][j] = matrix[n-j-1][i];
                break;
              case 2:
                res [i][j] = matrix[i][n-j-1];
                break;
              case 3:
                res[i][j] = matrix[j][i];
                break;
              }              
          } else if ((n%2 == 1 && i <= n-1 && i > n/2 && j > 0 && j < n-1) ||
                     (n%2 == 0 && i <= n-1 && i > n/2 && j > 0 && j < n-1)){
              switch (rotated_times) {
              case 1:
                res[i][j] = matrix[j][i];
                break;
              case 2:
                res [i][j] = matrix[n-i-1][j];
                break;
              case 3:
                res[i][j] = matrix[j][n-i-1];
                break;
              }              
          } else if ((n%2 == 1 && i > 0 && i < n-1 && j >= 0 && j < n / 2) ||
                     (n%2 == 0 && i > 0 && i < n-1 && j >= 0 && j < (n-1)/2)){
              switch (rotated_times) {
              case 1:
                res[i][j] = matrix[n-j-1][i];
                break;
              case 2:
                res [i][j] = matrix[i][n-j-1];
                break;
              case 3:
                res[i][j] = matrix[j][i];
                break;
              }              
            }
        }
      }
    }
    return res;
  }
};


class Test {
public:
  void test_rotateMatrixAmongDiagonals() {
    Solution sol;
    struct testCase {
      vector<vector<int>> matrix;
      int k;
      vector<vector<int>> expected;
    };
    vector<testCase> test_cases = {
      {{{1,2,3,},
        {4,5,6},
        {7,8,9}}, 1,
       {{1,4,3},
        {8,5,2},
        {7,6,9}}},
      {{{1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}}, 1,
       {{1,6,11,16,5},
        {22,7,12,9,2},
        {23,18,13,8,3},
        {24,17,14,19,4},
        {21,10,15,20,25}}},
      {{{1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}}, 1,
       {{1,5,9,4},
        {14,6,7,2},
        {15,10,11,3},
        {13,8,12,16}}},
    };
    for(auto&& test_case: test_cases) {
      auto got = sol.rotateMatrixAmongDiagonals(test_case.matrix, test_case.k);
      if (got != test_case.expected) {
        printf("rotatedMatrixAmongDiagonals(%s, %d) = %s\n",
               CPPUtility::twoDVectorStr<int>(test_case.matrix).c_str(),
               test_case.k,
               CPPUtility::twoDVectorStr<int>(got).c_str());
        assert(false);
      }
    }
  }
};

int main() {
  Test test;
  test.test_rotateMatrixAmongDiagonals();
}
