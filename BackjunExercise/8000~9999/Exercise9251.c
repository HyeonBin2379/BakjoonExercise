#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct structTable
{
	int **data;
} LCSTable;

int LCS(char *x, char *y, int i, int j, LCSTable *table)
{
	int m = 0, n = 0;

	for (m = 0; m <= i; m++)
		table->data[m][0] = 0;
	for (n = 0; n <= j; n++)
		table->data[0][n] = 0;

	for (m = 1; m <= i; m++)
	{
		for (n = 1; n <= j; n++)
		{
			if (x[m-1] == y[n-1])
			{
				table->data[m][n] = table->data[m-1][n-1] + 1;
			}
			else
			{
				table->data[m][n] = (table->data[m-1][n] > table->data[m][n-1]) ? table->data[m-1][n] : table->data[m][n-1];
			}
		}
	}
	return table->data[i][j];
}
void printTable(LCSTable *table, char *x, char *y, int lenx, int leny)
{
	int i = 0, j = 0;

	printf("%4s", "");
	for (i = 0; i < leny+1; i++)
		printf("%c ", y[i]);
	printf("\n");
	
	for (i = 0; i < lenx+1; i++)
	{
		if (i == 0)
			printf("%2s", "");
		else
			printf("%-2c", x[i-1]);

		for (j = 0; j < leny+1; j++)
		{
			printf("%d ", table->data[i][j]);
		}

		printf("\n");
	}
}
int main(void)
{
	char str1[1001] = {0, };
	char str2[1001] = {0, };
	int xlen, ylen, lcs;
	int i = 0, j = 0;
	LCSTable table;

	scanf("%s", str1);
	getchar();
	scanf("%s", str2);
	getchar();

	xlen = strlen(str1);
	ylen = strlen(str2);
	printf("%d %d\n", xlen, ylen);

	table.data = (int **)calloc((xlen+1), sizeof(int *));
	for (i = 0; i < xlen+1; i++)
	{
		table.data[i] = (int *)calloc((ylen+1), sizeof(int));
		memset(table.data[i], 0, sizeof(int) * (ylen+1));
	}
	lcs = LCS(str1, str2, xlen, ylen, &table);
	//printTable(&table, str1, str2, xlen, ylen);

	printf("%d\n", lcs);

	exit(0);
}
