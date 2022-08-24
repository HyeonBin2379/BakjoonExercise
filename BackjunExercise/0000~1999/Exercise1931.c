#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagTime
{
	int start;
	int end;
} Time;

int compare(const void *_elem1, const void *_elem2)
{
	Time *elem1 = (Time *)_elem1;
	Time *elem2 = (Time *)_elem2;

	if (elem1->end != elem2->end)
	{
		if (elem1->end > elem2->end)
			return 1;
		else if (elem1->end < elem2->end)
			return -1;
		else
			return 0;
	}
	else {
		if (elem1->start > elem2->start)
			return 1;
		else if (elem1->start < elem2->start)
			return -1;
		else
			return 0;
	}
	return 0;
}
void printData(Time *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d %d\n", arr[i].start, arr[i].end);
	}
}

int main(void)
{
	int mCount, meetCount, last;
	Time *meeting1;

	// 예약된 회의 시작 및 종료 시간
	scanf("%d", &mCount);
	meeting1 = (Time *)calloc(mCount, sizeof(Time));
	for (int i = 0; i < mCount; i++)
	{
		scanf("%d%d", &meeting1[i].start, &meeting1[i].end);
	}
	// 정렬: 종료 시간에 대한 오름차순 정렬,
	//	종료 시간 동일할 시 시작 시간 기준 오름차순 정렬
	qsort(meeting1, mCount, sizeof(Time), compare);

	// 진행 가능한 회의 수, 마지막 회의 종료 시간
	meetCount = 0;
	last = 0;
	for (int i = 0; i < mCount; i++)
	{
		// 예약된 회의 마지막 종료시간에 대한 그리디 알고리즘
		// 1개의 회의실에 대해 사용 가능한 최대 회의 수
		if (meeting1[i].start >= last)
		{
			meetCount++;
			last = meeting1[i].end;
		}
	}

	printf("%d\n", meetCount);
	free(meeting1);
	exit(0);
}
