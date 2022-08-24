#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000000

void printArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int check(int *broken, char *compare, int len)
{
	int numCount = 0;

	if (strcmp(compare, "0") == 0)
	{
		if (broken[compare[0]-'0'] == 1)
			return 0;
		else
			return 1;
	}

	for (int i = 0; i < len; i++)
	{
		// 고장난 버튼으로 잘못 입력 시 입력횟수 초기화
		if (broken[compare[i]-'0'] == 1)
			return 0;
		numCount++;
	}

	return numCount;
}
int main(void)
{
	int brokenCnt, minCnt, numCnt, max, min;
	int broken[10] = {0, };
	char input[7] = {0, };
	char compare[7] = {0, };

	scanf("%s", input);
	scanf("%d", &brokenCnt);
	while (brokenCnt-- > 0)
	{
		int index;

		scanf("%d", &index);
		broken[index] = 1;
	}

	minCnt = abs(atoi(input)-atoi("100"));
	max = MAXSIZE;
	min = 0;
	for (int i = min; i < max; i++)
	{
		int len = snprintf(compare, sizeof(compare), "%d", i);

		numCnt = check(broken, compare, len);
		if (numCnt > 0)
		{
			int pressCnt = abs(atoi(input) - atoi(compare));
			minCnt = (minCnt > pressCnt + numCnt) ? pressCnt + numCnt : minCnt;
			max = MAXSIZE - atoi(compare);
			min = atoi(compare);
		}
	}

	printf("%d\n", minCnt);
	exit(0);
}
