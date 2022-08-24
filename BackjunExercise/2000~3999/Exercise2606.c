#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 101

int graph[MAXLEN][MAXLEN] = {0, };
int visit[MAXLEN] = {0, };
int count = 0;

void dfs(int start, int *vCount)
{
	visit[start] = 1;

	for (int i = 1; i <= *vCount; i++)
	{
		if (graph[start][i] == 1 && visit[i] == 0) {
			count++;
			dfs(i, vCount);
		}
	}
}

int main(void)
{
	int vCount, eCount;
	int start = 1;

	scanf("%d%d", &vCount, &eCount);
	for (int i = 0; i < eCount; i++)
	{
		int from, target;

		scanf("%d%d", &from, &target);
		graph[from][target] = 1;
		graph[target][from] = 1;
	}

	dfs(start, &vCount);
	printf("%d\n", count);
	exit(0);
}
