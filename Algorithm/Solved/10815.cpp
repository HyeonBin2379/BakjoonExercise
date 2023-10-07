#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second)
{
    int a = *(int*)first;
    int b = *(int*)second;

    if (a > b) return 1;
    else if (a < b) return -1;
    else return 0;
}
int binarySearch(int array[], int len, int target)
{
    int left = 0;
    int right = len-1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (array[mid] == target)
            return 1;
        else if (array[mid] > target)
            right = mid-1;
        else
            left = mid+1;
    }
    return 0;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int owned[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &owned[i]);
    }
    qsort(owned, n, sizeof(int), compare);

    int m;
    scanf("%d", &m);
    int given[m];
    int res[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &given[i]);
        res[i] = binarySearch(owned, n, given[i]);
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    
    return 0;
}