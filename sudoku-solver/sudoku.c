
#include <stdio.h>
#include "sudoku.h"


void print_sudoku(int puzzle[][SUDOKU_SIZE]) {
  for (int i = 0; i < SUDOKU_SIZE; ++i) {
    for (int j = 0; j < SUDOKU_SIZE; ++j) {
      printf("%d ", puzzle[i][j]);
    }
    printf("\n");
  }
}

int is_valid_entry(int puzzle[][SUDOKU_SIZE], int row, int col, int num) {

  for (int i = 0; i < SUDOKU_SIZE; ++i) {
    // row check
    if (puzzle[row][i] == num) return 0;

    // column check
    if (puzzle[i][col] == num) return 0;
  }


  // 3x3 box check
  int start_row = (row / 3) * 3;
  int start_col = (col / 3) * 3;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (puzzle[i + start_row][j + start_col] == num) {
	return 0;
      }
    }
  }

  return 1;
}


int validate_puzzle(int puzzle[][SUDOKU_SIZE]) {

  for (int row = 0; row < SUDOKU_SIZE; ++row)
    for (int col = 0; col < SUDOKU_SIZE; ++col) {
      int d = puzzle[row][col];
      puzzle[row][col] = 0;
      if(!is_valid_entry(puzzle, row, col, d)) return 0;
      puzzle[row][col] = d;
    }

  return 1;
}

int solve(int puzzle[][SUDOKU_SIZE]) {
  int status = 0;

  for (int i = 0; i < SUDOKU_SIZE; ++i) {
    for (int j = 0; j < SUDOKU_SIZE; ++j) {

      if (puzzle[i][j] == 0) {
	for (int num = 1; num <= SUDOKU_SIZE; ++num) {
	  if (is_valid_entry(puzzle, i, j, num)) {
	    puzzle[i][j] = num;
	    status = solve(puzzle);

	    // if we found a solution, return 1
	    if (status) return 1;
                        
	    puzzle[i][j] = 0; // backtracking
	  }
	}

	// if none is a valid entry, then return 0
	return 0;
      }
    }
  }

  // solution found
  return 1;
}
