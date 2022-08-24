#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
	int row, col, blocks = 0;
	int height[250000] = {0, };
	int mintime = INT_MAX, maxheight = 0;
	int flag = 0;

	// 높이 입력 및 오름차순 정렬
	scanf("%d%d%d", &row, &col, &blocks);
	for (int i = 0; i < row*col; i++)
	{
		scanf("%d", &height[i]);
	}
	qsort(height, row*col, sizeof(int), compare);
	//printHeight(height, row*col);

	for (int i = height[0]; i <= height[row*col-1]; i++)
	{
		int build = 0, remove = 0;
		int target = i;
		int time = 0;

		//printf("height: %d\n", i);
		for (int j = 0; j < row*col; j++)
		{
			if (height[j] - target > 0)	// 블록 제거 수행
			{
				remove += (height[j] - target);
			}
			else if (height[j] - target < 0)	// 블록 설치 수행
			{
				build -= (height[j] - target);
			}
		}

		if (remove + blocks >= build)
		{
			time += remove * 2 + build;
			if (time <= mintime)
			{
				mintime = time;
				maxheight = target;
			}
		}
	}
	printf("%d %d\n", mintime, maxheight);
	exit(0);
}
