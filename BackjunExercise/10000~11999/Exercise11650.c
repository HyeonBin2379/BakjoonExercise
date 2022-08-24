#include <stdio.h>
#include <stdlib.h>

typedef struct _point
{
	int x;
	int y;
} Point;
int compare(const void * _elem1, const void * _elem2)
{
	Point * elem1 = (Point *)_elem1;
	Point * elem2 = (Point *)_elem2;

	if (elem1->x > elem2->x)
		return 1;
	else if (elem1->x < elem2->x)
		return -1;
	else {
		if (elem1->y > elem2->y)
			return 1;
		else if (elem1->y < elem2->y)
			return -1;
		else
			return 0;
	}
}

int main(void)
{
	Point arr[100000];
	int len;
	int i = 0;

	scanf("%d", &len);
	for (i = 0; i < len; i++)
	{
		scanf("%d%d", &arr[i].x, &arr[i].y);
	}

	qsort(arr, len, sizeof(Point), compare);

	for (i = 0; i < len; i++)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	exit(0);
}
