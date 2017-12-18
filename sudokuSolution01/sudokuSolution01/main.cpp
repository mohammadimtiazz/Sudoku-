#include <iostream>
#include <stdlib.h>
#include <vector>
#define UNASSIGNED 0

using namespace std;

int n = 9;

//chcecking assigned value
//Means if the matrix contain one or more zeros then findUnassignedVal will send true
// otherwise false
bool findUnassignedVal(vector<vector<int>> &grid, int &row, int &col){
	for (row = 0; row < n; row++){
		for (col = 0; col < n; col++){
			if (grid[row][col] == UNASSIGNED){
				return true;
			}

		}

	}

	return false;
}

bool correspondingRowCheck(vector<vector<int>> &grid, int row, int num){
	for (int col = 0; col < n; col++){
		if (grid[row][col] == num)
			return false;
	}
	return true; 
}


bool correspondingColCheck(vector<vector<int>> &grid, int col, int num){
	for (int row = 0; row < n; row++){
		if (grid[row][col] == num)
			return false;
	}
	return true; 
}

bool correspondingBoxCheck(vector<vector<int>> &grid, int boxRow, int boxCol, int num){
	for (int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){
			if (grid[row + boxRow][col + boxCol] == num)
				return false;
		}
	}
	return true; 
}

bool isSafe(vector<vector<int>> &grid, int row, int col, int num){
	bool x = correspondingRowCheck(grid, row, num);
	bool y =correspondingColCheck(grid, col, num);
	bool z = correspondingBoxCheck(grid, row - row%3, col - col%3, num);
	//cout << correspondingRowCheck(grid, row, num) << " " << correspondingColCheck(grid, col, num) << " " << correspondingBoxCheck(grid, row - row%3, col - col%3, num);
	//cout << x << " " << y << " " << z << endl;
	return x && y && z;
	//return correspondingRowCheck(grid, row, num) && correspondingColCheck(grid, col, num) && correspondingBoxCheck(grid, row - row%3, col - col%3, num);
}

bool solveSudoku(vector<vector<int>> &grid){
	int row, col;

	//find whether there is any unassigned values in the matrix or not
	if (!findUnassignedVal(grid, row, col))
		return true;

	for (int num = 1; num <= n; num++){
		if (isSafe(grid, row, col, num)){
			grid[row][col] = num;

		if (solveSudoku(grid))
			return true;

		grid[row][col] = UNASSIGNED;
		}
	}

	return false;
}


void printSudoku(vector<vector<int>> grid){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


/*
Sample Sudoku Input:

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

*/


int main(){
	vector<vector<int>> t(n, vector<int>(n));

	//give the input sudoku challenge
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> t[i][j];
		}
	}


	if (solveSudoku(t)){
		cout << endl << endl;
		cout << "Follwing is the sudoku solution:::" << endl;
		printSudoku(t);
	}
	else{
		cout << "There is no solution of this sudoku!!!" << endl;
	}

	return 0;
}