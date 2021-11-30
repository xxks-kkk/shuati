// LC-64
public class MinimumPathSum
{
    public int minPathSum(int[][] grid)
    {
        if (grid.length == 0) {
            return 0;
        }
        int m = grid.length;
        int n = grid[0].length;
        // d[i][j] = the minimum distance to reach (i,j)
        int[][] d = new int[m][n];
        /*
          We can combine d[0][0] and three for loops into one
          nested for loops. I leave them like this to illustrate
          general DP thinking. See how to do so:
          https://leetcode.com/problems/minimum-path-sum/discuss/344980/Java.-Details-from-Recursion-to-DP.
         */
        d[0][0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            d[0][j] = d[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            d[i][0] = d[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                d[i][j] = grid[i][j] + Math.min(d[i][j - 1], d[i - 1][j]);
            }
        }
        return d[m - 1][n - 1];
    }
}
