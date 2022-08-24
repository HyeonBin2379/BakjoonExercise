#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

#define MAXLEN 10001
using namespace std;

int nodeCount;
typedef struct node
{
	int weight;
	vector<node *>children = vector<node *>();
} Node;
Node node[MAXLEN];
int value = 0;

int traverse(Node *root)
{
	if (root->children.size() == 0)
		return root->weight;

	if (root->children.size() == 1)
		return root->weight += traverse(root->children[0]);

	vector<int> weights = vector<int> (root->children.size());

	for (int i = 0; i < root->children.size(); i++)
	{
		weights[i] = traverse(root->children[i]);
	}

	sort(weights.begin(), weights.end(), greater<>());

	value = max(weights[0] + weights[1], value);

	return root->weight + weights[0];
}

int main(void)
{
	int result;

	scanf("%d", &nodeCount);

	node[1] = Node();
	node[1].weight = 0;

	for (int i = 0; i < nodeCount-1; i++)
	{
		int from, target, weight;
		
		scanf("%d%d%d", &from, &target, &weight);
		node[target] = Node();
		node[target].weight = weight;
		node[from].children.push_back(&node[target]);
	}

	result = max(value, traverse(&node[1]));
	printf("%d\n", result);
	exit(0);
}
