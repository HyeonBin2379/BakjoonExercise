#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size, i, j, k;
	int graph[101][101] = {0, };

	scanf("%d", &size);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}

	for (k = 0; k < size; k++)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (graph[i][k] == 1 && graph[k][j] == 1)
					graph[i][j] = 1;
			}
		}
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	exit(0);
}
