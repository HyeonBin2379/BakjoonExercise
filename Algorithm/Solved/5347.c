#include <stdio.h>

long long GCD(long long a, long long b)
{
    long long max, min;
    if (a > b) {
        max = a;
        min = b;
    }
    else {
        max = b;
        min = a;
    }

    while (min > 0) {
        long long r = max % min;
        max = min;
        min = r;
    }
    return max;
}
int main(void)
{
    int testCase;

    scanf("%d", &testCase);
    for (int i = 0; i < testCase; i++) 
    {
        long long num1, num2;
        long long gcd, lcm;

        scanf("%lld%lld", &num1, &num2);
        gcd = GCD(num1, num2);
        lcm = (num1*num2)/gcd;

        printf("%lld\n", lcm);
    }
    return 0;
}