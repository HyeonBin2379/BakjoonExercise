#include <stdio.h>
#include <stdbool.h>

int num[20] = {0,};
int n, s;
int count = 0;

// 부분수열의 합: 멱집합 알고리즘 응용
// 현재 정수를 더하느냐, 더하지 않느냐에 따라 재귀호출 양상이 달라짐
// 단, 집합이 아니기 때문에 더해지는 정수값은 중복될 수도 있다.
void getSubSumCount(int idx, int sub_sum)
{
    // 상태공간트리의 리프노드
    if (idx == n)
        return;

    // 현재 정수를 더한 합이 입력된 값과 같은지 검사
    sub_sum += num[idx];
    if (sub_sum == s)
        count++;

    // 현재 정수를 더한 합이 입력된 값과 다르면 재귀호출
    // 현재 정수를 더한 합이 s와 같아지는 부분수열의 개수 구하기
    getSubSumCount(idx+1, sub_sum);
    // 현재 정수를 더하지 않은 합이 s와 같아지는 부분수열의 개수 구하기
    getSubSumCount(idx+1, sub_sum - num[idx]);
}

int main(void)
{
    scanf("%d%d", &n,  &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &num[i]);

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (num[i] > num[j])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    getSubSumCount(0, 0);
    printf("%d", count);
    return 0;
}