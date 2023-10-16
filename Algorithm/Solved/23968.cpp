#include <stdio.h>
#include <stdlib.h>

int count = 0;
int answer[2] = {0, 0};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void bubbleSort(int array[], int len, int k)
{
    for (int i = len-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp;

                count++;

                swap(&array[j], &array[j+1]);

                if (count == k) {
                    answer[0] = array[j];
                    answer[1] = array[j+1];
                }
            }
        }
    }
}
int main(void)
{
    int len, k;
    scanf("%d%d", &len, &k);
    int array[len] = {0,};
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    bubbleSort(array, len, k);

    if (count >= k)
        printArray(answer, 2);
    else
        printf("%d\n", -1);
    return 0;
}