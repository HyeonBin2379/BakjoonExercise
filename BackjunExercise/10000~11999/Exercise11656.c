#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *elem1, const void *elem2)
{
	return strcmp((char *)elem1, (char *)elem2);
}

int main(void)
{
	char str[1005] = {0, };
	char ptr[1005][1005] = {0, };
	int len;

	scanf("%s", str);
	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		strcpy(ptr[i], &str[i]);
	}
	qsort(ptr, len, sizeof(ptr[0]), compare);

	for (int i = 0; i < len; i++)
	{
		if (ptr[i] != NULL)
			printf("%s\n", ptr[i]);
		else
			continue;
	}

	exit(0);
}
