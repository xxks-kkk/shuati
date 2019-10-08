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
    auto comp = [](vector<int> &a, vector<int> &b) { return a[2] > b[2]; };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    queue<vector<int>> starts;
    starts.push({0,0});
    int dist = 0;
    int m = forest.size(), n = forest[0].size();
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (forest[i][j] != 0) {
          pq.push({i, j, forest[i][j]});          
        }
      }
    }
    while(!pq.empty()) {
      auto q = pq.top(); pq.pop();
      vector<int> destination = {q[0], q[1]};
      auto start = starts.front(); starts.pop();
      int shortestPath = findShortestPath(forest, start, destination);
      if (shortestPath == -1) return -1;
      else dist += shortestPath;
      starts.push(destination);
    }
    return dist;
  }
private:
  int findShortestPath(vector<vector<int>>& forest,
                        vector<int>& start,
                        vector<int>& destination) {
    int m = forest.size(), n = forest.size();
    // shortestDistanceAtPointTable[i][j] = shortest distance to reach point
    // [i][j] from start
    vector<vector<int>> shortestDistanceAtPointTable(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    shortestDistanceAtPointTable[start[0]][start[1]] = 0;
    q.push({start[0], start[1]});
    while (!q.empty())
    {
      auto coord = q.front();
      q.pop();
      for (auto &&dir : dirs)
      {
        int start_x = coord.first;
        int start_y = coord.second;
        int dist = shortestDistanceAtPointTable[start_x][start_y];
        start_x += dir.first;
        start_y += dir.second;
        if (start_x >= 0 && start_x < m && start_y >= 0 && start_y < n && forest[start_x][start_y] != 0)
        {
          dist++;
          if (dist < shortestDistanceAtPointTable[start_x][start_y])
          {
            shortestDistanceAtPointTable[start_x][start_y] = dist;
            if (start_x != destination[0] || start_y != destination[1])
              q.push({start_x, start_y});
          }
        }
      }
    }
    int res = shortestDistanceAtPointTable[destination[0]][destination[1]];
    return res == INT_MAX ? -1 : res;    
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
