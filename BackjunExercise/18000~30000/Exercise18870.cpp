#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> vect, int target)
{
	int left, right, mid;

	left = 0;
	right = (int)vect.size() - 1;

	while (left <= right)
	{
		mid = left + right / 2;

		if (vect[mid] == target)
			return mid;
		else if (vect[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main(void)
{
	int test, val;
	vector<int> arr;
	vector<int> sortArr;

	cin >> test;
	for (int i = 0; i < test; i++)
	{
		scanf("%d", &val);
		arr.push_back(val);
		sortArr.push_back(val);
	}
	sort(sortArr.begin(), sortArr.end());
	sortArr.erase(unique(sortArr.begin(), sortArr.end()), sortArr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		int res;

		val = arr[i];
		cout << lower_bound(sortArr.begin(), sortArr.end(), val) - sortArr.begin() << " ";
	}


	printf("\n");
	exit(0);
}
