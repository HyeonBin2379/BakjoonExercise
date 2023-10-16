#include <stdio.h>

int main(void)
{
    int size, cases;
    scanf("%d%d", &size, &cases);
    int table[size+1][size+1] = {0,};

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num;
            scanf("%d", &num);

            table[i+1][j+1] = table[i][j+1] + table[i+1][j] - table[i][j] + num;
        }
    }

    for (int i = 0; i < cases; i++)
    {
        int x1, y1;
        int x2, y2;
        int res;

        scanf("%d%d%d%d", &y1, &x1, &y2, &x2);

        res = table[y2][x2] - table[y1-1][x2] - table[y2][x1-1] + table[y1-1][x1-1];
        printf("%d\n", res);
    }

    return 0;
}