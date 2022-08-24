#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1001
long long arr[MAXLEN][MAXLEN] = {0, };

int main(void)
{
	int n, k;
	long long result;

	scanf("%d%d", &n, &k);
	for (int i = 0; i < 1001; i++)
	{
		arr[0][i] = 1;
		arr[i][0] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n-i; j++)
		{
			arr[i][j] = (arr[i-1][j] % 10007) + (arr[i][j-1] % 10007);
		}
	}

	result = arr[k][n-k] % 10007;
	printf("%lld\n", result);

	exit(0);
}
