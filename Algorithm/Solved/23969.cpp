#include <stdio.h>
#include <stdlib.h>

int count = 0;

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void copyArray(int array1[], int array2[], int len)
{
    for (int i = 0; i < len; i++)
        array1[i] = array2[i];
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int* bubbleSort(int array[], int len, int k)
{
    int* res = (int*)calloc(len, sizeof(int));

    for (int i = len-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j+1])
            {
                count++;

                swap(&array[j], &array[j+1]);

                if (count == k) {
                    copyArray(res, array, len);
                }
            }
        }
    }

    return res;
}
int main(void)
{
    int len, k;
    int* res;
    scanf("%d%d", &len, &k);
    int array[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    res = bubbleSort(array, len, k);

    if (count < k)
        printf("%d\n", -1);
    else
        printArray(res, len);

    return 0;
}