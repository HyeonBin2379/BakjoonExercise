#include <stdio.h>
#include <stdlib.h>

long long comb[1000001] = {0, };
int main(void)
{
	int input;
	long long answer = 0;

	scanf("%d", &input);
	comb[0] = 1 % 15746;
	comb[1] = 1 % 15746;

	for (int i = 2; i <= input; i++)
	{
		comb[i] = (comb[i-1] % 15746) + (comb[i-2] % 15746);
		comb[i] %= 15746;
	}

	answer = comb[input];
	printf("%lld\n", answer);
	exit(0);
}
