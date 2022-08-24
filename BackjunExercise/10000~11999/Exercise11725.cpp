#include <iostream>
#include <vector>
#include <queue>

#define MAXLEN 100001

using namespace std;

vector<int> tree[MAXLEN];
queue<int> q;

int parent[MAXLEN];
bool visit[MAXLEN];

void dfs(int root)
{
	visit[root] = true;

	for (int i = 0; i < tree[root].size(); i++)
	{
		int next = tree[root][i];

		if (visit[next] == false)
		{
			parent[next] = root;
			dfs(next);
		}
	}
}
void bfs(int root)
{
	visit[root] = true;

	q.push(root);

	while (!q.empty())
	{
		int popped = q.front();
		q.pop();

		for (int i = 0; i < tree[popped].size(); i++)
		{
			int next = tree[popped][i];

			if (visit[next] == false)
			{
				parent[next] = popped;
				visit[next] = true;
				q.push(next);
			}
		}
	}
}
int main(void)
{
	int test, from, target;

	cin >> test;
	for (int i = 0; i < test-1; i++)
	{
		cin >> from >> target;
		tree[from].push_back(target);
		tree[target].push_back(from);
	}

	//dfs(1);
	bfs(1);

	for (int i = 2; i <= test; i++)
	{
		printf("%d\n", parent[i]);
	}
	exit(0);
}
