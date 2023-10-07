#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[501];
} String;

void initArray(String array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%s", array[i].str);
    }
}
int compare(const void* first, const void* second)
{
    String* a = (String*)first;
    String* b = (String*)second;

    if (strcmp(a->str, b->str) > 0)
        return 1;
    else if (strcmp(a->str, b->str) < 0)
        return -1;
    else
        return 0;
}
int binarySearch(String array[], int len, char* target)
{
    int left = 0;
    int right = len-1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (strcmp(array[mid].str, target) == 0)
            return 1;
        else if (strcmp(array[mid].str, target) > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}
int main(void)
{
    // 문자열의 개수 입력
    int m, n;
    scanf("%d%d", &n, &m);

    // 집합 s의 문자열과 검사해야 할 문자열 입력
    String set[n];
    String check_list[m];
    initArray(set, n);
    initArray(check_list, m);

    // 검색 대상인 문자열 중 집합의 원소에 포함된 것들의 개수 구하기
    int count = 0;
    qsort(set, n, sizeof(set[0]), compare);

    for (int i = 0; i < m; i++)
    {
        count += binarySearch(set, n, check_list[i].str);
    }

    printf("%d", count);

    return 0;
}