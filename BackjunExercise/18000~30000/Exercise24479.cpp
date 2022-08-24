#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, prior; 
vector<vector<int>> graph;
vector<int> visit;
vector<int> seq;

void dfs(int V) 
{
	int size = graph[V].size();
	int v;
	visit[V] = 1;
	seq[V] = ++prior;

	for(int i = 0; i < size; i++) 
	{
		v = graph[V][i];
		if (visit[v] == 0) 
			dfs(v);
	}
}

int main(void) 
{
	int M, V, x, y;

	cin >> N >> M >> V;
	graph.resize(N+1);
	visit.resize(N+1);
	seq.resize(N+1);

	for(int i = 0; i < M; i++) 
	{
		int u, v;

		scanf("%d%d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(V);

	for (int i = 1; i < N+1; i++)
		printf("%d\n", seq[i]);

	exit(0);
}
