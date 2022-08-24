#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertSort(char * dataSet, int length)
{
	int i = 0;
	int j = 0;
	char value = 0;

	for (i = 1; i < length; i++)
	{
		if (dataSet[i] <= dataSet[i-1])
			continue;

		value = dataSet[i];

		for (j = 0; j < i; j++)
		{
			if (dataSet[j] < value)
			{
				memmove(&dataSet[j+1], &dataSet[j], sizeof(dataSet[0]) * (i-j));
				dataSet[j] = value;
				break;
			}
		}
	}
}

int main(void)
{
	char dataSet[11] = {0, };
	int length = sizeof(dataSet)/sizeof(dataSet[0]);
	int i = 0;

	scanf("%s", dataSet);
	length = strlen(dataSet);

	insertSort(dataSet, length);

	printf("%s\n", dataSet);
	exit(0);
}
