#include <stdio.h>
#include <stdlib.h>

typedef long long LONG;

int main(void)
{
	int cityCount, i;
	LONG *oilPrice;
	LONG *adjRoad;
	LONG now, totalPrice;

	// 입력
	scanf("%d", &cityCount);
	adjRoad = (LONG *)calloc(cityCount-1, sizeof(LONG));
	for (i = 0; i < cityCount-1; i++)
	{
		scanf("%lld", &adjRoad[i]);
	}
	oilPrice = (LONG *)calloc(cityCount, sizeof(LONG));
	for (i = 0; i < cityCount; i++)
	{
		scanf("%lld", &oilPrice[i]);
	}

	// 그리디 알고리즘: 현재 기름값과 다음 기름값 중 더 싼 값 지향
	// 도로 수 = 도시 수 - 1이므로 도착점의 기름값은 영향 X
	now = oilPrice[0];
	totalPrice = 0LL;
	for (i = 0; i < cityCount-1; i++)
	{
		// 다음 도시가 더 비싼 경우/동일한 경우
		if (now <= oilPrice[i])
		{
			totalPrice += now*adjRoad[i];
		}
		else	// 다음 도시가 더 싼 경우
		{
			now = oilPrice[i];
			totalPrice += now*adjRoad[i];
		}
	}
	printf("%lld\n", totalPrice);

	free(oilPrice);
	free(adjRoad);
	exit(0);
}
