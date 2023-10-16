#include <stdio.h>
#include <stdbool.h>

void initArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }
}
bool isSameArray(int array1[], int array2[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (array1[i] != array2[i])
            return false;
    }
    return true;
}
void selectSort(int array[], int comp[], int len)
{
    int flag = 0;

    for (int i = len-1; i > 0; i--)
    {
        int max = i;

        if (isSameArray(array, comp, len)) {
            flag = 1;
        }

        for (int j = i; j >= 0; j--)
        {
            max = (array[j] > array[max]) ? j : max;
        }

        if (i != max) {
            int temp = array[max];
            array[max] = array[i];
            array[i] = temp;
        }
    }

    if (isSameArray(array, comp, len)) {
        flag = 1;
    }
    printf("%d\n", flag);
}

int main(void)
{
    int len;
    scanf("%d", &len);
    int array1[len] = {0,};
    int array2[len] = {0,};

    initArray(array1, len);
    initArray(array2, len);

    selectSort(array1, array2, len);
    return 0;
}