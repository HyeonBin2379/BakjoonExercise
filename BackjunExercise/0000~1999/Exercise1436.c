#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int count;
	int i = 0;
	int val = 0;

	scanf("%d", &count);

	while (1)
	{
		char num[32] = {0, };

		if (count == 0)
			break;

		sprintf(num, "%d", ++i);
		if (strstr(num, "666") == NULL)
		{
			continue;
		}
		else {
			--count;
			val = atoi(num);
		}
	}

	printf("%d\n", val);
	exit(0);
}
