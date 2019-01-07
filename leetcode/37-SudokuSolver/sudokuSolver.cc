// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

//     Each of the digits 1-9 must occur exactly once in each row.
//     Each of the digits 1-9 must occur exactly once in each column.
//     Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
//     sub-boxes of the grid.

// Empty cells are indicated by the character '.'.

// A sudoku puzzle...

// ...and its solution numbers marked in red.

// Note:

//     The given board contain only digits 1-9 and the character '.'.
//     You may assume that the given Sudoku puzzle will have a single unique
//     solution. The given board size is always 9x9.

#include <assert.h>
#include <vector>

using namespace std;

class Solution
{
public:
  // Try 1 through 9 for each cell. Time complexity: 9^m (m = the number of blanks to be filled in)
  void solveSudoku(vector<vector<char>> &board)
  {
    if (board.size() == 0)
      return;
    solve(board);
  }

private:
  bool solve(vector<vector<char>> &board)
  {
    for (int i = 0; i < board.size(); ++i)
    {
      for (int j = 0; j < board[0].size(); ++j)
      {
        if (board[i][j] == '.')
        {
          for (char k = '1'; k <= '9'; ++k)
          {
            if (isValid(i, j, board, k))
            {
              board[i][j] = k;
              if (solve(board))
              {
                return true;
              }
              board[i][j] = '.'; // backtracking
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  bool isValid(int i, int j, vector<vector<char>> &board, char k)
  {
    for (int l = 0; l < 9; ++l)
    {
      // Each of the digits 1-9 must occur exactly once in each column.
      if (board[i][l] == k)
        return false;
      // Each of the digits 1-9 must occur exactly once in each row
      if (board[l][j] == k)
        return false;
      // Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
      // sub-boxes of the grid.
      if (board[3 * (i / 3) + l / 3][3 * (j / 3) + l % 3] == k)
        return false;
    }
    return true;
  }
};

using ptr2solveSudoku = void (Solution::*)(vector<vector<char>> &);

void test(ptr2solveSudoku pfcn)
{
  Solution sol;
  vector<vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  (sol.*pfcn)(board);
  vector<vector<char>> solved_board{
      {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
      {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
      {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
      {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
      {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
      {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
      {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
      {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
      {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
  assert(board == solved_board);
}

int main()
{
  ptr2solveSudoku pfcn = &Solution::solveSudoku;
  test(pfcn);
}
