#include <stdio.h>

int isAllZero(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] != 0)
            return 0;
    }
    return 1;
}
void bubbleSort(int array[], int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(void)
{
    while (1)
    {
        int sides[3];

        scanf("%d%d%d", &sides[0], &sides[1], &sides[2]);

        if (isAllZero(sides, 3))
            break;

        bubbleSort(sides, 3);
        
        if (sides[0] >= sides[1] + sides[2]) {
            printf("Invalid\n");
            continue;
        }

        if (sides[0] == sides[1] && sides[1] == sides[2])
        {
            printf("Equilateral\n");
        }
        else if (sides[0] > sides[1] && sides[1] > sides[2])
        {
            printf("Scalene\n");
        }
        else {
            printf("Isosceles\n");
        }
    }
    return 0;
}