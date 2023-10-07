#include <stdio.h>
#include <string.h>

int main(void)
{
    int count = 0;      // 반복 횟수 구하기
    int len = 0;
    int res = 0;

    while (1)
    {
        int ch = getchar();
        if (ch <'0' || ch > '9') break;
        res += (ch-'0');
        len++;
    }

    count = (len > 1) ? 1 : 0;
    while (res >= 10)
    {
        int temp = 0;
        while (res > 0) { 
            temp += res % 10;
            res /= 10;
        }
        res = temp;
        count++;
    }

    // 반복 횟수 출력
    printf("%d\n", count);
    // 구한 최종 num값이 3의 배수이면 YES, 아니면 NO 출력
    if (res % 3 == 0) printf("YES");
    else printf("NO");

    return 0;
}