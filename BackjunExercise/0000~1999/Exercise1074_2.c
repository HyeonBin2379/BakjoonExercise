#include <stdio.h>
#include <stdlib.h>

void partition(int *row, int *col, int size, int expo, int *value)
{
	if (expo == 0)
		return;

	size /= 2;

	if (*row < size)
	{
		if (*col < size)
		{
			*value += 0;
		}
		else
		{
			*col -= size;
			*value += (size*size);
		}
	}
	else
	{
		if (*col < size)
		{
			*row -= size;
			*value += 2*(size*size);
		}
		else
		{
			*col -= size;
			*row -= size;
			*value += 3*(size*size);
		}
	}
	partition(row, col, size, expo-1, value);
}
int power(int base, int expo)
{
	if (expo == 0)
		return 1;
	else if (expo == 1)
		return base;
	else
	{
		if (expo % 2 == 0)
		{
			int newBase = power(base, expo/2);
			return newBase * newBase;
		}
		else
		{
			int newBase = power(base, expo/2);
			return newBase * newBase * base;
		}
	}
}
int main(void)
{
	int expo, row, col, size;
	int value = 0;

	scanf("%d%d%d", &expo, &row, &col);
	size = power(2, expo);

	// row, col: 배열의 시작 행, 열
	partition(&row, &col, size, expo, &value);
	printf("%d\n", value);
	exit(0);
}
