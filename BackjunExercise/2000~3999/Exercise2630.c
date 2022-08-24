#include <stdio.h>
#include <stdlib.h>

int arr[128][128] = {0, };

int blue = 0, white = 0;

int isAllColorSame(int row, int col, int size)
{
	int color = arr[row][col];

	for (int i = row; i < row+size; i++)
	{
		for (int j = col; j < col+size; j++)
		{
			if (color != arr[i][j])
				return 0;
		}
	}
	return 1;
}
void partition(int row, int col, int size)
{
	int newSize;

	if (isAllColorSame(row, col, size) == 1)
	{
		if (arr[row][col] == 0)
			white++;
		else
			blue++;
		return;
	}

	newSize = size / 2;

	partition(row, col, newSize);
	partition(row, col + newSize, newSize);
	partition(row + newSize, col, newSize);
	partition(row + newSize, col + newSize, newSize);
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

	printf("%d\n%d\n", white, blue);
	exit(0);
}
