/*************************************************************************
  > File Name:       bleekingInk.cc
  > Author:          Zeyuan Hu
  > Mail:            iamzeyuanhu@utexas.edu
  > Created Time:    10/24/18
  > Description:
    
    C++ Solution for BleedingInk.

    Indeed OA #18
 ************************************************************************/

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <queue>

using namespace std;

class Solution
{
public:
    void
    bleedingInk()
    {
        typedef function<bool(pair<pair<int, int>, int> item1, pair<pair<int, int>, int> item2)> Comparator;
        Comparator comp = [](pair<pair<int, int>, int> item1, pair<pair<int, int>, int> item2) -> bool
        {
            return item1.second > item2.second;
        };
        int numSubTasks;
        cin >> numSubTasks;
        for (int i = 0; i < numSubTasks; ++i)
        {
            map<pair<int, int>, int> matrix;
            int m, n;
            cin >> m >> n;
            int numDrops;
            cin >> numDrops;
            for (int j = 0; j < numDrops; ++j)
            {
                int row, col, darkness;
                cin >> row >> col >> darkness;
                matrix[pair<int, int>{row, col}] = darkness;
            }
            vector<pair<pair<int, int>, int>> vec;
            for (auto &drop: matrix)
            {
                vec.emplace_back(move(drop));
            }
            // C++: sort the map by value (http://www.techiedelight.com/sort-map-values-cpp/)
            sort(vec.begin(), vec.end(), comp);
            bleedingInkHelper(m, n, vec);
        }
    }
private:
    /**
     * Helper function to the bleedingInk
     * @param m numRows of the grid
     * @param n numCols of the grid
     * @param vec the drop vector with each pair: <<row, col>, darkness>
     */
    void
    bleedingInkHelper(int m, int n, vector<pair<pair<int, int>, int>> vec)
    {
        int totalDarkness = 0;
        vector<vector<int>> grid(m, vector<int>(n));
        for (auto &drop: vec)
        {
            int row = drop.first.first;
            int col = drop.first.second;
            int darkness = drop.second;
            if (darkness > grid[row][col])
            {
                bfs(row, col, darkness, grid);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                totalDarkness += grid[i][j];
            }
        }
        cout << totalDarkness << endl;
    }

    /**
     * Perform BFS on the grid to fill the darkness
     * @param row the x pos of the drop
     * @param col the y pos of the drop
     * @param darkness the darkness value of the drop
     * @param grid the grid
     */
    void
    bfs(int row, int col, int darkness, vector<vector<int>> &grid)
    {
        queue<pair<pair<int,int>,int>> q;
        q.push(pair<pair<int,int>,int>{pair<int,int>{row,col}, darkness});
        while(!q.empty())
        {
            auto drop = q.front();
            q.pop();
            int x = drop.first.first;
            int y = drop.first.second;
            int d = drop.second;
            grid[x][y] = max(grid[x][y], d);
            if (x > 0 && d - 1 > grid[x-1][y])
            {
                q.push(pair<pair<int,int>,int>{pair<int,int>{x-1,y}, d-1});
            }
            if (y > 0 && d - 1 > grid[x][y-1])
            {
                q.push(pair<pair<int,int>,int>{pair<int,int>{x,y-1}, d-1});
            }
            if (x < grid.size()-1 && d - 1 > grid[x+1][y])
            {
                q.push(pair<pair<int,int>,int>{pair<int,int>{x+1,y}, d-1});
            }
            if (y < grid[0].size()-1 && d - 1 > grid[x][y+1])
            {
                q.push(pair<pair<int,int>,int>{pair<int,int>{x,y+1}, d-1});
            }
        }
    }
};

using ptr2bleedingInk = void (Solution::*)();

void
test(ptr2bleedingInk pfcn, vector<string> &filenames)
{
    Solution sol;
    for (auto &filename : filenames)
    {
        std::ifstream in(filename);
        std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
        std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

        (sol.*pfcn)();

        std::cin.rdbuf(cinbuf);   //reset to standard input again
    }
}

int
main()
{
    ptr2bleedingInk pfcn = &Solution::bleedingInk;
    vector<string> filenames = {"input001.txt"};
    test(pfcn, filenames);
}