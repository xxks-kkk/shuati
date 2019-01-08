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

use bit_vec::BitVec;
use std::char;


//TODO:
// 1. Leetcode doesn't allow us to modify the `struct Solution {}`. Thus, we need to have a new
// struct to contain `cells` and `bt` and work with our new struct throughout the solution
// 2. Test and debug current implementation

struct Solution {
    cells: Vec<Vec<Cell>>, 
    bt: Vec<(usize, usize)>,   // backtracking state - list of empty cells
}

// Enacpsulates a single cell on a Sudoku board
#[derive(Clone)]
struct Cell {
    value: usize,          // cell value 1..9 or 0 if unset
    numPossibilities: i32, // number of possible (unconstrained) values for the cell
    constraints: BitVec,   // if BitSet[v] is true the value can't be v
}

impl Cell {
    pub fn new() -> Self {
        Cell {
            value: 0,
            numPossibilities: 9,
            constraints: BitVec::from_elem(10, true)
        }
    }
}

impl Solution {
    pub fn new() -> Self {
        Solution {
            cells: vec![vec![Cell::new();  9]; 9],
            bt: Vec::new()
        }
    }
    
    /// Optimized solution (i.e., C++ one is a basic one)
    pub fn solve_sudoku(&mut self, board: &mut Vec<Vec<char>>) {
        // clear array
        self.cells.clear();
        // Decoding input board into the internal cell matrix.
        // As we do it - constraints are propagated and even additional values are set as we go
        // (in the case if it is possible to unambiguously deduce them)
        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] != '.' && !Solution::set(self, i, j, board[i][j].to_digit(10).unwrap() as usize) {
                    return; // sudoku is either incorrect or unsolvable
                }
            }
        }
        // if we're lucky we've already got a solution,
        // however, if we have empty cells we need to use backtracking to fill them
        if (!Solution::findValuesForEmptyCells(self)) {
            return; // sudoku is unsolvable
        }

        // copying the solution back to the board
        for i in 0..9 {
            for j in 0..9 {
                if self.cells[i][j].value > 0 {
                    board[i][j] = char::from_digit(self.cells[i][j].value as u32, 10).unwrap();
                }
            }
        }
    }

    /// set the value of the cell to `v`
    /// the function also propagates constraints to other cells and deduce new values where possible
    fn set(&mut self, i: usize, j: usize, v: usize) -> bool {
        if self.cells[i][j].value == v {
            return true;
        }
        if self.cells[i][j].constraints[v] {
            return false;
        }
        self.cells[i][j].value = v;
        self.cells[i][j].numPossibilities = 1;
        self.cells[i][j].constraints = BitVec::from_elem(10, true);
        self.cells[i][j].constraints.set(v, false);

        // propagting constraints
        for k in 0..9 {
            // to the row
            if i != k && !Solution::updateConstraints(self, k,j,v) {
                return false;
            }
            // to the column
            if j != k && !Solution::updateConstraints(self, i,k,v) {
                return false;
            }
            // to the 3x3 square
            let ix = (i/3)*3 + k/3;
            let jx = (j/3)*3 + k % 3;
            if ix != i && jx != j && !Solution::updateConstraints(self, ix, jx, v) {
                return false;
            }
        }
        true
    }

    /// update constraints of the cells[i][j] by excluding possibility of 'excludedValue'
    /// once there's one possibility left the function recurses back into set()
    fn updateConstraints(&mut self, i: usize, j: usize, excludedValue: usize) -> bool {
        if self.cells[i][j].constraints[excludedValue] {
            return true;
        }
        if self.cells[i][j].value == excludedValue {
            return false;
        }
        self.cells[i][j].constraints.set(excludedValue, true);
        self.cells[i][j].numPossibilities -= 1;
        if self.cells[i][j].numPossibilities > 1 {
            return true;
        }
        for v in 1..10 {
            if !self.cells[i][j].constraints[v] {
                return Solution::set(self, i, j, v);
            }
        }
        assert_eq!(true, false);
        true
    }

    /// find values for empty cells
    fn findValuesForEmptyCells(&mut self) -> bool {
        // collecting all empty cells
        self.bt.clear();
        for i in 0..9 {
            for j in 0 .. 9 {
                if self.cells[i][j].value == 0 {
                    self.bt.push((i,j));
                }
            }
        }
        // making backtracking efficient by pre-sorting empty cells by numPossibilities
        let mut bt_cpy = self.bt.clone();
        bt_cpy.sort_by(|a, b| self.cells[a.0][a.1].numPossibilities.cmp(&self.cells[b.0][b.1].numPossibilities));
        self.bt = bt_cpy;
        Solution::backtrack(self, 0)
    }

    /// Finds value for all empty cells with index >= k
    fn backtrack(&mut self, k: usize) -> bool {
        if k >= self.bt.len() {
            return true;
        }
        let i = self.bt[k].0;
        let j = self.bt[k].1;
        // fast path - only 1 possibility
        if self.cells[i][j].value > 0 {
            return Solution::backtrack(self, k+1);
        }
        // slow path > 1 possibility.
        // making snapshot of the state
        let snapshot: Vec<Vec<Cell>> = self.cells.clone();
        for v in 1..10 {
            if !self.cells[i][j].constraints[v] {
                if Solution::set(self, i, j, v) {
                    if Solution::backtrack(self, k+1) {
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

#[test]
fn test_37() {}
