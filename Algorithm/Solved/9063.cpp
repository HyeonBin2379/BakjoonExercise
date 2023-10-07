#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if (num1 < num2)
        return -1;
    else if (num1 > num2)
        return 1;
    else
        return 0;
}

int main(void)
{
    int count;
    int res;
    scanf("%d", &count);
    
    int pair[count][2] = {0,};
    int max_y = -10001;
    int min_y = 10001;
    for (int i = 0; i < count; i++)
    {
        scanf("%d%d", &pair[i][0], &pair[i][1]);
    }

    qsort(pair, count, sizeof(pair[0]), compare);
    res = pair[count-1][0] - pair[0][0];
    for (int i = 0; i < count; i++)
    {
        min_y = (pair[i][1] < min_y) ? pair[i][1] : min_y;
        max_y = (pair[i][1] > max_y) ? pair[i][1] : max_y;
    }
    res *= (max_y - min_y);

    printf("%d", res);
    return 0;
}