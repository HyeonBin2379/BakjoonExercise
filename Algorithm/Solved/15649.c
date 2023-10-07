#include <stdio.h>

int select[8] = {0,};
int n, m;

int promising(int level)
{
    for (int i = 0; i < level; i++)
    {
        if (select[i] == select[level])
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
        select[level] = i+1;
        if (promising(level)) {
            selectNum(level+1);
        }
    }
}

int main(void)
{
    scanf("%d%d", &n, &m);
    selectNum(0);
    return 0;
}