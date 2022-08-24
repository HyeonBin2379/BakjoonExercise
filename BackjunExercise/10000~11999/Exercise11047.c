#include <stdio.h>
#include <stdlib.h>

typedef struct tagCoin
{
	int coinUnit;
	int change;
	int diff;
} Coin;

void initData(Coin *arr, int unitCount, int price)
{
	for (int i = 0; i < unitCount; i++)
	{
		arr[i].coinUnit = 0;
		arr[i].change = 0;
		arr[i].diff = price;
	}
}
int compare(const void *_elem1, const void *_elem2)
{
	Coin *elem1 = (Coin *)_elem1;
	Coin *elem2 = (Coin *)_elem2;

	if (elem1->coinUnit > elem2->coinUnit)
		return -1;
	else if (elem1->coinUnit < elem2->coinUnit)
		return 1;
	else
		return 0;
}
int getChanges(Coin *arr, int unitCount, int price)
{
	int sum = 0;

	for (int i = 0; i < unitCount; i++)
	{
		if (price == 0)
			break;

		if (price < arr[i].coinUnit)
		{
			arr[i].diff = price;
			continue;
		}

		arr[i].change = price / arr[i].coinUnit;
		price -= arr[i].change * arr[i].coinUnit;
		sum += arr[i].change;
	}

	return sum;
}

int main(void)
{
	int unitCount, price, result;
	Coin *coins;

	scanf("%d%d", &unitCount, &price);
	coins = (Coin *)malloc(sizeof(Coin) * unitCount);

	initData(coins, unitCount, price);
	for (int i = 0; i < unitCount; i++)
	{
		scanf("%d", &coins[i].coinUnit);
	}
	qsort(coins, unitCount, sizeof(Coin), compare);

	result = getChanges(coins, unitCount, price);

	printf("%d\n", result);
	exit(0);
}
