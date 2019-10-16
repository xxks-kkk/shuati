// Amazon OA (10/11/19)

#include "cpputility.h"
#include <queue>
#include <vector>

using namespace std;

int minimumDistance(int numRows, int numColumns, int **area) {
  queue<pair<int, int>> q;
  vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
  auto visited = vector<vector<int>>(numRows, vector<int>(numColumns, 0));
  q.emplace(0,0);
  int dist = 0;
  while(!q.empty()) {
    int num_nodes_for_current_level = q.size();
    while(num_nodes_for_current_level--) {
      auto coord = q.front(); q.pop();
      int start_x = coord.first;
      int start_y = coord.second;
      if (area[start_x][start_y] == 9) {
        return dist;
      }
      for(auto&& dir: dirs) {
        start_x = coord.first;
        start_y = coord.second;
        start_x += dir.first;
        start_y += dir.second;
        if (start_x >= 0 && start_x < numRows &&
            start_y >= 0 && start_y < numColumns &&
            area[start_x][start_y] != 0 &&
            visited[start_x][start_y] != 1) {
          q.emplace(start_x, start_y);
          visited[start_x][start_y] = 1;
        }
      }
    }
    dist++;
  }
  return -1;
}

using ptr2minimumDistance = int (*) (int, int, int**);

struct testCase {
  int numRows;
  int numColumns;
  int** area;
  int expected;
};

vector<testCase> construct_test_cases() {
  vector<testCase> test_cases;
  int numRows = 3;
  int numColumns = 3;
  int** test_case1 = new int*[numRows];
  for(int i = 0 ; i < numRows; ++i) {
    test_case1[i] = new int[numColumns];
  }
  test_case1[0][0] = 1;
  test_case1[0][1] = 0;
  test_case1[0][2] = 0;
  test_case1[1][0] = 1;
  test_case1[1][1] = 0;
  test_case1[1][2] = 0;
  test_case1[2][0] = 1;
  test_case1[2][1] = 9;
  test_case1[2][2] = 1;
  test_cases.push_back({numRows,numColumns, test_case1, 3});

  numRows = 5;
  numColumns = 4;
  int** test_case2 = new int*[numRows];
  for(int i = 0 ; i < numRows; ++i) {
    test_case2[i] = new int[numColumns];
  }
  test_case2[0][0] = 1;
  test_case2[0][1] = 1;
  test_case2[0][2] = 1;
  test_case2[0][3] = 1;
  test_case2[1][0] = 0;
  test_case2[1][1] = 1;
  test_case2[1][2] = 1;
  test_case2[1][3] = 1;
  test_case2[2][0] = 0;
  test_case2[2][1] = 1;
  test_case2[2][2] = 0;
  test_case2[2][3] = 1;
  test_case2[3][0] = 1;
  test_case2[3][1] = 1;
  test_case2[3][2] = 9;
  test_case2[3][3] = 1;
  test_case2[4][0] = 0;
  test_case2[4][1] = 0;
  test_case2[4][2] = 1;
  test_case2[4][3] = 1;
  test_cases.push_back({numRows,numColumns, test_case2, 5});
  return test_cases;
}

void free_test_cases(vector<testCase> test_cases) {
  for(auto&& test_case: test_cases) {
    for(int i = 0; i < test_case.numRows; ++i) {
      delete [] test_case.area[i];
    }
    delete [] test_case.area;
  }
}

void test(ptr2minimumDistance pfcn, const char* pfcn_name) {
  auto test_cases = construct_test_cases();
  for(auto&& test_case: test_cases) {
    auto got = (*pfcn)(test_case.numRows, test_case.numColumns, test_case.area);
    if (got != test_case.expected) {
      printf("%s(%d, %d, %s) = %d\n",
             pfcn_name,
             test_case.numRows,
             test_case.numColumns,
             CPPUtility::twoDArrayIntStrC(test_case.numRows, test_case.numColumns, test_case.area).c_str(),
             got);
      free_test_cases(test_cases);
      assert(false);
    }
  }
  free_test_cases(test_cases);
}

int main() {
  ptr2minimumDistance pfcn = &minimumDistance;
  test(pfcn, FUNC_DEF_NAME(&minimumDistance));
}
