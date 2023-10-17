#include <stdio.h>
#include <stdlib.h>

int count = 0;
int value;

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void insertSort(int array[], int len, int k)
{
    for (int i = 1; i < len; i++)
    {
        int loc = i-1;              // 현재 비교중인 칸, 삽입할 값의 직전 칸부터 시작
        int newItem = array[i];     // 삽입될 값

        // 삽입될 값을 넣을 위치를 탐색
        // 비교한 값이 새로 삽입할 값보다 크면 해당 값을 오른쪽으로 1칸 이동
        // 이 과정에 의해 삽입할 값의 왼쪽에는 삽입할 값보다 작은 값들만 남음
        while (0 <= loc && newItem < array[loc])
        {
            array[loc+1] = array[loc];
            loc--;

            count++;

            if (count == k) {
                value = array[loc+1];
            }
        }

        // 처음 위치와 다른 위치일 시 해당 위치에 삽입 
        if (loc+1 != i) {
            array[loc+1] = newItem;
            count++;

            if (count == k) {
                value = newItem;
            }
        }
    }
}

int main(void)
{
    int len, k;

    scanf("%d%d", &len, &k);
    int array[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    insertSort(array, len, k);
    
    if (count < k) {
        printf("%d\n", -1);
    }
    else {
        printf("%d\n", value);
    }
    return 0;
}