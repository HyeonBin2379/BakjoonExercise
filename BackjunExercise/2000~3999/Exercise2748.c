#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long long fib[90] = {0, };
    int index;
    
    scanf("%d", &index);
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= index; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    printf("%lld\n", fib[index]);
    exit(0);
}
