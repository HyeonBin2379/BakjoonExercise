#include <stdio.h>

int main(void)
{
    int count;
    int num = 2;
    int res;

    scanf("%d", &count);

    for (int i = 1; i <= count; i++)
    {
        res = num + num - 1;
        num = res;
    }
    
    printf("%d", res*res);
    return 0;
}