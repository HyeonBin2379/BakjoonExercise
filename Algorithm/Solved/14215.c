#include <stdio.h>

void bubbleSortDesc(int array[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
int main(void)
{
    int sticks[3] = {0, 0, 0};
    int total_len = 0;

    // 막대의 길이 입력 및 총합 구하기
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &sticks[i]);
        total_len += sticks[i];
    }

    while (1)
    {
        // 내림차순 정렬
        bubbleSortDesc(sticks, 3);
        
        // 삼각형 생성 가능 시 반복문 종료
        if (sticks[0] < sticks[1] + sticks[2])
            break;

        // 삼각형 생성 불가능 시 가장 긴 변 길이만 줄이기
        sticks[0]--;
        total_len--;
    }

    printf("%d", total_len);
    return 0;
}