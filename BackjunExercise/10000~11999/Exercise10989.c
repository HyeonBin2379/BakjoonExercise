#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count[10001] = {0, };
	int len;

	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		int idx = 0;
		scanf("%d", &idx);
		count[idx]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (count[i] == 0) continue;
		else {
			for (int j = 1; j <= count[i]; j++)
				printf("%d\n", i);
		}
	}
	exit(0);
}
