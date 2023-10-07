#include <stdio.h>

int select[8] = {0,};
int n, m;

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
        select[level] = i+1;
        selectNum(level+1);
    }
}

int main(void)
{
    scanf("%d%d", &n, &m);
    selectNum(0);
    return 0;
}