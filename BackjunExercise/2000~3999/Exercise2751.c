#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000000

int compare(const void * _elem1, const void * _elem2)
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

int main(void)
{
	int len;
	int * arr = (int *)calloc(MAXLEN, sizeof(int));

	scanf("%d", &len);
	for (int i = 0; i < len; i++)
		scanf("%d", &arr[i]);

	qsort(arr, len, sizeof(int), compare);

	for (int i = 0; i < len; i++)
		printf("%d\n", arr[i]);

	free(arr);
	exit(0);
}
