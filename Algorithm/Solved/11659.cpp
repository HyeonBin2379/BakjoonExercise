#include <stdio.h>

int main(void)
{
    int len, testCase;

    scanf("%d%d", &len, &testCase);
    int array[len+1];
    array[0] = 0;
    for (int i = 1; i < len+1; i++)
    {
        scanf("%d", &array[i]);
        array[i] += array[i-1];
    }

    for (int i = 0; i < testCase; i++)
    {
        int sum[len+1];
        int start, end;
        
        scanf("%d%d", &start, &end);
        printf("%d\n", array[end] - array[start-1]);
    }
    return 0;
}