#include <stdio.h>

long long len, target, k;
long long count = 0;
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
// 피벗 찾기: 퀵정렬과 코드 동일
int partition(int array[], long long start, long long end)
{
    int pivot = array[end];
    long long pos = start - 1;
    
    for (long long i = start; i < end; i++)
    {
        if (array[i] <= pivot) {
            count++;
            swap(&array[++pos], &array[i]);

            if (count == k) {
                first = array[pos];
                second = array[i];
            }
        }
    }
    if (pos+1 != end) {
        count++;
        swap(&array[pos+1], &array[end]);

        if (count == k) {
            first = array[pos+1];
            second = array[end];
        }
    }
    return pos+1;
}
int select(int array[], long long start, long long end, long long target)
{
    long long total;
    long long pivot;

    if (start == end)
        return array[start];
    
    // 분할
    total = partition(array, start, end);
    pivot = total - start + 1;  // 기준원소 = 전체에서 k번째로 작은 원소

    // 왼쪽 그룹으로 범위를 좁힘
    if (target < pivot)
        return select(array, start, total-1, target);
    // 기준 원소가 찾는 원소
    else if (target == pivot)
        return array[total];
    // 오른쪽 그룹으로 범위 좁힘
    else
        return select(array, total+1, end, target-pivot);
}
int main(void)
{
    scanf("%lld%lld%lld", &len, &target, &k);
    int array[len];

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    select(array, 0, len-1, target);

    if (count < k)
        printf("%d\n", -1);
    else
        printf("%d %d\n", first, second);
    return 0;
}