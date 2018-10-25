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

using namespace std;

class Solution
{
public:
    // dfs
    int
    numIslands(vector<vector<char>> &grid)
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
private:
    void
    dfs(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = 'b';
        int m = grid.size();
        int n = grid[0].size();
        if (i > 0 && grid[i-1][j] == '1')
        {
            dfs(grid, i-1, j);
        }
        if (i < m-1 && grid[i+1][j] == '1')
        {
            dfs(grid, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == '1')
        {
            dfs(grid, i, j-1);
        }
        if (j < n-1 && grid[i][j+1] == '1')
        {
            dfs(grid, i, j+1);
        }
    }
};

using ptr2numIslands = int (Solution::*)(vector<vector<char>> &);

void
test(ptr2numIslands pfcn)
{
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    auto grid2(grid);
    assert((sol.*pfcn)(grid) == 1);
    assert(grid2 == grid);

    grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    grid2 = grid;
    assert((sol.*pfcn)(grid) == 3);
    assert(grid2 == grid);
};

int
main()
{
    ptr2numIslands pfcn = &Solution::numIslands;
    test(pfcn);
}