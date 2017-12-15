#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int n = 9;


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






/*
Sample Sudoku Input:

3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

*/

int main(){
	vector<vector<int>> t(n, vector<int>(n));

	cout << "Enter Sudoku values: " << endl;

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> t[i][j];
		}
	}


	if (checkRow(t) && checkCol(t) && checkSquare(t))
		cout << "This sudoko combinaiton is right" << endl;
	else
		cout << "This sudoko combinaiton is wrong" << endl;

	return 0;

}
