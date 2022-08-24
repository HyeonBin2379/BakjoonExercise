#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int testCase;

	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++)
	{
		int arr[41] = {0, };
		int count;

		scanf("%d", &count);

		if (count == 0)
		{
			printf("%d %d\n", 1, 0);
			continue;
		}
		else if (count == 1)
		{
			printf("%d %d\n", 0, 1);
			continue;
		}

		arr[0] = 1;
		arr[1] = 1;
		for (int j = 2; j <= count; j++)
		{
			arr[j] = arr[j-1] + arr[j-2];
		}
		printf("%d %d\n", arr[count-2], arr[count-1]);
	}
	exit(0);
}
