#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string
{
	char str[51];
} String;

int compare(const void * _elem1, const void * _elem2)
{
	String * elem1 = (String *)_elem1;
	String * elem2 = (String *)_elem2;

	if (strlen(elem1->str) > strlen(elem2->str))
		return 1;
	else if (strlen(elem1->str) < strlen(elem2->str))
		return -1;
	else {
		if (strcmp(elem1->str, elem2->str) < 0)
			return -1;
		else if (strcmp(elem1->str, elem2->str) > 0)
			return 1;
	}
	return 0;
}

int main(void)
{
	String list[20001];
	int len, i, j;

	scanf("%d", &len);
	for (i = 0; i < len; i++)
	{
		scanf("%s", list[i].str);
	}

	qsort(list, len, sizeof(String), compare);

	for (i = 0; i < len; i++)
	{
		if (i == 0)
		{
			printf("%s\n", list[i].str);
		}
		else {
			if (strcmp(list[i-1].str, list[i].str) != 0)
				printf("%s\n", list[i].str);
		}
	}	
	exit(0);
}
