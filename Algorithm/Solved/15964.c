#include <stdio.h>

int main(void)
{
    int a;
    int b;
    long long res = 0;

    scanf("%d%d", &a, &b);
    res = (a+b)*(a-b);
    
    printf("%lld", res);
    return 0;
}