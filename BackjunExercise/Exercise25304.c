#include <stdio.h>
#include <stdlib.h>

typedef struct bought
{
	int cost;
	int count;
} Bought;

int main(void)
{
	int total, sum = 0;
	int testCase;
	Bought *arr;

	scanf("%d", &total);
	scanf("%d", &testCase);

	arr = (Bought *)malloc(sizeof(Bought) * testCase);
	for (int i = 0; i < testCase; i++)
	{
		scanf("%d%d", &arr[i].cost, &arr[i].count);
		sum += arr[i].cost * arr[i].count;
	}

	if (total == sum)
		printf("Yes\n");
	else
		printf("No\n");

	free(arr);
	exit(0);
}
