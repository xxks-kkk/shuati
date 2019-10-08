#include "cpputility.h"

using namespace std;

class Solution {
public:
  // DFS Approach (TLE)
  int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    if (maze.empty() || maze[0].empty()) return -1;
    // shortestDistanceAtPointTable[i][j] = shortest distance to reach point [i][j] from start
    vector<vector<int>> shortestDistanceAtPointTable(maze.size(), vector<int>(maze[0].size(), INT_MAX));
    shortestDistanceAtPointTable[start[0]][start[1]] = 0;
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    shortestDistanceFromPoint(maze, start, destination, shortestDistanceAtPointTable, dirs);
    int res = shortestDistanceAtPointTable[destination[0]][destination[1]];
    return res == INT_MAX ? -1 : res;
  }
private:
  void shortestDistanceFromPoint(vector<vector<int>>& maze,
                                 vector<int>& start,
                                 vector<int>& destination,
                                 vector<vector<int>>& shortestDistanceAtPointTable,
                                 const vector<pair<int,int>>& dirs) {
    int m = maze.size();
    int n = maze[0].size();
    int start_x = start[0];
    int start_y = start[1];
    //printf("start_x: %d, start_y: %d \n %s\n", start_x, start_y, CPPUtility::twoDVectorStr<int>(shortestDistanceAtPointTable).c_str());
    if (start == destination) {
      // Don't do: shortesDistanceAtPointTable[start_x][start_y] = 0;
      return;
    }
    for (auto&& dir: dirs) {
      start_x = start[0];
      start_y = start[1];
      int dist = shortestDistanceAtPointTable[start_x][start_y];
      while (start_x >= 0 && start_x < m && start_y >= 0 && start_y < n && maze[start_x][start_y] != 1) {
        start_x += dir.first;
        start_y += dir.second;
        dist++;
      }
      start_x -= dir.first;
      start_y -= dir.second;
      dist--;
      if (dist < shortestDistanceAtPointTable[start_x][start_y]) {
        shortestDistanceAtPointTable[start_x][start_y] = dist;
        vector<int> v = {start_x, start_y};
        shortestDistanceFromPoint(maze, v, destination, shortestDistanceAtPointTable, dirs);
      }
    }
  }
};

using ptr2shortestDistance = int (Solution::*)(vector<vector<int>>&, vector<int>&, vector<int>&);

struct testFuncsInfo {
  ptr2shortestDistance pfcn;
  const char* pfcn_name;
};

void test(ptr2shortestDistance pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    vector<vector<int>> maze;
    vector<int> start;
    vector<int> destination;
    int expected;
  };
  vector<testCase> test_cases = {
    {{{0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,1,0},
      {1,1,0,1,1},
      {0,0,0,0,0}}, {0,4}, {4,4}, 12},
    {{{0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,1,0},
      {1,1,0,1,1},
      {0,0,0,0,0}}, {0,4}, {3,2}, -1},    
  };
  for(auto&& test_case: test_cases) {
    int got = (sol.*pfcn)(test_case.maze, test_case.start, test_case.destination);
    if (got != test_case.expected) {
      printf("%s(%s,%s,%s) = %d\n",
             pfcn_name,
             CPPUtility::twoDVectorStr(test_case.maze).c_str(),
             CPPUtility::oneDVectorStr(test_case.start).c_str(),
             CPPUtility::oneDVectorStr(test_case.destination).c_str(),
             got);
      assert(false);
    }
  }
}

int main() {
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::shortestDistance)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.pfcn_name);
  }
}
