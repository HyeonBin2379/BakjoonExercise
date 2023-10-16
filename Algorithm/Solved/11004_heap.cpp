#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int len)
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
void max_heapify(int array[], int len, int i)
{
    int left = 2*i;
    int right = 2*i+1;
    int k = i;

    if (left < len && array[left] > array[k]) {
        k = left;
    }
    if (right < len && array[right] > array[k]) {
        k = right;
    }

    if (i != k) {
        swap(&array[k], &array[i]);
        max_heapify(array, len, k);
    }
}
void build_max_heap(int array[], int len)
{
    int i = len;
    for (int j = i/2; j >= 1; j--) {
        max_heapify(array, len, j);
    }
}
void heapSort(int array[], int len)
{
    build_max_heap(array, len);

    while (len > 1) {
        swap(&array[1], &array[len]);
        len--;
        max_heapify(array, len, 1);
    }
}

int main(void)
{
    int len, k;

    scanf("%d%d", &len, &k);
    int array[len+1] = {0,};
    for (int i = 1; i <= len; i++)
    {
        scanf("%d", &array[i]);
    }

    heapSort(array, len);
    printf("%d\n", array[k]);
    return 0;
}