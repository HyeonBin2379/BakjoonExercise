#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char exp[51] = {0, };
	char minus[25] = {0, };
	char token[6] = {0, };
	int number[25] = {0, };
	int idx_tok = 0, idx_num = 0;
	int len, sum;

	scanf("%s", exp);
	len = strlen(exp);

	for (int i = 0; exp[i] != '\0'; i++)
	{

		if (exp[i] >= '0' && exp[i] <= '9')
		{
			token[idx_tok++] = exp[i];
		}
		else if (exp[i] == '+')
		{
			number[idx_num] += atoi(token);
			memset(token, 0, sizeof(token));
			idx_tok = 0;
		}
		else if (exp[i] == '-')
		{
			number[idx_num] += atoi(token);
			minus[idx_num++] = exp[i];

			memset(token, 0, sizeof(token));
			idx_tok = 0;
		}
	}
	number[idx_num] += atoi(token);

	sum = number[0];
	for (int i = 1; i <= idx_num; i++)
	{
		sum -= number[i];
	}
	printf("%d\n", sum);

	exit(0);
}
