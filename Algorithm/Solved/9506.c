#include <stdio.h>

int main(void)
{
    int num;

    while (1)
    {
        int measures[1000] = {0, };
        int mea_idx = 0;
        int sum = 0;

        scanf("%d", &num);

        if (num < 0)
            break;

        for (int i = 1; i < num; i++) {
            if (num % i == 0) {
                measures[mea_idx++] = i;
                sum += i;
            }
        }

        if (sum != num) {
            printf("%d is NOT perfect.\n", num);
            continue;
        }
        if (sum == num) {
            printf("%d = %d", num, measures[0]);
            for (int i = 1; i < mea_idx; i++)
                printf(" + %d", measures[i]);
            printf("\n");
            continue;
        }

    }
    return 0;
}