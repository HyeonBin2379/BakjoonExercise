#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int solved;
    int year;
    char firstName[6];
} Info;


int compare1(const void* a, const void* b)
{
    Info temp1 = *(Info*)a;
    Info temp2 = *(Info*)b;

    if (temp1.year < temp2.year)
        return -1;
    else if (temp1.year > temp2.year)
        return 1;
    else
        return 0;
}
int compare2(const void* a, const void* b)
{
    Info temp1 = *(Info*)a;
    Info temp2 = *(Info*)b;

    if (temp1.solved < temp2.solved)
        return 1;
    else if (temp1.solved > temp2.solved)
        return -1;
    else
        return 0;
}

int main(void)
{
    Info info[3];
    char teamName1[7] = {0,};
    char teamName2[4] = {0,};

    for (int i = 0; i < 3; i++)
    {
        scanf("%d%d%s", &(info[i].solved), &(info[i].year), info[i].firstName);
    }

    qsort(info, 3, sizeof(info[0]), compare1);
    for (int i = 0; i < 3; i++)
    {
        int val = info[i].year % 100;
        char temp[3] = {0,};

        sprintf(temp, "%d", val);
        strcat(teamName1, temp);
    }
    printf("%s\n", teamName1);

    qsort(info, 3, sizeof(info[0]), compare2);
    for (int i = 0; i < 3; i++)
    {
        teamName2[i] = info[i].firstName[0];
    }
    printf("%s", teamName2);
}