#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 200000

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
long long parametric(long long *arr, int used, int have)
{
	long long min = 1;
	long long max = arr[used-1] - arr[0];
	long long mid, ans = 0;

	while (min <= max)
	{
		long long prev = arr[0];
		int count = 1;

		mid = (min + max) / 2;

		for (int i = 1; i < used; i++)
		{
			if (arr[i] - prev >= mid)
			{
				count++;
				prev = arr[i];
			}
		}

		if (count < have)
		{
			max = mid-1;
		}
		else
		{
			min = mid+1;
			ans = (ans > mid) ? ans : mid;
		}
	}
	return ans;
}
int main(void)
{
	int count, have;
	long long pos[MAXSIZE] = {0, };
	long long ans = 0;

	scanf("%d%d", &count, &have);

	if (count == 0)
	{
		printf("%lld\n", ans);
	}
	else {
		for (int i = 0; i < count; i++)
		{
			scanf("%lld", &pos[i]);
		}
		qsort(pos, count, sizeof(long long), compare);
		
		ans = parametric(pos, count, have);
		printf("%lld\n", ans);
		exit(0);
	}
}
