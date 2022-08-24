#include <stdio.h>
#include <stdlib.h>

int matrix1[100][100] = {0, };
int matrix2[100][100] = {0, };
int result[100][100] = {0, };

int main(void)
{
	int row1, col1, row2, col2;
	int i, j, k;

	scanf("%d%d", &row1, &col1);
	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col1; j++)
		{
			scanf("%d", &matrix1[i][j]);
		}
	}

	scanf("%d%d", &row2, &col2);
	for (i = 0; i < row2; i++)
	{
		for (j = 0; j < col2; j++)
		{
			scanf("%d", &matrix2[i][j]);
		}
	}

	for (i = 0; i < col2; i++)
	{
		for (j = 0; j < row1; j++)
		{
			for (k = 0; k < col1; k++)
			{
				result[j][i] += matrix1[j][k]*matrix2[k][i];
			}
		}
	}

	for (i = 0; i < row1; i++)
	{
		for (j = 0; j < col2; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	exit(0);
}
