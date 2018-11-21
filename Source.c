#include <stdio.h>

#define MATRIX_SIZE 5

void bubleSortColumnsInDescendingOrder(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for (int row = 0; row < MATRIX_SIZE; row++)
	{
		for (int column = 0; column < MATRIX_SIZE; column++)
		{
			for (int incrementColumn = column + 1; incrementColumn < MATRIX_SIZE; incrementColumn++)
			{
				if (matrix[column][row] < matrix[incrementColumn][row])
				{
					int temptVariable = matrix[column][row];
					matrix[column][row] = matrix[incrementColumn][row];
					matrix[incrementColumn][row] = temptVariable;
				}
			}
		}
	}
}

void findMinElementInRow(int matrix[MATRIX_SIZE][MATRIX_SIZE], int matrixSumm[MATRIX_SIZE]) 
{
	for (int row = 0; row < MATRIX_SIZE; row++)
	{
		int minElement = matrix[row][0];
		for (int column = 0; column < MATRIX_SIZE; column++)
		{
			if (minElement > matrix[column][row])
			{
				minElement = matrix[column][row];
			}
		}
		matrixSumm[row] = minElement;
	}
}

void printMinElementsOfEachRow(int matrixSumm[MATRIX_SIZE])
{
  for (int matrixSummIndex = 0; matrixSummIndex < MATRIX_SIZE; matrixSummIndex++)
  {
    printf("%d-th row min = %d\n", matrixSummIndex + 1, matrixSumm[matrixSummIndex]);
  }
}

int averageValueOfMinElements(int matrixSumm[MATRIX_SIZE])
{
	int average = 0;
	int minElementsSumm = 0;

	for (int arrayIndex = 0; arrayIndex < MATRIX_SIZE; arrayIndex++)
	{
		minElementsSumm += matrixSumm[arrayIndex];
	}

	average = minElementsSumm / MATRIX_SIZE;
}

int printToConsoleMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE])
{
	for (int row = 0; row < MATRIX_SIZE; row++)
	{
		for (int column = 0; column < MATRIX_SIZE; column++)
		{
			printf("%5.0d", matrix[row][column]);
		}
		printf("\n");
	}
	puts("\n");

	return 0;
}

int main() 
{
	int matrix[MATRIX_SIZE][MATRIX_SIZE];

	for(int row = 0; row < MATRIX_SIZE; row++)
	{
		for (int column = 0; column < MATRIX_SIZE; column++)
		{
			scanf_s("%d", &matrix[row][column]);
		}
	}
	
	printf("Before sorting:\n");
	printToConsoleMatrix(matrix);

	bubleSortColumnsInDescendingOrder(matrix);

	printf("After sorting:\n");
	printToConsoleMatrix(matrix);

	int matrixSumm[MATRIX_SIZE];

	findMinElementInRow(matrix, matrixSumm);
	
	printMinElementsOfEachRow(matrixSumm);
	printf("\nAverage value of min elements of each row: %d", averageValueOfMinElements(matrixSumm));
}