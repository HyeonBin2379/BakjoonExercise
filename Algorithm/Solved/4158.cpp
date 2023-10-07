#include <stdio.h>

int binarySearch(long array[], int len, long target)
{
    int left = 0;
    int right = len-1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (array[mid] == target) return 0;
        else if (array[mid] < target) left = mid+1;
        else right = mid-1;
    }
    return -1;
}

int main(void)
{
    while (1) {
        int len1, len2;
        int res;

        scanf("%d%d", &len1, &len2);
        if (len1 == 0 && len2 == 0)
            break;
        
        // 첫번째 배열의 값 입력
        long arr1[len1] = {0,};
        for (int i = 0; i < len1; i++)
        {
            scanf("%ld", &arr1[i]);
        }

        // 두번째 배열의 값 입력
        long arr2[len2] = {0,};
        for (int i = 0; i < len2; i++)
        {
            scanf("%ld", &arr2[i]);
        }

        // 일치하는 값 찾기
        res = 0;
        for (int i = 0; i < len1; i++)
        {
            if (binarySearch(arr2, len2, arr1[i]) == 0)
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}