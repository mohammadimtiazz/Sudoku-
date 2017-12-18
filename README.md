# Sudoku-
This respiratory contain a code for checking sudoku solution and another code to solve unfinished sudoku matrix

sudokuSolution >>
this code only presents the part where it can tell whether a given sudoku matrix is correct or not.
It varify the funciton based on the 1 to 9 number combination row wise, col wise and 3x3 block wise

Example:
3 1 6 5 7 8 4 9 2

5 2 9 1 3 4 7 6 8

4 8 7 6 2 9 5 3 1

2 6 3 4 1 5 9 8 7

9 7 4 8 6 3 1 2 5

8 5 1 7 9 2 6 4 3

1 3 8 9 4 7 2 5 6

6 9 2 3 5 1 8 7 4

7 4 5 2 8 6 3 1 9


This above 9x9 matrix sudoku is coorect and the sudokuSolution code will varify it!!!

sudokuSolution01>>
this code presents the solution of given sudoku matrix if it is not complete. The unassigned location must have the value 0. It solve the sudoku matrix by varifing each number from 1 to 9 based on three condition check: same number can't contain in same row, col and 3x3 block location. Based on these conditions check it will assign values from 1 to 9 in the 0 valued location. 

If incase the input matrix is already solved then it will trigger the 2nd part of the code which is basically "sudokuSolution" and it will varify the input matrix


As example:
3 0 6 5 0 8 4 0 0

5 2 0 0 0 0 0 0 0

0 8 7 0 0 0 0 3 1

0 0 3 0 1 0 0 8 0

9 0 0 8 6 3 0 0 5

0 5 0 0 9 0 6 0 0

1 3 0 0 0 0 2 5 0

0 0 0 0 0 0 0 7 4

0 0 5 2 0 6 3 0 0


solution is :

3 1 6 5 7 8 4 9 2

5 2 9 1 3 4 7 6 8

4 8 7 6 2 9 5 3 1

2 6 3 4 1 5 9 8 7

9 7 4 8 6 3 1 2 5

8 5 1 7 9 2 6 4 3

1 3 8 9 4 7 2 5 6

6 9 2 3 5 1 8 7 4

7 4 5 2 8 6 3 1 9


