#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int testCase;

    scanf("%d", &testCase);

    for (int i = 0; i < testCase; i++)
    {
        char exp[12] = {0,};
        char* ptr;
        char temp[5] = {0,};
        int sum = 0;

        scanf("%s", exp);
        if (strcmp(exp, "P=NP") == 0) {
            printf("skipped\n");
            continue;
        }

        ptr = strtok(exp, "+");
        while (ptr != NULL) {
            strcpy(temp, ptr);
            sum += atoi(temp);
            ptr = strtok(NULL, "+");
            strcpy(temp, "");
        }

        printf("%d\n", sum);
    }
    return 0;
}