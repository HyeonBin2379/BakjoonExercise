#include <stdio.h>

int main(void)
{
    int scores[5] = {0, };
    int avg = 0;
    int mid;

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &scores[i]);
        avg += scores[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if (scores[i] < scores[j])
            {
                int temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    printf("%d\n%d", avg/5, scores[2]);
    return 0;
}