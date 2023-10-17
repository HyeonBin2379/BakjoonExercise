#include <stdio.h>

int len, k;
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
// 정렬된 상태의 배열을 병합
void merge(int array[], int temp[], int start, int mid, int end)
{
    int i = start, j = mid+1;
    int t_idx = start;

    // 중간지점 기준 왼쪽 인덱스값과 오른쪽 인덱스값 모두 채워야 하는 경우
    while (i <= mid && j <= end) {
        // 실질적인 정렬이 이루어지는 부분
        // 중간 지점 기준 왼쪽, 오른쪽 중 작은 값부터 임시 배열에 저장
        if (array[i] <= array[j]) {
            temp[t_idx++] = array[i++];
        }
        else {
            temp[t_idx++] = array[j++];
        }
    }
    // 임시배열에 채워야 할 값으로 왼쪽 인덱스값만 남은 경우
    while (i <= mid) {
        temp[t_idx++] = array[i++];
    }
    // 임시배열에 채워야 할 값으로 오른쪽 인덱스값만 남은 경우
    while (j <= end) {
        temp[t_idx++] = array[j++];
    }
    // 왼쪽, 오른쪽 부분 모두 채워넣음
    // 정렬된 임시배열의 값들을 다시 원래 배열에 저장
    for (int l = start; l <= end; l++) {
        count++;
        array[l] = temp[l];

        if (count == k) {
            value = array[l];
        }
    }
}
// 배열을 오름차순 정렬
void mergeSort(int array[], int temp[], int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;    // 중간 지점 구하기

        // 왼쪽 절반에 대해 재귀적인 분할-정복이 끝난 이후
        // 오른쪽 절반에 대해서도 재귀적인 분할-정복 실시
        mergeSort(array, temp, start, mid);     // 중간지점 기준 왼쪽 분할
        mergeSort(array, temp, mid+1, end);     // 중간지점 기준 오른쪽 분할
        merge(array, temp, start, mid, end);    // 분할된 배열 합병
    }
}

int main(void)
{
    scanf("%d%d", &len, &k);
    int array[len];
    int temp[len] = {0,};
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    mergeSort(array, temp, 0, len-1);

    if (count < k) {
        printf("%d\n", -1);
    }
    else {
        printf("%d\n", value);
    }
    return 0;
}