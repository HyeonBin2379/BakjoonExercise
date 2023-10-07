#include <stdio.h>

int main(void)
{
    int num;
    int index;
    int measures[10001] = {0, };
    int mea_idx = 0;

    scanf("%d%d", &num, &index);

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            measures[mea_idx++] = i;
    }

    if (mea_idx < index)
        printf("%d", 0);
    else
        printf("%d", measures[index-1]);
    
    return 0;
}