#include <stdio.h>
#include <stdlib.h>

int compare(const void *_elem1, const void *_elem2)
{
	int *elem1 = (int *)_elem1;
	int *elem2 = (int *)_elem2;

	if (*elem1 < *elem2)
		return 1;
	else if (*elem1 > *elem2)
		return -1;
	else
		return 0;
}

int main(void)
{
	int score[1001] = {0, };
	int count, cutLine;

	scanf("%d%d", &count, &cutLine);
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &score[i]);
	}

	qsort(score, count, sizeof(int), compare);

	printf("%d\n", score[cutLine-1]);
	exit(0);
}
