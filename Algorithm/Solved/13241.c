#include <stdio.h>

long long gcd(long long a, long long b)
{
    while (b > 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int main(void)
{
    long long a;
    long long b;
    long long res;

    scanf("%lld%lld", &a, &b);

    res = a * b;
    res /= (a > b) ? gcd(a, b) : gcd(b, a);
    printf("%lld", res);

    return 0;
}