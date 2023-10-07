#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101] = {0,};
    int len;

    scanf("%s", str);
    len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    
    printf("%s", str);
    return 0;
}