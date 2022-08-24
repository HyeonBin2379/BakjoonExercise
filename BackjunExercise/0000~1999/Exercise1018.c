#include <stdio.h>
#include <stdlib.h>

void makeAns1(char (*ans)[8], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if ((i + j) % 2 == 1)
				ans[i][j] = 'B';
			else
				ans[i][j] = 'W';
		}
	}
}
void makeAns2(char (*ans)[8], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if ((i + j) % 2 == 0)
				ans[i][j] = 'B';
			else
				ans[i][j] = 'W';
		}
	}
}
void printAns(char (*ans)[8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
			printf("%c", ans[i][j]);
		printf("\n");
	}
}
void printChess(char (*chess)[50], int row)
{
	for (int i = 0; i < row; i++)
		printf("%s\n", chess[i]);
}
int findMin(int *val, int len)
{
	int min = val[0];

	for (int i = 1; i < len; i++)
		min = (val[i] < min) ? val[i] : min;

	return min;
}
int changeFirstToWhite(char (*ans1)[8], char (*chess)[50], int x, int y)
{
	int count = 0;

	for (int i = x; i < x+8; i++)
	{
		for (int j = y; j < y+8; j++)
		{
			if (chess[i][j] != ans1[i-x][j-y])
				count++;
		}
	}
	return count;
}
int changeFirstToBlack(char (*ans2)[8], char (*chess)[50], int x, int y)
{
	int count = 0;
	
	for (int i = x; i < x+8; i++)
	{
		for (int j = y; j < y+8; j++)
		{
			if (chess[i][j] != ans2[i-x][j-y])
				count++;
		}
	}
	return count;
}

int main(void)
{
	char chess[50][50] = {0, };
	char ans1[8][8] = {0, };
	char ans2[8][8] = {0, };
	int row, col, result;
	int val[3] = {32, 32, 32};

	makeAns1(ans1, 8);
	//printf("\n");
	//printAns(ans1);

	makeAns2(ans2, 8);
	//printf("\n");
	//printAns(ans2);

	scanf("%d%d ", &row, &col);
	for (int i = 0; i < row; i++)
	{
		scanf("%s", chess[i]);
	}

	for (int i = 0; i + 7 < row; i++)
	{
		for (int j = 0; j + 7 < col; j++)
		{
			val[1] = changeFirstToWhite(ans1, chess, i, j);
			val[2] = changeFirstToWhite(ans2, chess, i, j);
			val[0] = findMin(val, sizeof(val)/sizeof(val[0]));
		}
	}

	result = val[0];
	printf("%d\n", result);
	//printChess(chess, row);
	exit(0);
}
