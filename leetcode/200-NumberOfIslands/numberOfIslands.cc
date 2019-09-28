/*************************************************************************
  > File Name:       numberOfIslands.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/18/18
  > Description:
    
    Citadel Phone Interview 2018

    Follow-up: how do we use the constant space?

    For vector<vector<int>>, for grid[i][j] == 0, we set it to -1
    for visited cell, we set it to 0. Then we restore the board when we done
    by adding each cell with 1.

    Lesson: I cannot run the following program using their coderpad. Switch
    to Python if that happens.
 ************************************************************************/

#include <vector>
#include <cassert>
#include <stdio.h>
#include "cpputility.h"

#define FUNC_DEF(func, check_grid) { func, #func, check_grid },

using namespace std;

class UnionFind {
public:
  UnionFind(vector<vector<char>>& grid) {
    count = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          parent.push_back(i*n+j);
          count++;
        }
        else {
          parent.push_back(-1);
        }
        size.push_back(1);
      }
    }
  }

  void Union(int x, int y) {
    // Implement union-by-size
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      if (size[rootX] > size[rootY]) {
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
      } else {
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
      }
      count--;
    }
  }

  int find(int x) {
    // Implement path compression
    while (parent[x] != x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  int getCount() {
    return count;
  }
private:
  vector<int> parent; // a vector of root of each connected componet
  vector<int> size;   // a vector of size of each connected componet   
  int count;          // count number of connected components
};

class Solution
{
public:
  // dfs (without modifying board)
  int numIslands(vector<vector<char>> &grid)
  {
      int m = grid.size();
      if (m == 0)
      {
          return 0;
      }
      int n = grid[0].size();
      int count = 0;
      for (int i = 0; i < m; ++i)
      {
          for (int j = 0; j < n; ++j)
          {
              if (grid[i][j] == '1')
              {
                  dfs(grid, i, j);
                  count++;
              }
              else if (grid[i][j] == '0')
              {
                  grid[i][j] = 'a';
              }
          }
      }
      // Restore the board
      for (int i = 0; i < m; ++i)
      {
          for (int j = 0; j < n; ++j)
          {
              if (grid[i][j] == 'a')
              {
                  grid[i][j] = '0';
              }
              else if (grid[i][j] == 'b')
              {
                  grid[i][j] = '1';
              }
          }
      }
      return count;
  }

  // union-find
  // runtime: O(mn) where m is the number of rows and n is the number of columns.
  //          Union operation essentially takes constant time when UnionFind is implemented
  //          with both path compression and union by size.
  // space:   O(mn) as required by UnionFind data structure.
  int numIslands2(vector<vector<char>>& grid) {
    int num_row = grid.size();
    if (num_row == 0) {
      return 0;
    }
    int num_col = grid[0].size();
    UnionFind uf (grid);
    for(int i = 0; i < num_row; ++i) {
      for(int j = 0; j < num_col; ++j) {
        if (grid[i][j] == '1') {
          grid[i][j] = '0';
          if (j > 0 && grid[i][j-1] == '1') uf.Union(i*num_col+j, i*num_col + j-1);
          if (i > 0 && grid[i-1][j] == '1') uf.Union(i*num_col+j, (i-1)*num_col + j);
          if (j < num_col-1 && grid[i][j+1] == '1') uf.Union(i*num_col+j, i*num_col + j+1);
          if (i < num_row-1 && grid[i+1][j] == '1') uf.Union(i*num_col+j, (i+1)*num_col + j);
        }
      }
    }
    return uf.getCount();
  }

  // dfs (with modifying board)
  // note: this version is much cleaner than dfs (wihtout modifying board) version
  //       If interviewer not noted, use this version
  int numIslands3(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        count += grid[i][j] - '0';
        dfs3(grid, i, j, m, n);
      }
    }
    return count;
  }
private:
  void dfs(vector<vector<char>> &grid, int i, int j)
  {
    grid[i][j] = 'b';
    int m = grid.size();
    int n = grid[0].size();
    if (i > 0 && grid[i-1][j] == '1')   dfs(grid, i-1, j);
    if (i < m-1 && grid[i+1][j] == '1') dfs(grid, i+1, j);
    if (j > 0 && grid[i][j-1] == '1')   dfs(grid, i, j-1);
    if (j < n-1 && grid[i][j+1] == '1') dfs(grid, i, j+1);
  }

  void dfs3(vector<vector<char>> &grid, int i, int j, int m, int n)
  {
    if (grid[i][j] == '0') return;
    grid[i][j] = '0';
    if (i > 0 && grid[i-1][j] == '1')   dfs3(grid, i-1, j, m, n);
    if (i < m-1 && grid[i+1][j] == '1') dfs3(grid, i+1, j, m, n);
    if (j > 0 && grid[i][j-1] == '1')   dfs3(grid, i, j-1, m, n);
    if (j < n-1 && grid[i][j+1] == '1') dfs3(grid, i, j+1, m, n);    
  }
};

using ptr2numIslands = int (Solution::*)(vector<vector<char>> &);

struct testFuncsInfo{
  ptr2numIslands pfcn;
  const char* func_name;
  bool check_grid;
};

void
test(ptr2numIslands pfcn, const char* func_name, bool check_grid)
{
    Solution sol;
    struct testCase {
      vector<vector<char>> grid;
      int expected;
    };
    vector<testCase> test_cases = {
      {{
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
        }, 1},
      {{
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
        }, 3},
    };
    for(auto&& test_case: test_cases) {
      auto grid2(test_case.grid);
      int got = (sol.*pfcn)(test_case.grid);
      if (got != test_case.expected) {
        // check if the function result is correct
        printf("%s(%s) = %s\n",
               func_name,
               CPPUtility::matrixStr(grid2).c_str(),
               to_string(got).c_str());
      }
      if (check_grid && grid2 != test_case.grid) {
        // check if board is modified after invoking function
        printf("%s(%s) modified grid: %s\n",
               func_name,
               CPPUtility::matrixStr(grid2).c_str(),
               CPPUtility::matrixStr(test_case.grid).c_str()
          );
      }
    }
};

int
main()
{
  vector<testFuncsInfo> func_array = {
    FUNC_DEF(&Solution::numIslands, true)
    FUNC_DEF(&Solution::numIslands2, false)
    FUNC_DEF(&Solution::numIslands3, false)
  };
  for(auto&& func : func_array) {
    test(func.pfcn, func.func_name, func.check_grid);
  }
}
