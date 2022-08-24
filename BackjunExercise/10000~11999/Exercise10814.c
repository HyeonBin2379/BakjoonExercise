#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _info
{
	int age;
	int index;
	char name[101];
} Info;
Info record[100000];

void initStrArray(Info * arr)
{
	for (int i = 0; i < 100000; i++)
	{
		arr[i].age = 0;
		arr[i].name[0] = '\0';
		arr[i].index = -1;
	}
}
void setStrValue(Info * val1, Info * val2)
{
	val1->age = val2->age;
	strcpy(val1->name, val2->name);
	val1->index = val2->index;
}
int compare(const void * _elem1, const void * _elem2)
{
	Info * elem1 = (Info *)_elem1;
	Info * elem2 = (Info *)_elem2;

	if (elem1->age > elem2->age)
		return 1;
	else if (elem1->age < elem2->age)
		return -1;
	else {
		if (elem1->index > elem2->index)
			return 1;
		else if (elem1->index < elem2->index)
			return -1;
	}
	return 0;
}
void insertSort(Info * arr, int len)
{
	int i = 0;
	int j = 0;
	Info value;

	for (i = 1; i < len; i++)
	{
		if (compare(&arr[i-1], &arr[i]) < 0)
			continue;

		setStrValue(&value, &arr[i]);

		for (j = 0; j < i; j++)
		{
			if (compare(&arr[j], &value) > 0)
			{
				memmove(&arr[j+1], &arr[j], sizeof(arr[0]) * (i-j));
				setStrValue(&arr[j], &value);
				break;
			}
		}
	}
}
int main(void)
{
	int len;

	initStrArray(record);
	scanf("%d", &len);

	for (int i = 0; i < len; i++)
	{
		scanf("%d%s", &record[i].age, record[i].name);
		record[i].index = i;
	}

	insertSort(record, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d %s\n", record[i].age, record[i].name); 
	}

	exit(0);
}
