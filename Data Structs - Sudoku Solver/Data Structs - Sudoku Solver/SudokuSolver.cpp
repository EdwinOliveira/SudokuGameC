#include "SudokuSolver.h"

/*MatrixFull Function
*If the Matrix is not empty, then it will keep trying to solve it.
*/

int MatrixFull(int SudokuMatrix[9][9]) {
	for (unsigned short int rowIndex = 0; rowIndex < 9; rowIndex++) {
		for (unsigned short int columnIndex = 0; columnIndex < 9; columnIndex++) {
			if (SudokuMatrix[rowIndex][columnIndex] == 0) { return 0; }
		}
	}

	return 1;
}

void SudokuPrincipal(int SudokuMatrix[9][9]/*, static int arrayValuesPossibles[9]*/) {

	/*memset(&arrayValuesPossibles[0], 0, sizeof(arrayValuesPossibles));*/

	unsigned short int arrayRow = 0;
	unsigned short int arrayCol = 0;

	//I was getting value by value into an array created in this function
	//So when i called an revursive state of the function, i was getting the values already stored in the array
	//So i tried to clean them on the recursive call with memset or even calling the array static to start with the array at 0 at all times.
	//
	//static int arrayValuesPossibles[9]; OLD

	int arrayValuesPossibles[9]; 

	unsigned short int flag = 0;

	if (MatrixFull(SudokuMatrix) == 1) { 
		printf("-------------------------- \n");
		printf("Sudoku Solved \n"); 
		LoopThroughtSudokuMatrix(SudokuMatrix);
		return;
	} else {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (SudokuMatrix[i][j] == 0) {
					arrayRow = i;
					arrayCol = j;
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}


	/*	for (unsigned short int i = 0; i < 9; i++) {

			if (SudokuCheckValues((i + 1), SudokuMatrix, arrayRow, arrayCol) == 1) {
				arrayValuesPossibles[i] = i + 1;
				printf("%d", arrayValuesPossibles[i]);
			}
		}*/

		for (unsigned int i = 0; i < 9; i++)
		{
			arrayValuesPossibles[i] = SudokuCheckValues((i + 1), SudokuMatrix, arrayRow, arrayCol);
		}

		for (int i = 0; i < 9; i++) {
			if (arrayValuesPossibles[i] != 0) {
				SudokuMatrix[arrayRow][arrayCol] = arrayValuesPossibles[i];
				//LoopThroughtSudokuMatrix(SudokuMatrix);
				SudokuPrincipal(SudokuMatrix/*,*/ /*arrayValuesPossibles*/);
			}
		}

		SudokuMatrix[arrayRow][arrayCol] = 0;
	}
	
}


int SudokuCheckValues(int SudokuMatrixPossibilities, int SudokuMatrix[9][9], int rowIndex, int colIndex) {

	//Verifies Verticaly
	for (unsigned short int rowAuxIT = 0; rowAuxIT < 9; rowAuxIT++) {
		if (SudokuMatrix[rowAuxIT][colIndex] == SudokuMatrixPossibilities) return 0;
	}

	//Verifies Horizontaly
	for (unsigned short int colAuxIT = 0; colAuxIT < 9; colAuxIT++) {
		if (SudokuMatrix[rowIndex][colAuxIT] == SudokuMatrixPossibilities) return 0;
	}

	unsigned short int rowStart;
	unsigned short int colStart;

	if (rowIndex >= 0 && rowIndex <= 2) rowStart = 0;
	else if (rowIndex >= 3 && rowIndex <= 5) rowStart = 3;
	else rowStart = 6;

	if (colIndex >= 0 && colIndex <= 2) colStart = 0;
	else if (colIndex >= 3 && colIndex <= 5) colStart = 3;
	else colStart = 6;

	for (unsigned short int rowStartAux = rowStart; rowStartAux < rowStart + 3; rowStartAux++) {
		for (unsigned short int colStartAux = colStart; colStartAux < colStart + 3; colStartAux++) {
			if (SudokuMatrix[rowStartAux][colStartAux] == SudokuMatrixPossibilities) return 0;
		}
	}

	return SudokuMatrixPossibilities;
}

int SudokuCheckMatrixBegin(int SudokuMatrixPossibilities, int SudokuMatrix[9][9], int rowIndex, int colIndex, int rowCount, int colCount, int boxCount) {

	rowCount = 0;
	colCount = 0;
	boxCount = 0;

	//Verifies Verticaly
	for (unsigned short int rowAuxIT = 0; rowAuxIT < 9; rowAuxIT++) {
		if (SudokuMatrix[rowAuxIT][colIndex] == SudokuMatrixPossibilities) {
			colCount++;
			if (colCount > 1) {
				return colCount; 
			}
		}
	}

	//Verifies Horizontaly
	for (unsigned short int colAuxIT = 0; colAuxIT < 9; colAuxIT++) {
		if (SudokuMatrix[rowIndex][colAuxIT] == SudokuMatrixPossibilities) {
			rowCount++;
			if (rowCount > 1) { 
				return rowCount; 
			}
		}
	}

	unsigned short int rowStart;
	unsigned short int colStart;

	if (rowIndex >= 0 && rowIndex <= 2) rowStart = 0;
	else if (rowIndex >= 3 && rowIndex <= 5) rowStart = 3;
	else rowStart = 6;

	if (colIndex >= 0 && colIndex <= 2) colStart = 0;
	else if (colIndex >= 3 && colIndex <= 5) colStart = 3;
	else colStart = 6;

	for (unsigned short int rowStartAux = rowStart; rowStartAux < rowStart + 3; rowStartAux++) {
		for (unsigned short int colStartAux = colStart; colStartAux < colStart + 3; colStartAux++) {
			if (SudokuMatrix[rowStartAux][colStartAux] == SudokuMatrixPossibilities) boxCount++;
			if (boxCount > 1) { 
				return boxCount; 
			}
		}
	}

	return 1;
}