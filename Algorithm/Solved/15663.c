#include <stdio.h>

int input[8] = {0,};
int select[8] = {0,};
int check[8] = {0,};
int n, m;

int promising(int level)
{
    for (int i = 0; i < level; i++)
    {
        if (select[i] >= select[i+1])
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
        if (check[i] == 1)
            continue;

        // input의 이전 항목과 현재 항목의 숫자의 일치 여부 확인
        // input의 이전 항목의 숫자가 이전 단계에 사용되었는지도 확인
        if (i >= 1 && input[i-1] == input[i] && !check[i-1])
            continue;

        check[i] = 1;
        select[level] = input[i];
        selectNum(level+1);
        check[i] = 0;
    }
}

int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

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