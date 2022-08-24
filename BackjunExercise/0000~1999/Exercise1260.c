#include <stdio.h>
#include <stdlib.h>

int N; 
int graph[1001][1001] = {0, };
int visit[1001] = {0, };
int queue[1001];

void dfs(int V) {
	visit[V] = 1;
	printf("%d ", V);
	for(int i=1; i<=N; i++) {
		if(graph[V][i] == 1 && visit[i] == 0) 
			dfs(i);
	}
}

void bfs(int v) 
{
	int front = 0, rear = 1;
	int pop;

	visit[v] = 1;
	printf("%d ", v);
	queue[0] = v;

	while(front < rear) 
	{
		pop = queue[front++];
		for(int i = 1; i <= N; i++) {
			if(graph[pop][i] == 1 && visit[i] == 0) 
			{
				visit[i] = 1;
				printf("%d ", i);
				queue[rear++] = i;
			}
		}
	}
}

int main(void) 
{
	int M, V, x, y;
	scanf("%d %d %d", &N, &M, &V);
	for(int i = 0; i < M; i++) 
	{
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	dfs(V);
	for(int i = 1; i <= N; i++) 
	{
		visit[i] = 0;
	}
	printf("\n");
	bfs(V);

	exit(0);
}
