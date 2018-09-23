#include <vector>
#include <cassert>
#include <string>
#include <fstream>

#include "cpputility.h"

using namespace std;

class Solution
{
public:
    // straightforward solution
    void
    gameOfLife( vector<vector<int>> &board )
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> updated_board( m, vector<int>( n ));
        for ( int i = 0; i < m; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                int live = 0;
                int dead = 0;
                if ((i - 1) >= 0 && (j - 1) >= 0 )
                {
                    (board[i - 1][j - 1] == 1) ? live++ : dead++;
                }
                if ((i - 1) >= 0 )
                {
                    (board[i - 1][j] == 1) ? live++ : dead++;
                }
                if ((i - 1) >= 0 && (j + 1) < n )
                {
                    (board[i - 1][j + 1] == 1) ? live++ : dead++;
                }
                if ((j - 1) >= 0 )
                {
                    (board[i][j - 1] == 1) ? live++ : dead++;
                }
                if ((j + 1) < n )
                {
                    (board[i][j + 1] == 1) ? live++ : dead++;
                }
                if ((i + 1) < m && (j - 1) >= 0 )
                {
                    (board[i + 1][j - 1] == 1) ? live++ : dead++;
                }
                if ((i + 1) < m )
                {
                    (board[i + 1][j] == 1) ? live++ : dead++;
                }
                if ((i + 1) < m && (j + 1) < n )
                {
                    (board[i + 1][j + 1] == 1) ? live++ : dead++;
                }
                if ( board[i][j] == 1 )
                {
                    if ( live < 2 )
                        updated_board[i][j] = 0;
                    if ( live == 2 || live == 3 )
                        updated_board[i][j] = 1;
                    if ( live > 3 )
                        updated_board[i][j] = 0;
                }
                if ( board[i][j] == 0 && live == 3 )
                {
                    updated_board[i][j] = 1;
                }
            }
        }
        board = move( updated_board );
    }


    // Solution uses 2 bits
    void
    gameOfLife2( vector<vector<int>> &board )
    {
        int m = board.size();
        int n = board[0].size();
        for ( int i = 0; i < m; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                int lives = 0;
                // We first check neighbours
                for ( int x = max( i - 1, 0 ); x <= min( i + 1, m - 1 ); ++x )
                {
                    for ( int y = max( j - 1, 0 ); y <= min( j + 1, n - 1 ); ++y )
                    {
                        lives += board[x][y] & 1;
                    }
                }
                // we count board[i][j] in the lives, which should be removed because it is not neighbor
                lives -= board[i][j] & 1;

                // In the beginning, every 2nd bit is 0;
                // We only need to care about when the 2nd bit will become 1
                // [2nd bit, 1st bit] = [next state, current state]
                if ( board[i][j] == 1 && lives >= 2 && lives <= 3 )
                {
                    board[i][j] = 3; // Make the 2nd bit 1: 01 --> 11
                }
                if ( board[i][j] == 0 && lives == 3 )
                {
                    board[i][j] = 2; // Make the 2nd bit 1: 00 --> 10
                }
            }
        }
        for ( int i = 0; i < m; ++i )
        {
            for ( int j = 0; j < n; ++j )
            {
                board[i][j] >>= 1; // Get the 2nd state
            }
        }
    }
};

class Solution2
{
public:
    // Solution for when board is too large for the memory
    void
    gameOfLife( const string& inputFile, const string& outputFile )
    {
        Solution sol;
        ifstream infile(inputFile);
        ofstream outfile(outputFile);
        string line;
        vector<int> tokens;
        vector<vector<int>> board;
        while (std::getline(infile, line))
        {
            tokens = CPPUtility::convertToInt(CPPUtility::split(line, ","));
            board.emplace_back(tokens);
            if (board.size() == 2)
            {
                // we're at the 1st line
                auto board2(board);
                sol.gameOfLife2(board2);
                for(auto & cell: board2[0])
                {
                    outfile << cell << ",";
                }
                outfile << "\n";
            }
            else if (board.size() == 3)
            {
                // general case: we have 3 lines in the board, and we only care about the middle line
                auto board2(board);
                sol.gameOfLife2(board2);
                for(auto & cell: board2[1])
                {
                    outfile << cell << ",";
                }
                outfile << "\n";
            }
            if (board.size() == 3)
            {
                board.erase(board.begin());
            }
        }
        // process the last line
        auto board2(board);
        sol.gameOfLife2(board2);
        for (auto & cell: board2[1])
        {
            outfile << cell << ",";
        }
        outfile << "\n";
        outfile.close();
        infile.close();
    }
};

using ptr2gameOfLife = void ( Solution::* )( vector<vector<int>> & );


void
test( ptr2gameOfLife pfcn )
{
    Solution sol;
    vector<vector<int>> board =
        {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
        };
    vector<vector<int>> ans =
        {
            {0, 0, 0},
            {1, 0, 1},
            {0, 1, 1},
            {0, 1, 0}
        };
    (sol.*pfcn)( board );
    assert( board == ans );
}


int
main()
{
    ptr2gameOfLife pfcn = &Solution::gameOfLife;
    test( pfcn );
    pfcn = &Solution::gameOfLife2;
    test( pfcn );

    Solution2 sol;
    sol.gameOfLife("/Users/zeyuan/Documents/projects/shuati/leetcode/289-GameOfLife/input.txt", "output.txt");
}