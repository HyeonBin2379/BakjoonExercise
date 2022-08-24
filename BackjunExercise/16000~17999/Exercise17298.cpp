#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

int main(void)
{
	int length, i;
	int *arr;
	stack<int> stack;
	vector<int> nge;

	scanf("%d", &length);
	arr = (int *)calloc(length, sizeof(int));
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &arr[i]);
	}

	nge.resize(length);
	for (i = 0; i < length; i++)
	{
		if (stack.empty()) {
			stack.push(i);
		}
		while (!stack.empty() && arr[stack.top()] < arr[i])
		{
			nge[stack.top()] = arr[i];
			stack.pop();
		}
		stack.push(i);

	}
	while (!stack.empty()) {
		nge[stack.top()] = -1;
		stack.pop();
	}

	for (i = 0; i < length; i++)
		printf("%d ", nge[i]);
	printf("\n");
	exit(0);
}
