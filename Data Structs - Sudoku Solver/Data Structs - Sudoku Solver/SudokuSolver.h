#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

void CreateSudokuMatrix();

int MatrixFull(int SudokuMatrix[9][9]);

int LoopThroughtSudokuMatrix(int SudokuMatrix[9][9]);

int FillArrayTxtFile(int SudokuMatrix[9][9]);

int SudokuCheckValues(int SudokuMatrixPossibilities,int SudokuMatrix[9][9], int rowIndex, int colIndex);

void SudokuPrincipal(int SudokuMatrix[9][9]/*, static int arrayValuesPossibles[9]*/);

int SudokuCheckMatrixBegin(int SudokuMatrixPossibilities, int SudokuMatrix[9][9], int rowIndex, int colIndex, int rowCount, int colCount, int boxCount);

int LoopExistNumbers(int SudokuMatrix[9][9], int counterValue);