#include <stdio.h>
#include <stdlib.h>

long long len, totalCnt;
long long count = 0;
int first, second;

void printArray(int array[], long long len)
{
    for (int i = 1; i <= len; i++)
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
            first = (array[k] < array[least]) ? array[k] : array[least];
            second = (array[k] < array[least]) ? array[least] : array[k];
        }
        heapify(array, least, n);
    }
}
void buildMinHeap(int array[], long long n)
{
    for (long long i = n/2; i >= 1; i--) {
        heapify(array, i, n);
    }
}
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
            first = (array[1] < array[i]) ? array[1] : array[i];
            second = (array[1] < array[i]) ? array[i] : array[1];
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
        printf("%d %d\n", first, second);
    return 0;
}