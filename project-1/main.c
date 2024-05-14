
#include <stdio.h>

#include "sudoku.h"



void run_test3() {

  printf("Puzzle 3: \n");  
  int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},
		    {1, 9, 0, 4, 7, 0, 6, 0, 8},
		    {0, 5, 2, 8, 1, 9, 4, 0, 7},
		    {2, 0, 0, 0, 4, 8, 0, 0, 0},
		    {0, 0, 9, 0, 0, 0, 5, 0, 0},
		    {0, 0, 0, 7, 5, 0, 0, 0, 9},
		    {9, 0, 7, 3, 6, 4, 1, 8, 0},
		    {5, 0, 6, 0, 8, 1, 0, 7, 4},
		    {0, 8, 0, 0, 0, 0, 0, 0, 0}};

  printf("problem:\n");
  printf("--------\n");  
  print_sudoku(puzzle);
  printf("\n");

  printf("solution:\n");
  printf("--------\n");  

  if (solve(puzzle)) {
    print_sudoku(puzzle);
    if(validate_puzzle(puzzle))
      printf("\n(validated solution)\n");    
  }
  else printf("No solution exists\n");

  printf("\n");  

}




void run_test2() {

  printf("Puzzle 2: \n");
  
  int puzzle[9][9] = {{0, 0, 2, 0, 0, 0, 0, 4, 1},
		      {0, 0, 0, 0, 8, 2, 0, 7, 0},
		      {0, 0, 0, 0, 4, 0, 0, 0, 9},
		      {2, 0, 0, 0, 7, 9, 3, 0, 0},
		      {0, 1, 0, 0, 0, 0, 0, 8, 0},
		      {0, 0, 6, 8, 1, 0, 0, 0, 4},
		      {1, 0, 0, 0, 9, 0, 0, 0, 0},
		      {0, 6, 0, 4, 3, 0, 0, 0, 0},
		      {8, 5, 0, 0, 0, 0, 4, 0, 0}};

  printf("problem:\n");
  printf("--------\n");  
  print_sudoku(puzzle);
  printf("\n");

  printf("solution:\n");
  printf("--------\n");  

  if (solve(puzzle)) {
    print_sudoku(puzzle);
    if(validate_puzzle(puzzle))
      printf("\n(validated solution)\n");    
  }
  else printf("No solution exists\n");

  printf("\n");  
  
}

void run_test1() {

  printf("Puzzle 1: \n");
  
  int puzzle[9][9] = {{0, 1, 3, 8, 0, 0, 4, 0, 5},
		      {0, 2, 4, 6, 0, 5, 0, 0, 0},
		      {0, 8, 7, 0, 0, 0, 9, 3, 0},
		      {4, 9, 0, 3, 0, 6, 0, 0, 0},
		      {0, 0, 1, 0, 0, 0, 5, 0, 0},
		      {0, 0, 0, 7, 0, 1, 0, 9, 3},
		      {0, 6, 9, 0, 0, 0, 7, 4, 0},
		      {0, 0, 0, 2, 0, 7, 6, 8, 0},
		      {1, 0, 2, 0, 0, 8, 3, 5, 0}};

  printf("problem:\n");
  printf("--------\n");  
  print_sudoku(puzzle);
  printf("\n");

  printf("solution:\n");
  printf("--------\n");  

  if (solve(puzzle)) {
    print_sudoku(puzzle);
    if(validate_puzzle(puzzle))
      printf("\n(validated solution)\n");    
  }
  else printf("No solution exists\n");

  printf("\n");  
}



int main(void) {
  run_test1();
  run_test2();
  run_test3();
  return 0;
}
