#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long LONG;

LONG factorial(int num)
{
	LONG result = 1;

	for (int i = 1; i <= num; i++)
	{
		result *= i;
		while (result % 10 == 0)
		{
			result /= 10;
		}
		result %= 1000000000000;
	}
	return result;
}

int main(void)
{
	int n, count = 0;
	char number[65] = {0, };
	LONG result;

	scanf("%d", &n);

	result = factorial(n);

	printf("%05lld\n", result % 100000);
	exit(0);
}
