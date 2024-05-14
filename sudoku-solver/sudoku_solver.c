#include <stdio.h>

#define SUDOKU_SIZE 9

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


void test1() {
    int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},
                      {1, 9, 0, 4, 7, 0, 6, 0, 8},
                      {0, 5, 2, 8, 1, 9, 4, 0, 7},
                      {2, 0, 0, 0, 4, 8, 0, 0, 0},
                      {0, 0, 9, 0, 0, 0, 5, 0, 0},
                      {0, 0, 0, 7, 5, 0, 0, 0, 9},
                      {9, 0, 7, 3, 6, 4, 1, 8, 0},
                      {5, 0, 6, 0, 8, 1, 0, 7, 4},
                      {0, 8, 0, 0, 0, 0, 0, 0, 0}};

    

    if (solve(puzzle)) print_sudoku(puzzle);
    else printf("No solution exists\n");

}


void test2() {

    int puzzle[9][9] = {{0, 0, 2, 0, 0, 0, 0, 4, 1},
                        {0, 0, 0, 0, 8, 2, 0, 7, 0},
                        {0, 0, 0, 0, 4, 0, 0, 0, 9},
                        {2, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 9, 0, 0, 0, 5, 0, 0},
                        {0, 0, 0, 7, 5, 0, 0, 0, 9},
                        {9, 0, 7, 3, 6, 4, 1, 8, 0},
                        {5, 0, 6, 0, 8, 1, 0, 7, 4},
                        {0, 8, 0, 0, 0, 0, 0, 0, 0}};


    if (solve(puzzle)) print_sudoku(puzzle);
    else printf("No solution exists\n");
}

int main(void) {
    test1();
    test2();
    return 0;
}
