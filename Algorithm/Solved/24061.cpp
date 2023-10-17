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
int* copyArray(int array1[], int len)
{
    int* array2 = (int*)calloc(len, sizeof(int));

    for (int i = 0; i < len; i++)
    {
        array2[i] = array1[i];
    }

    return array2;
}
void merge(int array[], int temp[], int start, int mid, int end)
{
    int i = start, j = mid+1;
    int t_idx = start;

    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j]) {
            temp[t_idx++] = array[i++];
        }
        else {
            temp[t_idx++] = array[j++];
        }
    }

    while (i <= mid) {
        temp[t_idx++] = array[i++];
    }
    while (j <= end) {
        temp[t_idx++] = array[j++];
    }
    for (int l = start; l <= end; l++) {
        count++;
        array[l] = temp[l];

        if (count == k) {
            answer = copyArray(array, len);
        }
    }
}
void mergeSort(int array[], int temp[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(array, temp, start, mid);
        mergeSort(array, temp, mid+1, end);
        merge(array, temp, start, mid, end);
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
        printArray(answer, len);
    }

    free(answer);
    return 0;
}