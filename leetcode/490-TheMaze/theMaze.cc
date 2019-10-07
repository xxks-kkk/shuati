#include "cpputility.h"

using namespace std;

class Solution {
public:
  // DFS approach
  bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    if (maze.empty() || maze[0].empty()) return true;
    // keep track whether we have a path to destination at [i,j]
    vector<vector<int>> hasPathTable (maze.size(), vector<int>(maze[0].size(), -1));
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}}; 
    return hasPathAtPoint(maze, hasPathTable, start, destination, dirs);
  }
private:
  bool hasPathAtPoint(vector<vector<int>>& maze,
                      vector<vector<int>>& hasPathTable,
                      vector<int> start,
                      vector<int> destination,
                      const vector<pair<int,int>>& dirs) {
    int m = maze.size();
    int n = maze[0].size();
    int start_x = start[0];
    int start_y = start[1];          
    bool res = false;
    maze[start_x][start_y] = -1;    
    if (hasPathTable[start_x][start_y] != -1) return hasPathTable[start_x][start_y];
    if (start_x == destination[0] && start_y == destination[1]) {
      hasPathTable[start_x][start_y] = true;
      return true;
    }
    for(auto&& dir: dirs) {
      start_x = start[0];
      start_y = start[1];
      while(start_x >= 0 && start_x < m && start_y >= 0 && start_y < n && maze[start_x][start_y] != 1) {
        start_x += dir.first;
        start_y += dir.second;
      }
      start_x -= dir.first;
      start_y -= dir.second;
      if (maze[start_x][start_y] != -1) {
        vector<int> v = {start_x, start_y};
        res |= hasPathAtPoint(maze, hasPathTable, v, destination, dirs);        
      }
    }
    hasPathTable[start[0]][start[1]] = res;
    return res;
  }
};

using ptr2hasPath = bool (Solution::*)(vector<vector<int>>&, vector<int>&, vector<int>&);

void test(ptr2hasPath pfcn, const char* pfcn_name) {
  Solution sol;
  struct testCase {
    vector<vector<int>> maze;
    vector<int> start;
    vector<int> destination;
    bool expected;
  };
  vector<testCase> test_cases = {
    {{{0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,1,0},
      {1,1,0,1,1},
      {0,0,0,0,0}}, {0,4}, {4,4}, true},
    {{{0,0,1,0,0},
      {0,0,0,0,0},
      {0,0,0,1,0},
      {1,1,0,1,1},
      {0,0,0,0,0}}, {0,4}, {3,2}, false},    
  };
  for(auto&& test_case: test_cases) {
    bool got = (sol.*pfcn)(test_case.maze, test_case.start, test_case.destination);
    if (got != test_case.expected) {
      printf("%s(%s,%s,%s) = %s\n",
             pfcn_name,
             CPPUtility::twoDVectorStr(test_case.maze).c_str(),
             CPPUtility::oneDVectorStr(test_case.start).c_str(),
             CPPUtility::oneDVectorStr(test_case.destination).c_str(),
             !got ? "false" : "true");
      assert(false);
    }
  }
}


int main() {
  ptr2hasPath pfcn = &Solution::hasPath;
  test(pfcn, FUNC_DEF_NAME(&Solution::hasPath));
}
