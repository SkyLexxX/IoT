#include <stdio.h>

#define MATRIX_SIZE 5

void bubleSort(int arr[MATRIX_SIZE][MATRIX_SIZE]) // sorting an array by buble sort in descending order
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			for (int h = j + 1; h < MATRIX_SIZE; h++)
			{
				if (arr[j][i] < arr[h][i])
				{
					int tempt = arr[j][i];
					arr[j][i] = arr[h][i];
					arr[h][i] = tempt;
				}
			}
		}
	}
}

void find_min_elm(int arr[MATRIX_SIZE][MATRIX_SIZE], int sumArr[MATRIX_SIZE]) // findind min elements in each row of a 2d array
{
	for (int i = 0; i < MATRIX_SIZE; i++) 
	{
		int min = arr[i][0];
		for (int j = 0; j < MATRIX_SIZE; j++) 
		{
			if (min > arr[j][i]) 
			{
				min = arr[j][i];
			}
		}
		sumArr[i] = min;
	}
}

void print_min_elements_of_each_row(int sumArr[MATRIX_SIZE]) // printing all min elements in each row of a 2d array
{
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    printf("%d-th row min = %d\n", i + 1, sumArr[i]);
  }
}

int sum_arr(int sumArr[MATRIX_SIZE]) // calculating the summ of all max elements in each row of a 2d array
{
	int sum = 0;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		sum += sumArr[i];
	}
	return sum;
}

int avr_arr(int sumArr[MATRIX_SIZE]) // findind avg element in each row of a 2d array
{
	int avr = 0;
	int sum = 0;

	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		sum += sumArr[i];
	}

	 avr = sum / MATRIX_SIZE;
}

int printing(int arr[MATRIX_SIZE][MATRIX_SIZE]) // printing an array = matrix
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			printf("%5.0d", arr[i][j]);
		}
		printf("\n");
	}
	puts("\n");

	return 0;
}

int main() {

	int arr[MATRIX_SIZE][MATRIX_SIZE];

	for(int i = 0; i< MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}

	
	printf("Before sorting:\n");
	printing(arr);

	bubleSort(arr);

	printf("After sorting:\n");
	printing(arr);

	int sumArr[MATRIX_SIZE];

	find_min_elm(arr, sumArr);
	
	print_min_elements_of_each_row(sumArr);
	printf("\nAverage value of min elements of each row: %d", avr_arr(sumArr));
}