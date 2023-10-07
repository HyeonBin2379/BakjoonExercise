#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int num;
    char name[21];
} pokemon;

int compare(const void* a, const void* b)
{
    pokemon *first = (pokemon*)a;
    pokemon *second = (pokemon*)b;

    if (strcmp(first->name, second->name) > 0)
        return 1;
    else if (strcmp(first->name, second->name) < 0)
        return -1;
    else
        return 0;
}
int binarySearch(pokemon list[], int len, char* target)
{
    int left = 0;
    int right = len-1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (strcmp(list[mid].name, target) == 0)
            return list[mid].num;
        else if (strcmp(list[mid].name, target) < 0)
            left = mid+1;
        else
            right = mid-1;
    }
}
int main(void)
{
    int m, n;
    scanf("%d%d", &n, &m);
    pokemon list[n];
    pokemon sorted_list[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", list[i].name);
        list[i].num = i+1;
        sorted_list[i] = list[i];
    }

    qsort(sorted_list, n, sizeof(sorted_list[0]), compare);

    for (int i = 0; i < m; i++)
    {
        char question[21] = {0,};
        int idx;

        scanf("%s", question);
        if ((idx = atoi(question)) != 0)
        {
            printf("%s\n", list[idx-1].name);
        }
        else {
            idx = binarySearch(sorted_list, n, question);
            printf("%d\n", idx);
        }
    }

    return 0;
}