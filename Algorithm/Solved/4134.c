#include <stdio.h>

int isPrimeNum(long long num)
{
    if (num <= 1)
        return 0;
        
    for (long long i = 2; i*i < num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int testCase;

    scanf("%d", &testCase);

    for (int i = 0; i < testCase; i++)
    {
        long long num;

        scanf("%lld", &num);
        while (!isPrimeNum(num))
            num++;

        printf("%lld\n", num);
    }
    return 0;
}