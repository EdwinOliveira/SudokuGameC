#include "SudokuSolver.h"

void main() {

	CreateSudokuMatrix();

	system("pause");
}

void CreateSudokuMatrix() {

	//Defines Matrix Rows;
	unsigned short const int matrixRows = 9;
	//Defines Matrix Cols;
	unsigned short const int matrixCols = 9;
	//Creates the Array;
	int SudokuMatrix[matrixRows][matrixCols];

	for (unsigned short int rowIndex = 0; rowIndex < 9; rowIndex++) {
		for (unsigned short int columnIndex = 0; columnIndex < 9; columnIndex++) {
			SudokuMatrix[rowIndex][columnIndex] = 0;
		}
	}

	printf("Beginning of the Sudoku Game \n");

	//Fills in the Array
	FillArrayTxtFile(SudokuMatrix);

	for (unsigned short int i = 0; i < 9; i++) {
		if (LoopExistNumbers(SudokuMatrix, i + 1) == 0) {
			printf("Sudoku Invalid! \n");
			system("pause");
		}
	}

	SudokuPrincipal(SudokuMatrix/*, arrayValuesPossibles*/);
}

int LoopThroughtSudokuMatrix(int SudokuMatrix[9][9]) {
	printf("-------------------------- \n");
	for (unsigned short int rowIndex = 0; rowIndex < 9; rowIndex++) {
		for (unsigned short int columnIndex = 0; columnIndex < 9; columnIndex++) {
			printf("%d ", SudokuMatrix[rowIndex][columnIndex]);
		}

		printf("\n");
	}


	return 1;
}

int FillArrayTxtFile(int SudokuMatrix[9][9]) {

	FILE * ptrsudokufile;

	ptrsudokufile = fopen("0.txt", "r");

	if (ptrsudokufile == NULL) return 0;

	for (unsigned short int rowIndex = 0; rowIndex < 9; rowIndex++) {
		for (unsigned short int columnIndex = 0; columnIndex < 9; columnIndex++) {
			fscanf(ptrsudokufile, "%1d ", &SudokuMatrix[rowIndex][columnIndex]);
		}
	}

	//Loops to Show the Array
	LoopThroughtSudokuMatrix(SudokuMatrix);

	return 1;

}

int LoopExistNumbers(int SudokuMatrix[9][9], int counterValue) {

	static unsigned short int rowCount;
	static unsigned short int colCount;
	static unsigned short int boxCount;

	for (unsigned short int arrayRow = 0; arrayRow < 9; arrayRow++) {
		for (unsigned short int arrayCol = 0; arrayCol < 9; arrayCol++) {
			if (SudokuCheckMatrixBegin(counterValue, SudokuMatrix, arrayRow, arrayCol, rowCount, colCount, boxCount) > 1) {
				return 0;
			}
		}
	}
	
	return 1;
}