#include <stdio.h>

int input[7] = {0,};
int select[7] = {0,};
int check[7] = {0,};
int n, m;

int promising(int level)
{
    for (int i = 0; i < level; i++)
    {
        if (select[i] > select[i+1])
            return 0;
    }
    return 1;
}
void selectNum(int level)
{
    if (level == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", select[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        select[level] = input[i];
        selectNum(level+1);
        check[i] = 0;
    }
}

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (input[i] > input[j])
            {
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    selectNum(0);
    return 0;
}