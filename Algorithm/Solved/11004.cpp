#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i = start-1;

    for (int j = start; j < end; j++)
    {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[end]);
    return i+1;
}
void quicksort(int array[], int start, int end)
{
    if (start < end) {
        int pivot = partition(array, start, end);

        quicksort(array, start, pivot-1);
        quicksort(array, pivot+1, end);
    }
}
void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
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

    //quicksort(array, 0, len-1);
    qsort(array, len, sizeof(int), compare);
    printf("%d\n", array[k-1]);

    return 0;
}