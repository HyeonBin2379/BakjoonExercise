#include <stdio.h>
#include <stdlib.h>

int compare(const void *_elem1, const void *_elem2)
{
	long long *elem1 = (long long *)_elem1;
	long long *elem2 = (long long *)_elem2;

	if (*elem1 > *elem2)
		return 1;
	else if (*elem1 < *elem2)
		return -1;
	else
		return 0;
}
int parametric(long long *arr, int count, long long need)
{
	long long min = 1;
	long long max = arr[count-1];
	long long mid, ans = 0;

	while (min <= max)
	{
		long long sum = 0;

		mid = (min + max) / 2;

		for (int i = 0; i < count; i++)
		{
			if (arr[i] > mid)
				sum += arr[i] - mid;
			else
				sum += 0;
		}

		if (sum < need) 
		{
			max = mid-1;
		}
		else
		{
			min = mid+1;
			if (ans < mid)
				ans = mid;
		}
	}

	return ans;
}

int main(void)
{
	int count = 0;
	long long need = 0, ans = 0;
	long long *height;

	scanf("%d%lld", &count, &need);

	if (count == 0)
	{
		printf("%lld\n", ans);
		exit(0);
	}
	else {
		height = (long long *)calloc(count, sizeof(long long));
		for (int i = 0; i < count; i++)
		{
			scanf("%lld", &height[i]);
		}
		qsort(height, count, sizeof(long long), compare);

		ans = parametric(height, count, need);
		printf("%lld\n", ans);
		free(height);
		exit(0);
	}
}
