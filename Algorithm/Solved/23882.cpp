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
int* selectsort(int array[], int len, int k)
{
    int *res = (int*)calloc(len, sizeof(int));

    for (int i = len-1; i > 0; i--)
    {
        int max = i;
        for (int j = i; j >= 0; j--) {
            max = (array[j] > array[max]) ? j : max;
        }

        if (max != i) {
            int temp = array[max];
            array[max] = array[i];
            array[i] = temp;
            count++;

            if (count == k) {
                copyArray(res, array, len);
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
    int array[len] = {0,};
    for (int i = 0; i < len; i++) {
        scanf("%d", &array[i]);
    }

    res = selectsort(array, len, k);

    if (count < k) {
        printf("%d\n", -1);
        return 0;
    }
    
    printArray(res, len);
    return 0;
}