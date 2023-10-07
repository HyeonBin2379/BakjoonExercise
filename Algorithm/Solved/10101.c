#include <stdio.h>

int main(void)
{
    int angle[3] = {0,};
    int sum = 0;

    // 각의 크기 입력 및 합 구하기
    for (int i = 0; i < 3; i++) {
        scanf("%d", &angle[i]);
        sum += angle[i];
    }

    // 각의 크기의 합이 180인지 확인
    if (sum != 180) {
        printf("Error\n");
        return 0;
    }

    // 정렬
    for (int i = 0; i < 2; i++)
    {
        for (int j = i+1; j < 3; j++)
        {
            if (angle[i] > angle[j]) {
                int temp = angle[i];
                angle[i] = angle[j];
                angle[j] = temp;
            }
        }
    }

    // 삼각형의 종류 식별
    // 세 각의 크기가 모두 동일
    if (angle[0] == angle[1] && angle[1] == angle[2])
    {
        printf("Equilateral\n");
        return 0;
    }

    // 세 각 중 두 각의 크기만 동일
    if ((angle[0] < angle[1] && angle[1] == angle[2])
        || (angle[0] == angle[1] && angle[1] < angle[2]))
    {
        printf("Isosceles\n");
        return 0;
    }
 
    // 세 각의 크기가 모두 다름
    if (angle[0] < angle[1] && angle[1] < angle[2])
    {
        printf("Scalene\n");
        return 0;
    }

    return 0;
}