
#ifndef __SUDOKU_H__
#define __SUDOKU_H__


#ifndef SUDOKU_SIZE
#define SUDOKU_SIZE 9
#endif

void print_sudoku(int puzzle[][SUDOKU_SIZE]);

// helper function to check if num is valid to be inserted in cell puzzle[row][col]
int is_valid_entry(int puzzle[][SUDOKU_SIZE], int row, int col, int num);

// recursive method to solve the sudoku puzzle
int solve(int puzzle[][SUDOKU_SIZE]);

// checks if the solution found by solve is valid or not
int validate_puzzle(int puzzle[][SUDOKU_SIZE]);

#endif
