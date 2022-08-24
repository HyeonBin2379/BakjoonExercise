#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MID 50

int table[101][101][101] = {0, };

int function(int i, int j, int k)
{
	int l = i + MID;
	int m = j + MID;
	int n = k + MID;

	if (table[l][m][n] != 0)
		return table[l][m][n];

	if (i <= 0 || j <= 0 || k <= 0)
		table[l][m][n] = 1;
	else if (i > 20 || j > 20 || k > 20)
		table[l][m][n] = function(20, 20, 20);
	else if (i < j && j < k)
		table[l][m][n] = function(i, j, k-1) + function(i, j-1, k-1) - function(i, j-1, k-1);
	else
		table[l][m][n] = function(i-1, j, k) + function(i-1, j-1, k) + function(i-1, j, k-1) - function(i-1, j-1, k-1);

	return table[l][m][n];
}

int main(void)
{
	while (1)
	{
		int a, b, c, result;

		scanf("%d%d%d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break;

		result = function(a, b, c);
		printf("w(%d, %d, %d) = %d\n", a, b, c, result);
	}

	exit(0);
}
