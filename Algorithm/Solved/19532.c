#include <stdio.h>

int main(void)
{
    int num[6] = {0,};

    for (int i = 0; i < 6; i++)
        scanf("%d", &num[i]);

    for (int i = -999; i <= 999; i++) {
        for (int j = -999; j <= 999; j++)
        {
            if (num[0]*i+num[1]*j == num[2] &&
                num[3]*i+num[4]*j == num[5]) {
                printf("%d %d", i, j);
                break;
            }
        }
    }
    return 0;
}