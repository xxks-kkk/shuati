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

use std::char;

struct Solution {}

// Enacpsulates a single cell on a Sudoku board
#[derive(Clone)]
struct Cell {
    value: usize,           // cell value 1..9 or 0 if unset
    num_possibilities: i32, // number of possible (unconstrained) values for the cell
    constraints: Vec<bool>, // if BitSet[v] is true the value can't be v
}

impl Cell {
    pub fn new() -> Self {
        Cell {
            value: 0,
            num_possibilities: 9,
            constraints: vec![false; 10],
        }
    }
}

struct Data {
    cells: Vec<Vec<Cell>>,
    bt: Vec<(usize, usize)>, // backtracking state - list of empty cells
}

impl Data {
    pub fn new() -> Self {
        Data {
            cells: vec![vec![Cell::new(); 9]; 9],
            bt: Vec::new(),
        }
    }

    /// set the value of the cells[i][j] to `v`
    /// the function also propagates constraints to other cells and deduce new values where possible
    /// The function returns true if cells[i][j] = 'v' otherwise, returns false
    fn set(&mut self, i: usize, j: usize, v: usize) -> bool {
        // cells[i][j] = v already, return true
        if self.cells[i][j].value == v {
            return true;
        }
        // we cannot set cells[i][j] to v due to the constraints
        if self.cells[i][j].constraints[v] {
            return false;
        }
        self.cells[i][j].value = v;
        self.cells[i][j].num_possibilities = 1;
        // since we already set the value v, then it's impossible to set it to other values. Thus, we update constrainits
        self.cells[i][j].constraints = vec![true; 10];
        self.cells[i][j].constraints[v] = false;

        // propagting constraints
        for k in 0..9 {
            // to the row
            if i != k && !Data::update_constraints(self, k, j, v) {
                return false;
            }
            // to the column
            if j != k && !Data::update_constraints(self, i, k, v) {
                return false;
            }
            // to the 3x3 square
            let ix = (i / 3) * 3 + k / 3;
            let jx = (j / 3) * 3 + k % 3;
            if ix != i && jx != j && !Data::update_constraints(self, ix, jx, v) {
                return false;
            }
        }
        true
    }

    /// update constraints of the cells[i][j] by excluding possibility of 'excludedValue'
    /// once there's one possibility left the function recurses back into set()
    /// function returns true if cells[i][j] has no conflict with excludedValue; otherwise, false
    fn update_constraints(&mut self, i: usize, j: usize, excluded_value: usize) -> bool {
        // cells[i][j] cannot be set to the excluded_value
        if self.cells[i][j].constraints[excluded_value] {
            return true;
        }
        // cells[i][j] = excluded_value => there is a conflict, return false
        if self.cells[i][j].value == excluded_value {
            return false;
        }
        self.cells[i][j].constraints[excluded_value] = true;
        self.cells[i][j].num_possibilities -= 1;
        if self.cells[i][j].num_possibilities > 1 {
            // it's still possible to set to other values for cells[i][j]
            return true;
        }
        for v in 1..10 {
            if !self.cells[i][j].constraints[v] {
                return Data::set(self, i, j, v);
            }
        }
        true
    }

    /// find values for empty cells
    fn find_values_for_empty_cells(&mut self) -> bool {
        // collecting all empty cells
        self.bt.clear();
        for i in 0..9 {
            for j in 0..9 {
                if self.cells[i][j].value == 0 {
                    self.bt.push((i, j));
                }
            }
        }
        // making backtracking efficient by pre-sorting empty cells by num_possibilities
        let mut bt_cpy = self.bt.clone();
        bt_cpy.sort_by(|a, b| {
            self.cells[a.0][a.1]
                .num_possibilities
                .cmp(&self.cells[b.0][b.1].num_possibilities)
        });
        self.bt = bt_cpy;
        Data::backtrack(self, 0)
    }

    /// Finds value for all empty cells with index >= k
    /// return true if we have find values for all empty cells with index >= k; otherwise, false
    fn backtrack(&mut self, k: usize) -> bool {
        if k >= self.bt.len() {
            return true;
        }
        let i = self.bt[k].0;
        let j = self.bt[k].1;
        // fast path - only 1 possibility
        if self.cells[i][j].value > 0 {
            return Data::backtrack(self, k + 1);
        }
        // slow path > 1 possibility.
        // making snapshot of the state
        let snapshot: Vec<Vec<Cell>> = self.cells.clone();
        for v in 1..10 {
            if !self.cells[i][j].constraints[v] {
                if Data::set(self, i, j, v) {
                    if Data::backtrack(self, k + 1) {
                        return true;
                    }
                }
                // restoring from snapshot,
                // note: computationally this is cheaper than alternate implementation with undoing the changes
                self.cells = snapshot.clone();
            }
        }
        false
    }
}

impl Solution {
    /// Optimized solution (i.e., C++ one is a basic one)
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        let mut data = Data::new();
        // Decoding input board into the internal cell matrix.
        // As we do it - constraints are propagated and even additional values are set as we go
        // (in the case if it is possible to unambiguously deduce them)
        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] != '.' && !data.set(i, j, board[i][j].to_digit(10).unwrap() as usize)
                {
                    return; // sudoku is either incorrect or unsolvable
                }
            }
        }
        // if we're lucky we've already got a solution,
        // however, if we have empty cells we need to use backtracking to fill them
        if !data.find_values_for_empty_cells() {
            return; // sudoku is unsolvable
        }

        // copying the solution back to the board
        for i in 0..9 {
            for j in 0..9 {
                if data.cells[i][j].value > 0 {
                    board[i][j] = char::from_digit(data.cells[i][j].value as u32, 10).unwrap();
                }
            }
        }
    }
}

#[test]
fn test_37() {
    let mut board: Vec<Vec<char>> = vec![
        vec!['5', '3', '.', '.', '7', '.', '.', '.', '.'],
        vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
        vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
        vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
        vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
        vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
        vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
        vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
        vec!['.', '.', '.', '.', '8', '.', '.', '7', '9'],
    ];
    Solution::solve_sudoku(&mut board);
    let board_correct: Vec<Vec<char>> = vec![
        vec!['5', '3', '4', '6', '7', '8', '9', '1', '2'],
        vec!['6', '7', '2', '1', '9', '5', '3', '4', '8'],
        vec!['1', '9', '8', '3', '4', '2', '5', '6', '7'],
        vec!['8', '5', '9', '7', '6', '1', '4', '2', '3'],
        vec!['4', '2', '6', '8', '5', '3', '7', '9', '1'],
        vec!['7', '1', '3', '9', '2', '4', '8', '5', '6'],
        vec!['9', '6', '1', '5', '3', '7', '2', '8', '4'],
        vec!['2', '8', '7', '4', '1', '9', '6', '3', '5'],
        vec!['3', '4', '5', '2', '8', '6', '1', '7', '9'],
    ];
    assert_eq!(board, board_correct);
}
