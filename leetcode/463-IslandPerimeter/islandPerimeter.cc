//    You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.
//
//    Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water,
//    and there is exactly one island (i.e., one or more connected land cells).
//
//    The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a
//    square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
//
//
//
//    Example:
//
//    Input:
//    [[0,1,0,0],
//     [1,1,1,0],
//     [0,1,0,0],
//     [1,1,0,0]]
//
//    Output: 16

#include <vector>
#include <unordered_set>
#include <cassert>
#include <functional>

using namespace std;

class Solution
{
public:
    /**
     * The idea here is that each land cell contributes as many lines in perimeter as it's surrounded by water / boundary.
     * @param grid
     * @return
     */
    int
    islandPerimeter(vector<vector<int>> &grid)
    {
        // We don't have to use this if we can modify the grid
        // Simply mark grid[i][j] = -1 for visited.
        unordered_set<pair<int, int>, pair_hash> visited;
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1 && visited.find(pair<int, int>{i, j}) == visited.end())
                {
                    dfs(grid, visited, ans, i, j);
                }
            }
        }
        return ans;
    }

    /**
     * - find how many 1 in the map. If without the consideration of surrounding cells, the total perimeter should be the
     * total amount of 1 times 4.
     * - find how many cell walls that connect with both lands. We need to deduct twice of those lines from total perimeter
     * (we times two because a side is shared by two adjacent squares. When we count initially, we count this shared side as
     * two sides.)
     * @param grid
     * @return
     */
    int
    islandPerimeter2(vector<vector<int>> &grid)
    {
        int count = 0, repeat = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                    if (i != 0 && grid[i - 1][j] == 1)
                        repeat++;
                    if (j != 0 && grid[i][j - 1] == 1)
                        repeat++;
                }
            }
        }
        return 4 * count - repeat * 2;
    }
private:
    // C++: how we add custom hash so that we can have pair<> in an unordered_set
    struct pair_hash
    {
        // C++: function call operator overloading (primer p.577)
        // the function will be invoked as:
        // pair_hash hash;
        // hash(pair<int,int>{3,5});
        // inline: function expanded "in line" at each call. Note that
        // function marked with inline is only request to the compiler. Compiler may choose to ignore this request.
        inline std::size_t
        operator()(const std::pair<int, int> &v) const
        {
            return v.first * 31 + v.second;
        }
    };

    void
    dfs(vector<vector<int>> &grid,
        unordered_set<pair<int, int>, pair_hash> &visited,
        int &ans,
        int i,
        int j
    )
    {
        if (i < 0 || j >= grid[0].size() || i >= grid.size() || j < 0 || grid[i][j] == 0
            || visited.find(pair<int, int>{i, j}) != visited.end())
        {
            return;
        }
        // CRITICAL: DFS mark visit inside the dfs function instead of the caller function (e.g. islandPerimeter)
        // because if we only mark the visited inside the caller, all the rest of recursion dfs calls will not mark any
        // node we've visited.
        visited.insert(pair<int, int>{i, j});
        // be careful with conditions here, we still need to count when we hit the boundaries. Normally, for example,
        // we have (i > 0 && grid[i-1][j]). However, for this problem, we need to count when we at boundry position.
        ans = ans +
            (i - 1 < 0 || grid[i - 1][j] == 0) +
            (i + 1 >= grid.size() || grid[i + 1][j] == 0) +
            (j - 1 < 0 || grid[i][j - 1] == 0) +
            (j + 1 >= grid[0].size() || grid[i][j + 1] == 0);
        dfs(grid, visited, ans, i - 1, j);
        dfs(grid, visited, ans, i + 1, j);
        dfs(grid, visited, ans, i, j - 1);
        dfs(grid, visited, ans, i, j + 1);
    }
};

using ptr2islandPerimeter = int (Solution::*)(vector<vector<int>> &grid);

void
test(ptr2islandPerimeter pfcn)
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    assert((sol.*pfcn)(grid) == 16);
}

int
main()
{
    ptr2islandPerimeter pfcn = &Solution::islandPerimeter;
    test(pfcn);

    pfcn = &Solution::islandPerimeter2;
    test(pfcn);
}