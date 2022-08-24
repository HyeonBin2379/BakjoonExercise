#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int inputs[4] = {0, };
	long long result = 0;
	char num1[32] = {0, };
	char num2[32] = {0, };

	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &inputs[i]);
	}

	sprintf(num1, "%d%d", inputs[0], inputs[1]);
	sprintf(num2, "%d%d", inputs[2], inputs[3]);

	printf("%s %s\n", num1, num2);
	result = atol(num1) + atol(num2);
	printf("%lld\n", result);
	exit(0);
}
