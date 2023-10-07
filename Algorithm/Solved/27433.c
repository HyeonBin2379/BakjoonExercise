#include <stdio.h>

long long factorial(int num)
{
    if(num <= 1)
        return 1;
    else
        return (long long)factorial(num-1)*num;
}
int main(void)
{
    int num;
    long long res;

    scanf("%d", &num);
    res = factorial(num);

    printf("%lld", res);
    return 0;
}