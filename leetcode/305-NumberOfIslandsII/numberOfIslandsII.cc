//    A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which
//    turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of
//    islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands
//    horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
//    Example:
//
//    Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
//    Output: [1,1,2,3]
//    Explanation:
//
//    Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
//
//    0 0 0
//    0 0 0
//    0 0 0
//    Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
//
//    1 0 0
//    0 0 0   Number of islands = 1
//    0 0 0
//    Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
//
//    1 1 0
//    0 0 0   Number of islands = 1
//    0 0 0
//    Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
//
//    1 1 0
//    0 0 1   Number of islands = 2
//    0 0 0
//    Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
//
//    1 1 0
//    0 0 1   Number of islands = 3
//    0 1 0
//    Follow up:
//
//    Can you do it in time complexity O(k log mn), where k is the length of the positions?

#include <vector>
#include <assert.h>

using namespace std;

class UnionFind {
public:
    explicit UnionFind(int n)
    {
        count = 0;
        for(int i = 0; i < n; ++i)
        {
            // Note: normally we would set id[i] = i but in this problem, since
            // there is no island initially, we set id[i] = -1
            id[i] = -1;
        }
        // Accordingly, sizes are all intialize to 0
        size = vector<int>(n,0);
    }

    int findId(int node)
    {
        while(id[node] != node)
        {
            id[node] = id[id[node]];
            node = id[node];
        }
        return id[node];
    }

    void unionId(int node1, int node2)
    {
        int setX = findId(node1);
        int setY = findId(node2);
        if (setX == setY)
        {
            return;
        }
        if (size[setX] > size[setY])
        {
            size[setY] += size[setX];
            id[setY] = setX;
        }
        else
        {
            size[setX] += size[setY];
            id[setX] = setY;
        }
        count--;
    }

    /**
     * Check whether given node is already in the disjoint set
     * @param node
     * @return
     */
    bool isValid(int node)
    {
        return id[node] >= 0;
    }

    /**
     * Add the given node to the disjoint set
     * @param node
     * @return
     */
    bool add(int node)
    {
        id[node] = node;
        count++;
        size[node] = 1;
    }

    /**
     * Get current number of connected components in the disjoint set
     * @return
     */
    int getCount()
    {
        return count;
    }

private:
    int count; // # of connected components
    vector<int> id;
    vector<int> size;
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<vector<int>> board(m, vector<int>(n));
        auto s = UnionFind(m*n);
        vector<int> res;

        for(auto& pos: positions)
        {
            int x = pos.first;
            int y = pos.second;
            vector<int> tmp;
            // check pos's neighbors to see if they are in the existing islands or not
            if (x > 0 && s.isValid((x-1)*n + y))
            {
                tmp.push_back((x-1)*n + y);
            }
            if (y > 0 && s.isValid(x*n + y-1))
            {
                tmp.push_back(x*n + y-1);
            }
            if (x < m - 1 && s.isValid((x+1)*n + y))
            {
                tmp.push_back((x+1)*n + y);
            }
            if (y < n - 1 && s.isValid(x*n + y+1))
            {
                tmp.push_back(x*n + y+1);
            }
            int node = x*n + y;
            for(auto& neighbor: tmp)
            {
                s.unionId(node, neighbor);
            }
            res.push_back(s.getCount());
        }

        return res;
    }
};

using ptr2numIslands2 = vector<int> (Solution::*)(int, int, vector<pair<int,int>>&);

void test(ptr2numIslands2 pfcn)
{
    Solution sol;
    int m = 3;
    int n = 3;
    vector<pair<int,int>> positions = {
        {0,0}, {0,1}, {1,2}, {2,1}
    };
    assert((sol.*pfcn)(m,n,positions) == vector<int>{1,1,2,3});
}


int main()
{
    ptr2numIslands2 pfcn  = &Solution::numIslands2;
    test(pfcn);
}