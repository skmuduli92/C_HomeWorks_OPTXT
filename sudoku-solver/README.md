


## Dependencies
   - gcc or clang compiler installed
   - Make tool to run make script to build and run tests
   

## Project Structure
   - sudoku.h : header file contains declaration of the function used for solving a input sudoku
   - sudoku.c : c file has the definition of the functions in sudoku.h
   - main.c   : it has 3 test methods (2 tests are from the problem doc). The  main() calls these 3 tests.
   - Makefile : make script to build and run test


## Running

There are 3 tests methods given in main.c. To build and run these tests invoke `make test`. 
This will build and run the main.c executable. It will print 3 sudoku puzzles and their solutions.

## Solver Implementation
	I have used the concept of recursion to impelement the solver for sudoku puzzles. There are other approaches such as using constraint solving to find solutions easilty for a given sudoku puzzle. But since we are dealing with a fixed sized 9x9 puzzle, I have used recursion based method as it is very easy to implement and recusion based solutions are generally very succint.

