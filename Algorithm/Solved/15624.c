#include <stdio.h>

#define MOD 1000000007

int main(void)
{
    int fib[3] = {0,};
    int num;

    scanf("%d", &num);
    fib[1] = 1;
    fib[2] = 1;

    if (num == 0) {
        printf("%d\n", fib[0]);
        return 0;
    }

    for (int i = 1; i < num; i++)
    {
        fib[1] = fib[0];
        fib[0] = fib[2];
        fib[2] = (fib[1] + fib[0]) % MOD;
    }

    printf("%d\n", fib[2]);
    return 0;
}