#include <stdio.h>
#include <stdlib.h>

int fibRecCount(int num, int *result)
{
	if (num == 1 || num == 2) 
	{
		(*result)++;
		return 1;
	}
	else 
		return fibRecCount(num-1, result) + fibRecCount(num-2, result);
}
void fibDPCount(int *arr, int count, int *result)
{
	for (int i = 3; i <= count; i++)
	{
		arr[i] = arr[i-1] + arr[i];
		(*result)++;
	}
}
int main(void)
{
	int count;
	int num;
	int result1 = 0, result2 = 0;
	int arr[41] = {0, };

	scanf("%d", &count);

	arr[1] = 1;
	arr[2] = 1;

	fibRecCount(count, &result1);
	fibDPCount(arr, count, &result2);

	printf("%d %d\n", result1, result2);
	exit(0);
}
