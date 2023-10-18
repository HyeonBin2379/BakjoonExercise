#include <stdio.h>
#include <stdlib.h>

long long len, totalCnt;
long long count = 0;
int* answer;

void printArray(int array[], long long len)
{
    for (int i = 1; i <= len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int* copyArray(int array[], long long len)
{
    int* res = (int*)calloc(len+1, sizeof(int));
    for (int i = 1; i <= len; i++)
    {
        res[i] = array[i];
    }
    return res;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* 최소 힙 연산
   array[k]를 root로 삼는 트리가 최소 힙 성질을 충족하도록 수정
   array[k]의 두 자식을 root로 삼는 subtree는 최소 힙 성질 충족
   n은 배열 array의 전체 크기이자 최대 인덱스
*/
void heapify(int array[], long long k, long long n)
{
    long long left = 2*k;
    long long right = 2*k+1;
    long long least;

    if (right <= n) {
        least = (array[left] < array[right]) ? left : right;
    }
    else if (left <= n) {
        least = left;
    }
    else
        return;

    if (array[least] < array[k]) {
        count++;
        //printf("count: %d, ", count);
        //printArray(array, len);

        swap(&array[k], &array[least]);

        if (count == totalCnt) {
            answer = copyArray(array, len);
        }
        heapify(array, least, n);
    }
}
// 배열로부터 최소힙 생성
void buildMinHeap(int array[], long long n)
{
    for (long long i = n/2; i >= 1; i--) {
        heapify(array, i, n);
    }
}
// 힙정렬 함수
void heapSort(int array[], long long n)
{
    buildMinHeap(array, n);
    for (long long i = n; i > 1; i--)
    {
        count++;
        //printf("count: %d, ", count);
        //printArray(array, len);

        swap(&array[1], &array[i]);

        if (count == totalCnt) {
            answer = copyArray(array, len);
        }
        heapify(array, 1, i-1);
    }
}
int main(void)
{
    scanf("%lld%lld", &len, &totalCnt);
    int array[len+1];
    array[0] = 0;
    for (long long i = 1; i <= len; i++)
    {
        scanf("%d", &array[i]);
    }

    heapSort(array, len);

    if (count < totalCnt)
        printf("%d\n", -1);
    else
        printArray(answer, len);
    return 0;
}