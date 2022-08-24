#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
// 각 자리별 고장 여부 확인, 숫자버튼 사용 횟수 리턴
int check(int *broken, int channel)
{
	int len = 0;

	if (channel == 0)
	{
		if (broken[0] == 1)
			return 0;
		else
			return 1;
	}

	while (channel > 0)
	{
		if (broken[channel % 10] == 1)
			return 0;

		channel /= 10;
		len++;
	}

	return len;
}
int main(void)
{
	int channel, brokenCnt;
	int broken[10] = {0, };
	int count = 0, minDiff;

	// 입력: 이동할 채널 번호, 고장난 숫자 버튼
	scanf("%d", &channel);
	scanf("%d", &brokenCnt);
	while (brokenCnt-- > 0) 
	{
		int index;

		scanf("%d", &index);
		broken[index] = 1;
	}

	// 초기화: 100번에서 +/- 버튼만 사용 시 버튼 누르는 횟수
	minDiff = abs(channel - 100);

	// 숫자 입력 후 +/- 버튼 사용
	// 숫자 입력 시 버튼 고장 여부 판정
	for (int i = 0; i <= 1000000; i++)
	{
		int len, press;

		// 숫자 입력 횟수
		len = check(broken, i);
		// +/- 입력 횟수
		if (len > 0)
		{
			int press = abs(i - channel);
			minDiff = (minDiff > press+len) ? press+len : minDiff;
		}
	}

	printf("%d\n", minDiff);
	exit(0);
}
