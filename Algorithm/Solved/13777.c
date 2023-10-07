#include <stdio.h>

void binarySearch(int len, int target)
{
    int left = 1;
    int right = len;

    while (left <= right)
    {
        int mid = (left + right)/2;

        printf("%d ", mid);

        if (mid == target) break;
        else if (mid < target) left = mid+1;
        else right = mid-1;
    }
    printf("\n");
}
int main(void)
{
    int num;
    while (1)
    {
        scanf("%d", &num);

        if (num == 0)
            break;

        binarySearch(50, num);
    }
    return 0;
}