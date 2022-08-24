#include <stdio.h>
#include <stdlib.h>

long long parametric(int size, int target)
{
	long long start = 1;
	long long end = target;	// b[k] <= k <= size*size: 범위를 최대한 좁히고 시작
	long long mid, ans = 0;

	while (start <= end)
	{
		long long count = 0;
		
		mid = (start + end) / 2;

		for (int i = 1; i <= size; i++)
		{
			long long min = (mid/i > size) ? size : mid/i;
			count += min;
		}

		if (count < target)	// upper bound
		{
			start = mid+1;
		}
		else	// lower bound: target과 같거나 작은 첫번째 mid값
		{
			ans = mid; 
			end = mid-1;
		}
	}

	return ans;
}

int main(void)
{
	long long size, target;
	long long ans = 0;

	scanf("%lld", &size);
	scanf("%lld", &target);

	ans = parametric(size, target);
	printf("%lld\n", ans);
	exit(0);
}
