#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
	int num, i = 0, j = 0;
	int time[1005] = {0, };
	int sum[1005] = {0, };
	int min = 0;

	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &time[i]);
	}
	qsort(time, num, sizeof(int), compare);
	//printArr(time, num);

	// 그리디 알고리즘의 방식대로 답이 구해졌는지도 채점에 반영
	for (i = 0; i < num; i++)
	{
		if (i == 0)
		{
			sum[i] = time[i];
		}
		else	// 부분합을 이용해 해 찾기
		{
			sum[i] = sum[i-1] + time[i];
		}
		min += sum[i];	// 앞서 구한 최소 소요 시간
	}
	//printArr(sum, num);

	printf("%d\n", min);
	exit(0);
}
