#include <stdio.h>
#include <stdlib.h>

int entry[100001] = {0,};
int target[100001] = {0,};

int compare(const void *_elem1, const void *_elem2)
{
	int *elem1 = (int *)_elem1;
	int *elem2 = (int *)_elem2;

	if (*elem1 > *elem2)
		return 1;
	else if (*elem1 < *elem2)
		return -1;
	else
		return 0;
}

int binarySearch(int input[], int len, int target)
{
	int left, right, mid;
	int res = 0;

	left = 0;
	right = len-1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (target == input[mid]) {
			return 1;
		}
		else if (target > input[mid])
			left = mid+1;
		else
			right = mid-1;
	}
	return 0;
}

int main(void)
{
	int len, test;
	
	scanf("%d", &len);
	for (int i = 0; i < len; i++)
	{
		scanf("%d", &entry[i]);
	}

	qsort(entry, len, sizeof(int), compare);

	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		scanf("%d", &target[i]);
	}

	for (int i = 0; i < test; i++)
	{
		printf("%d\n", binarySearch(entry, len, target[i]));
	}

	return 0;
}
