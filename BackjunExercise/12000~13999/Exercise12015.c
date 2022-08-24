#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *arr, int start, int end, int target)
{
	int mid;
	int left = start;
	int right = end;

	while (left < right)
	{
		mid = (left + right) / 2;

		if (target > arr[mid])
			left = mid+1;
		else
			right = mid;
	}

	return right;
}

int main(void)
{
	int *data;
	int *list;
	int size = 0, len = 0, last = 0;

	scanf("%d", &size);
	data = (int *)malloc(sizeof(int) * size);
	list = (int *)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &data[i]);
	}

	list[last++] = data[0];
	for (int i = 1; i < size; i++)
	{
		if (data[i] > list[last-1])
		{
			len = last;
			list[last++] = data[i];
		}
		else {
			int pos = binarySearch(list, 0, len, data[i]);
			list[pos] = data[i];
		}
	}

	free(data);
	free(list);
	printf("%d\n", len+1);
	exit(0);
}
