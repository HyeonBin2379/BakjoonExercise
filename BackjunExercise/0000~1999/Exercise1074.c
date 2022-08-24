#include <stdio.h>
#include <stdlib.h>

typedef struct tagTable
{
	int **arr;
} Table;

void partition(Table *table, int row, int col, int size)
{
	static int value = 0;
	int newSize;
	int newStart;

	if (size == 2)
	{
		int i = 0, j = 0;
		for (i = row; i < row+size; i++)
		{
			for (j = col; j < col+size; j++)
			{
				table->arr[i][j] = value++;
			}
		}
		return;
	}

	newSize = size / 2;

	partition(table, row, col, newSize);
	partition(table, row, col + newSize, newSize);
	partition(table, row + newSize, col, newSize);
	partition(table, row + newSize, col + newSize, newSize);
}
void printArray(Table *table, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%2d ", table->arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int power(int expo)
{
	int base = 2;

	if (expo == 0)
		return 1;
	else if (expo == 1)
		return base;
	else
	{
		if (expo % 2 == 0)
		{
			int newBase = power(expo/2);
			return newBase * newBase;
		}
		else
		{
			int newBase = power(expo/2);
			return newBase * newBase * base;
		}
	}
}
int main(void)
{
	int expo, row, col, size;
	Table table;

	scanf("%d%d%d", &expo, &row, &col);
	size = power(expo);
	table.arr = (int **)calloc(size, sizeof(int *));
	for (int i = 0; i < size; i++)
	{
		table.arr[i] = (int *)calloc(size, sizeof(int));
	}

	// row, col: 배열의 시작 행, 열
	if (size > 1)
		partition(&table, 0, 0, size);
	printArray(&table, size);
	printf("%d\n", table.arr[row][col]);

	for (int i = 0; i < size; i++)
	{
		free(table.arr[i]);
	}
	free(table.arr);
	exit(0);
}
