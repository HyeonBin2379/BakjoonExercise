#include <stdio.h>

int len, k;
int count = 0;
int first, second;

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int array[], int start, int end)
{
    int pivot = array[end];     // 기준 원소, 배열의 마지막 값 사용
    int pos = start - 1;        // pivot보다 작은 마지막 값의 위치
                                // pivot보다 큰 첫번째 값의 위치를 찾는 용도

    // 배열의 마지막값 이외 원소들을 대상으로 반복
    for (int i = start; i < end; i++)
    {
        // 현재 값이 배열의 마지막 값보다 안 크면 왼쪽으로 이동
        if (array[i] <= pivot) 
        {
            count++;
            swap(&array[++pos], &array[i]);

            if (count == k) {
                first = array[pos];
                second = array[i];
            }
        }
    }

    // pivot보다 큰 첫번째 값의 위치가 배열 맨 끝이 아닌 경우
    // 즉, pivot이 배열의 최대값이 아니면 pivot을 해당 위치의 값과 맞바꿈
    if (pos+1 != end) {
        count++;
        swap(&array[pos+1], &array[end]);

        if (count == k) {
            first = array[pos+1];
            second = array[end];
        }
    }
    
    // pivot이 저장된 인덱스 반환
    return pos+1;
}
void quickSort(int array[], int start, int end)
{
    if (start < end)
    {
        /* 병합정렬: 분할된 배열을 다시 합병하는 과정에서 정렬 수행
           퀵정렬: 분할 지점을 찾는 과정에서 정렬 수행, 합병작업 없음 */
        int pivot = partition(array, start, end);   // 분할할 지점 찾기
        quickSort(array, start, pivot-1);           // 왼쪽 부분 정렬
        quickSort(array, pivot+1, end);             // 오른쪽 부분 정렬
    }
}
int main(void)
{
    scanf("%d%d", &len, &k);
    int array[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, len-1);

    if (count < k)
        printf("%d\n", -1);
    else
        printf("%d %d\n", first, second);
    return 0;
}