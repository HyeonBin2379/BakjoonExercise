#include <stdio.h>
#include <stdlib.h>

char arr[64][64] = {0, };

int isSameValue(int row, int col, int size)
{
	char value = arr[row][col];

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
		printf("%c", arr[row][col]);
		return;
	}

	newSize = size / 2;

	printf("(");
	partition(row, col, newSize);
	partition(row, col+newSize, newSize);
	partition(row+newSize, col, newSize);
	partition(row+newSize, col+newSize, newSize);
	printf(")");
}

int main(void)
{
	int size;

	scanf("%d", &size);

	for (int i = 0; i < size; i++)
	{
		scanf("%s", arr[i]);
	}

	partition(0, 0, size);
	printf("\n");
	exit(0);
}
