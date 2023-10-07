#include <stdio.h>

int main(void)
{
    int num[3] = {0,};

    for (int i = 0; i < 3; i++)
        scanf("%d", &num[i]);

    for (int i = 0; i < 2; i++)
    {
        for (int j = i+1; j < 3; j++)
        {
            if (num[i] > num[j]) {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    printf("%d", num[1]);
    return 0;
}