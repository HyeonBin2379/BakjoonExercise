#include <stdio.h>

int count = 0;
int first, second;

void printArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void selectsort(int array[], int len, int k)
{
    int max;

    for (int i = len-1; i > 0; i--)
    {
        max = i;

        for (int j = i; j >= 0; j--)
        {
            max = (array[j] > array[max]) ? j : max;
        }

        if (i != max) {
            int temp = array[max];
            array[max] = array[i];
            array[i] = temp;
            count++;
            //printf("count: %d, ", count);
            //printArray(array, len);

            if (count == k) {
                first = array[max];
                second = array[i];
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

    selectsort(array, len, k);

    if (count < k)
        printf("%d\n", -1);
    else
        printf("%d %d\n", first, second);
    return 0;
}