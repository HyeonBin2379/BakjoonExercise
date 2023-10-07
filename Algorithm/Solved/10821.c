#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101] = {0,};
    char* ptr;
    int count = 0;

    scanf("%s", str);
    
    ptr = strtok(str, ",");
    while (ptr != NULL)
    {
        count++;
        ptr = strtok(NULL, ",");
    }

    printf("%d", count);
    return 0;
}