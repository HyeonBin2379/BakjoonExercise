#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 8001

typedef struct _count
{
	int val;
	int count;
} Count;

void initStrArray(Count * arr)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		arr[i].val = 0;
		arr[i].count = 0;
	}
}
int compare1(const void * _elem1, const void * _elem2)
{
	Count * elem1 = (Count *)_elem1;
	Count * elem2 = (Count *)_elem2;

	if (elem1->count < elem2->count)
		return 1;
	else if (elem1->count > elem2->count)
		return -1;
	else {
		if (elem1->val > elem2->val)
			return 1;
		else if (elem1->val < elem2->val)
			return -1;
	}
	return 0;
}
int compare2(const void * _elem1, const void * _elem2)
{
	int * elem1 = (int *)_elem1;
	int * elem2 = (int *)_elem2;

	if (*elem1 > *elem2)
		return 1;
	else if (*elem1 < *elem2)
		return -1;
	else
		return 0;
}

int arithAvg(int * arr, int len)
{
	int sum = 0;
	double avg;

	for (int i = 0; i < len; i++)
		sum += arr[i];

	avg = (double)sum/len;

	return (int)round(avg);
}
int median(int * arr, int len)
{
	return arr[len/2];
}
int mode(Count * arr, int len)
{
	if (arr[0].count == arr[1].count)
		return arr[1].val;
	else
		return arr[0].val;
}
int range(int * arr, int len)
{
	return arr[len-1] - arr[0];
}

int main(void)
{
	Count count[MAXSIZE];
	int num[500000] = {0, };
	int len, val;
	int i = 0;

	initStrArray(count);
	scanf("%d", &len);
	for (i = 0; i < len; i++)
	{
		scanf("%d", &num[i]);
		count[num[i] + 4000].val = num[i];
		count[num[i] + 4000].count++;
	}

	qsort(count, MAXSIZE, sizeof(Count), compare1);
	qsort(num, len, sizeof(int), compare2);

	printf("%d\n", arithAvg(num, len));
	printf("%d\n", median(num, len));
	printf("%d\n", mode(count, len));
	printf("%d\n", range(num, len));

	exit(0);
}
