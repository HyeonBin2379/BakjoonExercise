#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, prior = 0; 
vector<vector<int>> graph;
vector<int> visit;
queue<int> que;

void bfs(int V) 
{

	int size, u;

	visit[V] = ++prior;
	que.push(V);

	while (que.size() != 0)
	{
		u = que.front();
		que.pop();
		size = graph[u].size();

		for(int i = 0; i < size; i++) 
		{
			if (visit[graph[u][i]] == 0)
			{
				visit[graph[u][i]] = ++prior;
				que.push(graph[u][i]);
			}
		}
	}
}

int main(void) 
{
	int M, V, x, y;

	cin >> N >> M >> V;
	graph.resize(N+1);
	visit.resize(N+1);

	for(int i = 0; i < M; i++) 
	{
		int u, v;

		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end(), greater<>());

	bfs(V);

	for (int i = 1; i < N+1; i++)
		printf("%d\n", visit[i]);

	exit(0);
}
