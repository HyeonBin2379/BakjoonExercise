#include <stdio.h>
#include <stdlib.h>

int len, k;
int count = 0;
int* answer;

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int* copyArray(int array[], int len)
{
    int* res = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < len; i++)
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
int partition(int array[], int start, int end)
{
    int pivot = array[end];
    int pos = start - 1;

    for (int i = start; i < end; i++)
    {
        if (array[i] <= pivot) {
            count++;
            swap(&array[++pos], &array[i]);

            if (count == k) {
                answer = copyArray(array, len);
            }
        }
    }
    if (pos+1 != end) {
        count++;
        swap(&array[pos+1], &array[end]);

        if (count == k) {
            answer = copyArray(array, len);
        }
    }
    return pos+1;
}
void quickSort(int array[], int start, int end)
{
    if (start < end) 
    {
        int pivot = partition(array, start, end);
        quickSort(array, start, pivot-1);
        quickSort(array, pivot+1, end);
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
        printArray(answer, len);
    return 0;
}