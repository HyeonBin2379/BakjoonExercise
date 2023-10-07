#include <stdio.h>

long GCD(long num1, long num2)
{
    long max, min;

    if (num1 > num2) {
        max = num1;
        min = num2;
    }
    else {
        max = num2;
        min = num1;
    }

    while (1)
    {
        int rmn = max % min;

        if (rmn == 0) return min;
        max = min;
        min = rmn;
    }
}
int main(void)
{
    long num[2][2];
    long son, mom, gcd;

    for (int i = 0; i < 2; i++)
        scanf("%ld%ld", &num[i][0], &num[i][1]);

    son = num[0][0]*num[1][1] + num[0][1]*num[1][0];
    mom = num[0][1]*num[1][1];
    gcd = GCD(son, mom);

    son /= gcd;
    mom /= gcd;
    printf("%ld %ld", son, mom);
    
    return 0;
}