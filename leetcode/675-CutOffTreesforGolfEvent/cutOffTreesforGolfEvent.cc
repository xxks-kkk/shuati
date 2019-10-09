#include "cpputility.h"
#include <queue>

using namespace std;

class Solution
{
public:
  int cutOffTree(vector<vector<int>> &forest)
  {
    if (forest.empty() || forest[0].empty())
      return 0;
    int dist = 0;
    int m = forest.size(), n = forest[0].size();
    vector<int> start = {0, 0};
    
    // {height, i, j}
    vector<tuple<int, int, int>> trees;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (forest[i][j] != 0) {
          trees.push_back({forest[i][j], i, j});
        }
      }
    }
    sort(trees.begin(), trees.end());
    
    for(int i = 0; i < trees.size(); ++i) {
      vector<int> destination = {get<1>(trees[i]), get<2>(trees[i])};
      int shortestPath = findShortestPath(forest, start, destination);
      if (shortestPath == INT_MAX) return -1;
      else dist += shortestPath;
      start = destination;
    }
    return dist;
  }
private:
  // min steps go from `start` to `destination`
  int findShortestPath(vector<vector<int>>& forest,
                        vector<int>& start,
                        vector<int>& destination) {
    int m = forest.size(), n = forest[0].size();
    queue<pair<int, int>> q;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    auto visited = vector<vector<int>>(m, vector<int>(n, 0));
    q.emplace(start[0], start[1]);
    int dist = 0;
    while (!q.empty()) {
      int num_nodes_for_current_level = q.size();
      while(num_nodes_for_current_level--) {
        auto coord = q.front(); q.pop();
        int start_x = coord.first;
        int start_y = coord.second;
        if (start_x == destination[0] && start_y == destination[1])
          return dist;        
        for (auto &&dir : dirs) {
          start_x = coord.first;
          start_y = coord.second;        
          start_x += dir.first;
          start_y += dir.second;
          if (start_x >= 0 && start_x < m &&
              start_y >= 0 && start_y < n &&
              forest[start_x][start_y] != 0 &&
              visited[start_x][start_y] != 1) {
            q.emplace(start_x, start_y);
            visited[start_x][start_y] = 1;
          }
        }
      }
      dist++;
    }
    return INT_MAX;
  }
};

using ptr2cutOffTree = int (Solution::*)(vector<vector<int>> &);

void test(ptr2cutOffTree pfcn, const char *pfcn_name)
{
  Solution sol;
  struct testCase
  {
    vector<vector<int>> forest;
    int expected;
  };
  vector<testCase> test_cases = {
    {{{1, 7, 2}, {0, 0, 5}, {8, 3, 6}}, 16},
    {{{9,7,2}, {0,0,5}, {8,3,6}}, 22},
  };
  for (auto &&test_case : test_cases)
  {
    int got = (sol.*pfcn)(test_case.forest);
    if (got != test_case.expected)
    {
      printf("%s(%s) = %d\n",
             pfcn_name,
             CPPUtility::twoDVectorStr<int>(test_case.forest).c_str(),
             got);
      assert(false);
    }
  }
}

int main()
{
  ptr2cutOffTree pfcn = &Solution::cutOffTree;
  test(pfcn, FUNC_DEF_NAME(&Solution::cutOffTree));
}
