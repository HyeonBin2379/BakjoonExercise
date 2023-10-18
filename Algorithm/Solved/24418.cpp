#include <stdio.h>

int size;
int dp[16][16] = {0,};
int count1 = 0;
int count2 = 0;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int matrixPathRec(int (*arr)[16], int i, int j)
{
    if (i == 0 || j == 0) {
        count1++;
        return 0;
    }
    else
        return (arr[i][j] + max(matrixPathRec(arr, i-1, j), matrixPathRec(arr, i, j-1)));
}
int matrixPath1(int (*arr)[16], int n)
{
    return matrixPathRec(arr, n, n);
}
int matrixPath2(int (*arr)[16], int n)
{
    for (int i = 0; i < n+1; i++)
        dp[i][0] = 0;
    for (int j = 1; j < n+1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            count2++;
            dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}
int main(void)
{
    scanf("%d", &size);
    int mat[16][16] = {0,};
    for (int i = 1; i < size+1; i++)
    {
        for (int j = 1; j < size+1; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    matrixPath1(mat, size);
    matrixPath2(mat, size);

    printf("%d %d\n", count1, count2);
    return 0;
}