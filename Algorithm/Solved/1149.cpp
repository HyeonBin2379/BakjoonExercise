#include <stdio.h>

int arr[1001][3];
int ans[1001][3];
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int main(void)
{
    int num, result;
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 1; i <= num; i++)
    {
        ans[i][0] = (i == 1) ? arr[i][0] : min(ans[i-1][1], ans[i-1][2])+arr[i][0];
        ans[i][1] = (i == 1) ? arr[i][1] : min(ans[i-1][0], ans[i-1][2])+arr[i][1];
        ans[i][2] = (i == 1) ? arr[i][2] : min(ans[i-1][0], ans[i-1][1])+arr[i][2];
    }
    
    result = 1001*1001;
    for (int i = 0; i < 3; i++)
    {
        result = (result > ans[num][i]) ? ans[num][i] : result;
    }
    printf("%d\n", result);
    return 0;
}