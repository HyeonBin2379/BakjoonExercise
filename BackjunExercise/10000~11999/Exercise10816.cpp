#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int compareNum(const void *_elem1, const void *_elem2)
{
	int *elem1 = (int *)_elem1;
	int *elem2 = (int *)_elem2;

	if (elem1 > elem2)
		return 1;
	else if (elem1 < elem2)
		return -1;
	else
		return 0;
}

int main(void)
{
	int test1, test2, val, idx;

	vector<int> numbers;
	vector<int> counts;

	scanf("%d", &test1);
	for (int i = 0; i < test1; i++)
	{
		scanf("%d", &val);
		numbers.push_back(val);
	}

	sort(numbers.begin(), numbers.end());

	scanf("%d", &test2);
	for (int i = 0; i < test2; i++)
	{
		scanf("%d", &val);
		idx = upper_bound(numbers.begin(), numbers.end(), val) - lower_bound(numbers.begin(), numbers.end(), val);
		counts.push_back(idx);
	}

	for (int i = 0; i < test2; i++)
		printf("%d ", counts[i]);

	printf("\n");
	
	exit(0);
}
