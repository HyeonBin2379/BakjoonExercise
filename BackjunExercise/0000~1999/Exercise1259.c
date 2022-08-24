#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPelindrom(char *arr, int len)
{
	int mid = len / 2;

	for (int i = 0; i < mid; i++)
	{
		if (arr[i] != arr[len-(i+1)])
			return 0;
	}
	return 1;
}

int main(void)
{
	int num;

	while (1)
	{
		int len;
		int pelindrom = 0;
		char arr[7] = {0, };

		scanf("%d", &num);

		if (num == 0)
			break;

		sprintf(arr, "%d", num);
		len = strlen(arr);
		
		if (strlen(arr) == 1)
		{
			printf("yes\n");
			continue;
		}

		if (isPelindrom(arr, len) == 0)
			printf("no\n");
		else
			printf("yes\n");

	}
	exit(0);
}
