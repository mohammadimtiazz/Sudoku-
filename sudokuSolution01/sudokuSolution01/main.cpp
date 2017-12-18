#include <iostream>
#include <stdlib.h>
#include <vector>
#define UNASSIGNED 0

using namespace std;

int n = 9;






/////////////////////////////////////////////////////////////////////////
///This part of the code will be only activated if the input matrix already contain the full solution////////////


//Sudoku is a 9x9 matrix contain with numbers from 1 to 9
//to win a sudoku the cmbination of this 9x9 matrix needs the following characteristics
// each row needs to contain number from 1 to 9 with out repetation
// each col needs to contain number from 1 to 9 with out repetation
// each 3x3 consecutive matrix should contain number from 1 to 9 with out repetation

//For the following function below boolean represents::
//false means ->>> 0
//true means ->>> 1

//this function will check repetation of numbers from 1 to 9 in a 1D vector
bool checkBox(vector<int> &b){
	for (int i = 0; i < n; i++){
		for(int j = i + 1; j < 9; j++){
			if (b[i] == b[j])
				return false;
		}
	}
	return true;
}


//this function will check repetation of numbers 1 to 9 in each row
bool checkRow(vector<vector<int>> &t){
	vector<int> box(n);
	for(int i = 0; i < n; i++){
		for (int j = 0; j < 9; j++){
			box[j] = t[i][j];		//put row values in box vector
		}
		if (!checkBox(box))			//call checkBox to find repetation
			return false;
	}

	return true;
}


//this function will check repetation of numbers 1 to 9 in each column
bool checkCol(vector<vector<int>> &t){
	vector<int> box(n);
	for(int i = 0; i < n; i++){
		for (int j = 0; j < 9; j++){
			box[j] = t[j][i];		//put column values in box vector
		}
		if (!checkBox(box))			//call checkBox to find repetation
			return false;
	}

	return true;
}


//this function will check repetation of numbers 1 to 9 in each 3x3 matrix
bool checkSquare(vector<vector<int>> &t){
	vector<int> box(n);
	int index;
	for(int row  = 0; row <= 6; row += 3){
		for (int col = 0; col <= 6; col += 3){
			index = 0;
			for(int i = row + 0; i < row + 3; i++){
				for (int j = col + 0; j < col + 3; j++){
					box[index] = t[i][j];		//put each 3x3 matrix values in box vector
					index++;
				}
			}
			if (!checkBox(box))					//call checkBox to find repetation
				return false;
		}
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////////







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

//looking for similar values in Row
bool correspondingRowCheck(vector<vector<int>> &grid, int row, int num){
	for (int col = 0; col < n; col++){
		if (grid[row][col] == num)
			return false;
	}
	return true; 
}


//looking for similar values in col
bool correspondingColCheck(vector<vector<int>> &grid, int col, int num){
	for (int row = 0; row < n; row++){
		if (grid[row][col] == num)
			return false;
	}
	return true; 
}

//looking for similar values in box
bool correspondingBoxCheck(vector<vector<int>> &grid, int boxRow, int boxCol, int num){
	for (int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){
			if (grid[row + boxRow][col + boxCol] == num)
				return false;
		}
	}
	return true; 
}

//Check to see wheather all condition meet or not
bool isSafe(vector<vector<int>> &grid, int row, int col, int num){
	bool x = correspondingRowCheck(grid, row, num);		
	bool y =correspondingColCheck(grid, col, num);
	bool z = correspondingBoxCheck(grid, row - row%3, col - col%3, num);
	//cout << correspondingRowCheck(grid, row, num) << " " << correspondingColCheck(grid, col, num) << " " << correspondingBoxCheck(grid, row - row%3, col - col%3, num);
	//cout << x << " " << y << " " << z << endl;
	return x && y && z;
	//return correspondingRowCheck(grid, row, num) && correspondingColCheck(grid, col, num) && correspondingBoxCheck(grid, row - row%3, col - col%3, num);
}

//Solve sudoku function
bool solveSudoku(vector<vector<int>> &grid){
	int row, col;

	//find whether there is any unassigned values in the matrix or not
	if (!findUnassignedVal(grid, row, col)){
		if (checkRow(grid) && checkCol(grid) && checkSquare(grid)){
			cout << "Don't need to solve it as " << endl;
			cout << "This sudoko combinaiton is already solved" << endl;
		}
		else
			cout << "This sudoko combinaiton is wrong" << endl;
		return true;
	}


	//check number from 1 to 9 for inserting or discarding 
	for (int num = 1; num <= n; num++){
		//if this number doesn't exist in the same row, col and box then insert that value
		//in the pos r else look for the next value from 1 to 9
		if (isSafe(grid, row, col, num)){	
			grid[row][col] = num;

		if (solveSudoku(grid))	// resurssion process
			return true;

		grid[row][col] = UNASSIGNED;
		}
	}

	return false;	// forse it to no solution 
}

//print sudoku matrix
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