//    Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//    Example 1:
//
//    Input:
//    [
//     [ 1, 2, 3 ],
//     [ 4, 5, 6 ],
//     [ 7, 8, 9 ]
//    ]
//    Output: [1,2,3,6,9,8,7,4,5]
//    Example 2:
//
//    Input:
//    [
//      [1, 2, 3, 4],
//      [5, 6, 7, 8],
//      [9,10,11,12]
//    ]
//    Output: [1,2,3,4,8,12,11,10,9,5,6,7]

#include <vector>
#include <cassert>

using namespace std;

class Solution
{
public:
    vector<int>
    spiralOrder( vector<vector<int>> &matrix )
    {
        if (matrix.empty())
        {
            return {};
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res(m*n);
        vector<vector<int>> visited(m, vector<int>(n));
        int x = 0, y = 0, whichdir = 0;
        // determines which direction to walk through
        // spiral requires the direction order to be: forward, downward, backward, upward
        vector<pair<int,int>> directions = {
            {0,1},   // forward
            {1,0},   // downward
            {0,-1},  // backward
            {-1,0}   // upward
        };
        for(int i = 0; i < m*n; ++i)
        {
            res[i] = matrix[x][y];
            visited[x][y] = 1;
            int tmp_x = x + directions[whichdir].first;
            int tmp_y = y + directions[whichdir].second;
            if (tmp_x < m && tmp_y < n && tmp_x >= 0 && tmp_y >= 0 && !visited[tmp_x][tmp_y])
            {
                x = tmp_x;
                y = tmp_y;
            }
            else
            {
                whichdir = (whichdir + 1) % 4;
                x += directions[whichdir].first;
                y += directions[whichdir].second;
            }
        }
        return res;
    }
};

using ptr2spiralOrder = vector<int> ( Solution::* )( vector<vector<int>> & );


void
test( ptr2spiralOrder pfcn )
{
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> output = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    assert((sol.*pfcn)( matrix ) == output );

    matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    output = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    assert((sol.*pfcn)( matrix ) == output );
}


int
main()
{
    ptr2spiralOrder pfcn = &Solution::spiralOrder;
    test(pfcn);
}
