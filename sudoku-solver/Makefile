

CC?=gcc


build: sudoku.h sudoku.c  main.c
	${CC} main.c sudoku.c


test: build
	./a.out



.PHONY: clean
clean:
	rm -rf *.o a.out
