#include <stdio.h>

#define MOD 1000000007

int main(void)
{
    long num;
    long fib1 = 0, fib2 = 0;
    long fib = 1;

    scanf("%ld", &num);

    for (int i = 1; i < num; i++)
    {
        // 재귀 시 결국 1씩 반환된 것을 더하는 것과 같음
        // 어차피 재귀하는 횟수가 계산 결과와 같으므로
        // 재귀를 이용하지 않고도 재귀와 같은 연산을 수행하는 방법을 구하는 것이 핵심
        fib2 = fib1;
        fib1 = fib;
        fib = (fib1 + fib2) % MOD;
    }
    
    printf("%ld %d\n", fib, (num-2) % MOD);
    return 0;
}