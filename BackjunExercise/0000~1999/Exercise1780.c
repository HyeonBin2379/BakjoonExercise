#include <stdio.h>
#include <stdlib.h>

int arr[2187][2187] = {0, };
int minus = 0, zero = 0, one = 0;

int isSameValue(int row, int col, int size)
{
	int value = arr[row][col];

	for (int i = row; i < row+size; i++)
	{
		for (int j = col; j < col+size; j++)
		{
			if (value != arr[i][j])
				return 0;
		}
	}
	return 1;
}
void partition(int row, int col, int size)
{
	int newSize;

	if (isSameValue(row, col, size) == 1)
	{
		switch(arr[row][col])
		{
			case -1:
				minus++;
				break;
			case 0:
				zero++;
				break;
			case 1:
				one++;
				break;
		}
		return;
	}

	newSize = size / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			partition(row + i*newSize, col + j*newSize, newSize);
		}
	}
}

int main(void)
{
	int size;

	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	partition(0, 0, size);

	printf("%d\n%d\n%d\n", minus, zero, one);
	exit(0);
}
