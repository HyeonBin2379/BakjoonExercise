#include <stdio.h>

int main(void)
{
    int o, a, k;
    int res = 0;

    scanf("%d%d%d", &o, &a, &k);

    for (int i = 1; i < 150; i++)
    {
        for (int j = 1; j <= 150; j++)
        {
            if (o == i*a + j*k) {
                res = 1;
                break;
            }
        }
    }
    
    printf("%d", res);
    return 0;
}